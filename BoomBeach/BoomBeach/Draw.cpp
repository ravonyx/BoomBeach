#include "Draw.h"
#include <iostream>
#include "glut.h"
#include "Tools.h"

GLuint textureImage[6];
std::vector <Building*> _buildingModels;
Base *base;
Army *army;
Field *field;
int *map;

int currentBuilding = -1;
int widthMap, heightMap;

typedef struct Square {
	float x;
	float y;
	float width;
	float height;
} Square_p;

Square_p currentSquare;
float squarex = 0;
float squarey = 0;

void mouse(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{

	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		float x = e->X;
		float y = e->Y;
		float sizeheight = heightMap / (base->getField()->getHeight());
		float sizewidth = widthMap / (base->getField()->getWidth());

		float realx = x / sizewidth;
		float realy = y / sizeheight;

		realx = roundf(realx);
		realy = roundf(realy);

		int tile = map[(int)realx + (int)realy *field->getWidth()];
		//if can construct on that tile
		if (tile == -1 && currentBuilding != -1)
		{
			if (base->addBuilding((_buildingModels[currentBuilding]->getName()).c_str(), realx, realy) == true)
			{
				map = field->getData();
				currentBuilding = -1;
			}
		}
	}
}

void mouseMotion(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{

		int x = e->X;
		int y = e->Y;

		float sizeheight = heightMap / (base->getField()->getHeight());
		float sizewidth = widthMap / (base->getField()->getWidth());

		float realx = x / sizewidth;
		float realy = y / sizeheight;

		realx = roundf(realx);
		realy = roundf(realy);
		
		int tile = map[(int)realx + (int)realy *field->getWidth()];

		squarex = realx;
		squarey = realy;
		currentSquare.width = sizewidth;
		currentSquare.height = sizeheight;

}

void Initialize()
{
	base = new Base();
	army = new Army();

	std::cout << *(base->getField());

	field = base->getField();
	map = field->getData();

	memset(textureImage, 0, sizeof(void *) * 1);

	textureImage[0] = createTexture("tile-green.png");
	textureImage[1] = createTexture("tile-sand.png");
	textureImage[2] = createTexture("tile-rock.png");
	textureImage[3] = createTexture("tile-tower.png");
	textureImage[4] = createTexture("tile-house.png");
	textureImage[5] = createTexture("tile-mortar.png");

	_buildingModels = base->getBuildingsPossibilies();
}


void DrawRender()
{
	int tile;
	glOrtho(0, widthMap, heightMap, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float sizewidth = widthMap / (base->getField()->getWidth() - 0.05f);
	float sizeheight = heightMap / (base->getField()->getHeight() - 0.05f);

	for (int y = 0; y < field->getHeight(); y++)
	{
		for (int x = 0; x < field->getWidth(); x++)
		{
			tile = map[x + y *field->getWidth()];

			glEnable(GL_TEXTURE_2D);
			if (tile == -1)
				glBindTexture(GL_TEXTURE_2D, textureImage[0]);
			else if (tile == -2)
				glBindTexture(GL_TEXTURE_2D, textureImage[1]);
			else if (tile == -3)
				glBindTexture(GL_TEXTURE_2D, textureImage[2]);
			else if (tile == 1)
				glBindTexture(GL_TEXTURE_2D, textureImage[3]);
			else if (tile == 2)
				glBindTexture(GL_TEXTURE_2D, textureImage[4]);
			else if (tile == 3)
				glBindTexture(GL_TEXTURE_2D, textureImage[5]);
			else
				glBindTexture(GL_TEXTURE_2D, 0);
			
			float realx = x * sizewidth;
			float realy = y * sizeheight;
			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(float(realx), float(realy), 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(float(realx + sizewidth), float(realy), 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(float(realx + sizewidth), float(realy + sizeheight), 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(float(realx), float(realy + sizeheight), 0.0f);
			glEnd();
		}
	}

	glBindTexture(GL_TEXTURE_2D, 0);

	//std::cout << currentSquare.x << " " << currentSquare.y << " " << currentSquare.width << " " << currentSquare.height << std::endl;
	//glColor3f(1.0f, 0.0f, 0.0f);
	glPointSize(20);
	currentSquare.x = squarex * sizewidth;
	currentSquare.y = squarey * sizeheight;
	glBegin(GL_LINE_LOOP);
	glVertex3f(float(currentSquare.x), float(currentSquare.y), 0.0f);
	glVertex3f(float(currentSquare.x + currentSquare.width), float(currentSquare.y), 0.0f);
	glVertex3f(float(currentSquare.x + currentSquare.width), float(currentSquare.y + currentSquare.height), 0.0f);
	glVertex3f(float(currentSquare.x), float(currentSquare.y + currentSquare.height), 0.0f);
	glEnd();
}

void SetDimensionMap(GLsizei width, GLsizei height)
{
	widthMap = width;
	heightMap = height;
}

void save_callback()
{
	base->saveBase();
	army->SaveArmy();
}

void load_callback()
{
	base->loadBase();
	army->LoadArmy();
}

void add_building(int nbBuilding)
{
	currentBuilding = nbBuilding;
}

void add_unit(int nbUnits)
{
	army->GetFactory().CreateUnit((unitType)nbUnits, army);
}

int get_army_money()
{
	return army->getMoney();
}

int get_base_money()
{
	return base->getMoney();
}