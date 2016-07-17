#version 150

#extension GL_ARB_explicit_attrib_location : enable

layout(location = 0) in vec4 a_position;
layout(location = 1) in vec3 a_normal;
layout(location = 2) in vec2 a_texcoords;

// decommenter afin d'utiliser la technique d'instancing via gl_InstanceID
//#define USE_UNIFORM_INSTANCING 1

#if USE_UNIFORM_INSTANCING
//uniform int u_index;
#define MAX_OBJECTS 100
uniform vec3 u_objectColors[MAX_OBJECTS];
uniform vec3 u_objectPositions[MAX_OBJECTS];
#else
layout(location = 3) in vec3 a_objectPosition;
layout(location = 4) in vec3 a_objectColor;
#endif

uniform	mat4 u_viewMatrix;
uniform mat4 u_projectionMatrix;
uniform mat4 u_worldMatrix;

out VertexDataIn {
    vec4 v_color;
    vec3 v_normal;
    vec2 v_texcoords;
} OUT;

// Vecteur vers le haut de l'hemisphere
const vec3 UP = vec3(0.0, 1.0, 0.0);
// Couleurs pour l'hemisphere Ambient Lighting
const vec4 Blue = vec4(0.0, 0.0, 1.0, 1.0);
const vec4 Green = vec4(0.0, 1.0, 0.0, 1.0);

uniform float u_time;

void main(void)
{
	mat4 modelMatrix = u_worldMatrix;
#ifdef USE_UNIFORM_INSTANCING
	int u_index = gl_InstanceID;	
	modelMatrix[3].xyz = u_objectPositions[u_index];
	//modelMatrix[3] = vec4(u_objectPositions[u_index], 1.0);
	vec4 objColor = vec4(u_objectColors[u_index], 1.0);
#else
	modelMatrix[3].xyz = a_objectPosition;
	vec4 objColor = vec4(a_objectColor, 1.0);
#endif
	vec4 worldPosition = modelMatrix * a_position;
	
	vec3 N = mat3(u_worldMatrix) * a_normal;
	OUT.v_normal = N;

	//float NdotL = max(dot(L, N), 0.0);
	//worldPosition.xyz += OUT.v_normal * NdotL * abs(cos(u_time));

	float ambientFactor = (dot(N, UP) + 1.0) / 2.0;
	OUT.v_color = objColor * mix(Green, Blue, ambientFactor);

	OUT.v_texcoords = a_texcoords;
	gl_Position = u_projectionMatrix * u_viewMatrix * worldPosition;

}