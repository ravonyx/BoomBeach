//
// ESGI
// MultipleObjects.cpp 
//

#include <cstdio>
#include <cmath>

#include <vector>
#include <string>

#ifdef _WIN32
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "freeglut.lib")
#ifdef GLEW_STATIC
#pragma comment(lib, "glew32s.lib")
#else
#pragma comment(lib, "glew32.lib")
#endif
#include <Windows.h>

#define FREEGLUT_LIB_PRAGMAS 0
#endif

#include <cstdio>
#include <cmath>
#include <cstdint>

#include "GL/glew.h"
#include "GL/freeglut.h"

#include "../common/EsgiShader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#include "tinyobjloader/tiny_obj_loader.h"

// ---

#include <vector>
#include <iostream>
#include <fstream>

struct vec3
{
	vec3() {}
	vec3(float f) : x(f), y(f), z(f) {}
	vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	vec3(const vec3& v) : x(v.x), y(v.y), z(v.z) {}

	float x, y, z;
};

struct mat4
{
	mat4() {}
	mat4(float f) { makeScale(f); }
	mat4(const mat4& _m) { memcpy(m, &_m, sizeof(float) * 16); }

	void identity() { makeScale(1.0f); }

	inline void makeScale(float f) {
		memset(m, 0, sizeof(float)*16);
		m[0] = f; m[5] = f; m[10] = f; m[15] = 1.0f;
	};

	inline void setPosition(const vec3& v) { m[12] = v.x; m[13] = v.y; m[14] = v.z; }

	float m[16];
};


#ifndef M_PI
#define M_PI 3.141592f
#endif


static inline float radians(float deg) {
	return deg * M_PI / 180.0f;
}

static inline float degrees(float rad) {
	return rad * 180.0f / M_PI;
}

mat4 perspectiveFov(float fov, float width, float height, float znear, float zfar)
{
	mat4 mat(0.0f);

	float aspect = width / height;

	float xymax = znear * tan(fov * 0.5f * M_PI/180.0f);

	float ymin = -xymax;
	float xmin = -xymax;
 
	float near_width = xymax - xmin;
	float near_height = xymax - ymin;
 
	float depth = zfar - znear;
	float q = -(zfar + znear) / depth;
	float qn = -2 * (zfar * znear) / depth;
 
	float w = 2 * znear / near_width;
	w = w / aspect;
	float h = 2 * znear / near_height;
 
	// ne pas oublier il s'agit de colonnes !
	mat.m[0]  = w; mat.m[1]  = 0.0f; mat.m[2]  = 0.0f; mat.m[3]  = 0.0f;
	mat.m[4]  = 0.0f; mat.m[5]  = h; mat.m[6]  = 0.0f; mat.m[7]  = 0.0f;
	mat.m[8]  = 0.0f; mat.m[9]  = 0.0f; mat.m[10] = q; mat.m[11] = -1.0f;
	mat.m[12] = 0.0f; mat.m[13] = 0.0f; mat.m[14] = qn; mat.m[15] = 0.0f;

	return mat;
}

mat4 lookAt(const vec3& eye, const vec3& target, const vec3& up)
{
	mat4 mat(1.0f);

	// TODO: une vraie lookAt matrix (cf TD au format doc)

	mat.m[12] = -eye.x; mat.m[13] = -eye.y; mat.m[14] = -eye.z;

	return mat;
}

// ---

bool LoadAndCreateTexture(const char* nom, GLuint& textureObj)
{
	int w, h, comp;
	int req_comp = 4;
	auto* image = stbi_load(nom, &w, &h, &comp, req_comp);
	if (image)
	{
		glGenTextures(1, &textureObj);
		glBindTexture(GL_TEXTURE_2D, textureObj);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		stbi_image_free(image);
		glBindTexture(GL_TEXTURE_2D, 0);

		return true;
	}

	return false;
}

void DestroyTexture(GLuint textureObj)
{
	glDeleteTextures(1, &textureObj);
}

// ---

EsgiShader g_BasicShader;

int previousTime = 0;

struct ViewProj
{
	mat4 viewMatrix;
	mat4 projectionMatrix;
	vec3 rotation;	
} g_Camera;

struct Objet
{
	// transform
	vec3 position;
	vec3 rotation;
	mat4 worldMatrix;	
	// mesh
	GLuint VBO;
	GLuint IBO;
	GLuint ElementCount;
	GLenum PrimitiveType;
	GLuint VAO;
	// material
	GLuint textureObj;
};

Objet g_Objet;
Objet g_CubeMap;

// decommenter afin d'utiliser la technique d'instancing via gl_InstanceID
//#define USE_UNIFORM_INSTANCING 1
//static const int MAX_OBJECTS = 100;
//vec3 objectPositions[MAX_OBJECTS];
//vec3 objectColors[MAX_OBJECTS];
std::vector<vec3>& objectPositions = std::vector<vec3>();
std::vector<vec3>& objectColors = std::vector<vec3>();
GLuint objPositionsVBO;
GLuint objColorsVBO;
// ---

void LoadOBJ(const std::string &inputFile)
{	
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;

	std::string err = tinyobj::LoadObj(shapes, materials, inputFile.c_str());
	const std::vector<unsigned int>& indices = shapes[0].mesh.indices;
	const std::vector<float>& positions = shapes[0].mesh.positions;
	const std::vector<float>& normals = shapes[0].mesh.normals;
	const std::vector<float>& texcoords = shapes[0].mesh.texcoords;

	g_Objet.ElementCount = indices.size();
	
	uint32_t stride = 0;

	if (positions.size()) {
		stride += 3 * sizeof(float);
	}
	if (normals.size()) {
		stride += 3 * sizeof(float);
	}
	if (texcoords.size()) {
		stride += 2 * sizeof(float);
	}

	const auto count = positions.size() / 3;
	const auto totalSize = count * stride;
	
	glGenBuffers(1, &g_Objet.IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_Objet.IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), &indices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &g_Objet.VBO);
	glBindBuffer(GL_ARRAY_BUFFER, g_Objet.VBO);
	glBufferData(GL_ARRAY_BUFFER, totalSize, nullptr, GL_STATIC_DRAW);

	// glMapBuffer retourne un pointeur sur la zone memoire allouee par glBufferData 
	// du Buffer Object qui est actuellement actif - via glBindBuffer(<cible>, <id>)
	// il est imperatif d'appeler glUnmapBuffer() une fois que l'on a termine car le
	// driver peut tres bien etre amener a modifier l'emplacement memoire du BO.
	float* vertices = (float*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);		
	for (auto index = 0; index < count; ++index)
	{
		if (positions.size()) {
			memcpy(vertices, &positions[index * 3], 3 * sizeof(float));
			vertices += 3;
		}
		if (normals.size()) {
			memcpy(vertices, &normals[index * 3], 3 * sizeof(float));
			vertices += 3;
		}
		if (texcoords.size()) {
			memcpy(vertices, &texcoords[index * 2], 2 * sizeof(float));
			vertices += 2;
		}
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);

	glGenVertexArrays(1, &g_Objet.VAO);
	glBindVertexArray(g_Objet.VAO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_Objet.IBO);

	glBindBuffer(GL_ARRAY_BUFFER, g_Objet.VBO);
	uint32_t offset = 3 * sizeof(float);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, stride, nullptr);
	glEnableVertexAttribArray(0);
	if (normals.size()) {		
		glVertexAttribPointer(1, 3, GL_FLOAT, false, stride, (GLvoid *)offset);
		glEnableVertexAttribArray(1);
		offset += 3 * sizeof(float);
	}
	if (texcoords.size()) {
		glVertexAttribPointer(2, 2, GL_FLOAT, false, stride, (GLvoid *)offset);
		glEnableVertexAttribArray(2);
		offset += 2 * sizeof(float);
	}

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);	

	LoadAndCreateTexture(materials[0].diffuse_texname.c_str(), g_Objet.textureObj);
}

void CleanObjet(Objet& objet)
{
	if (objet.textureObj)
		glDeleteTextures(1, &objet.textureObj);
	if (objet.VAO)
		glDeleteVertexArrays(1, &objet.VAO);
	if (objet.VBO)
		glDeleteBuffers(1, &objet.VBO);
	if (objet.IBO)
		glDeleteBuffers(1, &objet.IBO);
}

// Initialisation et terminaison ---

static const float randomFloat(float min, float max)
{
	float normalized = (float)rand() / (float)RAND_MAX;
	return min + normalized * (max - min);
}

void loadBase();

vec3 startPos = vec3(-20, -10, 0);
vec3 currentPos = startPos;

std::vector<int> _buildings;
int _money;

int MAX_OBJECTS = 0;


struct Field {
	std::vector<int> _data;
	int _width;
	int _height;
};

Field* _field;

std::istream& operator >> (std::istream& is, Field& f)
{
	is >> f._width;
	is >> f._height;

	const int size = f._width * f._height;
	MAX_OBJECTS = f._width * f._height;
	objectPositions.resize(MAX_OBJECTS);
	objectColors.resize(MAX_OBJECTS);
	int data;
	int index = 0;
	while (is.good())
	{
		is >> data;
		if (index < size)
		{
			f._data.push_back(data);
			index++;
		}
	}
	return is;
}

int ReadNextBuilding(std::istream &stream)
{
	int id = 0, level = 0, x = 0, y = 0, type = 0;
	std::string name;

	stream >> id;
	stream >> name;
	stream >> type;
	stream >> level;
	stream >> x;
	stream >> y;

	return 0;
}

void loadBase()
{
	_buildings.clear();
	_field = new Field();
	_field->_data.clear();
	int nbBuildings = 0;
	std::ifstream myfile("base.txt", std::ios::in);
	if (myfile.is_open())
	{
		myfile >> _money;
		std::string junk;
		myfile >> junk;
		myfile >> nbBuildings;
		for (int i = 0; i < nbBuildings; i++)
		{
			_buildings.push_back(ReadNextBuilding(myfile));
		}
		myfile >> *_field;
	}
	myfile.close();
}

void Initialize()
{
	printf("Version Pilote OpenGL : %s\n", glGetString(GL_VERSION));
	printf("Type de GPU : %s\n", glGetString(GL_RENDERER));
	printf("Fabricant : %s\n", glGetString(GL_VENDOR));
	printf("Version GLSL : %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int numExtensions;
	glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);
	
	GLenum error = glewInit();
	if (error != GL_NO_ERROR) {
		// TODO
	}

	loadBase();

#if LIST_EXTENSIONS
	for (int index = 0; index < numExtensions; ++index)
	{
		printf("Extension[%d] : %s\n", index, glGetStringi(GL_EXTENSIONS, index));
	}
#endif
	
#ifdef _WIN32
	// on coupe la synchro vertical pour voir l'effet du delta time
	//wglSwapIntervalEXT(0);
#endif

	// render states par defaut
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);	

	// Objets OpenGL

	g_BasicShader.LoadVertexShader("basic.vs");
	g_BasicShader.LoadFragmentShader("basic.fs");
	//g_BasicShader.LoadGeometryShader("basic.gs");
	g_BasicShader.Create();


	auto program = g_BasicShader.GetProgram();

	// Setup

	previousTime = glutGet(GLUT_ELAPSED_TIME);

	const std::string inputFile = "rock.obj";
	LoadOBJ(inputFile);

	// initialisation des tableaux random
	//MAX_OBJECTS

	int x = 0, y = 0;
	for (auto index = 0; index < _field->_height * _field->_width; ++index)
	{
		//objectPositions[index] = vec3(randomFloat(-10.0f, 10.0f), randomFloat(-10.0f, 10.0f), randomFloat(-10.0f, 10.0f));
		objectPositions[index] = currentPos;
		currentPos.x += 2;
		x++;
		if (x >= _field->_width) {
			x = 0;
			y++;
			currentPos.x = startPos.x;
			currentPos.y += 1;
			currentPos.z -= 1.2;
		}
		//objectColors[index] = vec3(randomFloat(0.0f, 1.0f), randomFloat(0.0f, 1.0f), randomFloat(0.0f, 1.0f));
		objectColors[index] = vec3(1-_field->_data[index]*2/10.0*-1.0, 1-_field->_data[index]*2 / 10.0 * -1.0, 1-_field->_data[index]*2 / 10.0 * -1.0);
	}

#ifndef USE_UNIFORM_INSTANCING
	glBindVertexArray(g_Objet.VAO);
	// a. les 3 lignes ci apres ne sont pas prises en compte par le VAO
	glGenBuffers(1, &objPositionsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, objPositionsVBO);
	glBufferData(GL_ARRAY_BUFFER, MAX_OBJECTS * sizeof(vec3), &objectPositions[0], GL_STREAM_DRAW);
	// b. mais les 3 lignes suivantes SI !
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), nullptr);
	glVertexAttribDivisor(3, 1);
	glEnableVertexAttribArray(3);
	// idem a
	glGenBuffers(1, &objColorsVBO);
	glBindBuffer(GL_ARRAY_BUFFER, objColorsVBO);
	glBufferData(GL_ARRAY_BUFFER, MAX_OBJECTS * sizeof(vec3), &objectColors[0], GL_STREAM_DRAW);
	// idem b
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), nullptr);
	glVertexAttribDivisor(4, 1);
	glEnableVertexAttribArray(4);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
#endif
}

void Terminate()
{	
	glDeleteBuffers(1, &objPositionsVBO);
	glDeleteBuffers(1, &objColorsVBO);

	CleanObjet(g_Objet);

	g_BasicShader.Destroy();
}

// boucle principale ---

void Resize(GLint width, GLint height) 
{
	glViewport(0, 0, width, height);
	
	g_Camera.projectionMatrix = perspectiveFov(45.f, (float)width, (float)height, 0.1f, 1000.f);
}

static float time = 0.0f;

void Update() 
{
	auto currentTime = glutGet(GLUT_ELAPSED_TIME);
	auto delta = currentTime - previousTime;
	previousTime = currentTime;
	auto elapsedTime = delta / 1000.0f;
	time += elapsedTime;
	//g_Objet.rotation += vec3(36.0f * elapsedTime);
	//g_Camera.rotation.y += 10.f * elapsedTime;

	glutPostRedisplay();
}

void Render()
{
	auto width = glutGet(GLUT_WINDOW_WIDTH);
	auto height = glutGet(GLUT_WINDOW_HEIGHT);

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// variables uniformes (constantes) 

	g_Camera.projectionMatrix = perspectiveFov(45.f, (float)width, (float)height, 0.1f, 1000.f);
	
	vec3 camera_position(0.0f, 0.0f, 40.0f);
	g_Camera.viewMatrix = lookAt(vec3(camera_position), vec3(0.f), vec3(0.f, 1.f, 0.f));

	g_Objet.worldMatrix.identity();

	// rendu	

	auto program = g_BasicShader.GetProgram();
	glUseProgram(program);
	
	GLint timeLocation = glGetUniformLocation(program, "u_time");
	glUniform1f(timeLocation, time);

	auto projectionLocation = glGetUniformLocation(program, "u_projectionMatrix");
	auto viewLocation = glGetUniformLocation(program, "u_viewMatrix");
	auto worldLocation = glGetUniformLocation(program, "u_worldMatrix");
	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, g_Camera.projectionMatrix.m);
	glUniformMatrix4fv(viewLocation, 1, GL_FALSE, g_Camera.viewMatrix.m);
	

	glBindTexture(GL_TEXTURE_2D, g_Objet.textureObj);

	glUniformMatrix4fv(worldLocation, 1, GL_FALSE, g_Objet.worldMatrix.m);
#if USE_UNIFORM_INSTANCING
	GLint colorsLocation = glGetUniformLocation(program, "u_objectColors");
	glUniform3fv(colorsLocation, MAX_OBJECTS, &objectColors[0].x);
	GLint positionsLocation = glGetUniformLocation(program, "u_objectPositions");
	glUniform3fv(positionsLocation, MAX_OBJECTS, &objectPositions[0].x);
#endif

	glBindVertexArray(g_Objet.VAO);	

	glDrawElementsInstanced(GL_TRIANGLES, g_Objet.ElementCount, GL_UNSIGNED_INT, 0, MAX_OBJECTS);

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Multiple Objects with Instancing");

#ifdef FREEGLUT
	// Note: glutSetOption n'est disponible qu'avec freeGLUT
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
				  GLUT_ACTION_GLUTMAINLOOP_RETURNS);
#endif

	Initialize();

	glutReshapeFunc(Resize);
	glutIdleFunc(Update);
	glutDisplayFunc(Render);

	glutMainLoop();

	Terminate();

	return 0;
}