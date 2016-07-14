#include "Draw.h"
#include <iostream>
#include "glut.h"
#include "Tools.h"

GLuint textureImage[10];
std::vector <Building*> _buildingModels;
std::vector <Unit*> _unitModels;
Base *base;
Army *army;
Field *field;
int *map;

int currentBuilding = -1;
int currentUnit = -1;
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
		else {
			//if can drop unit on that tile
			if (tile == -2 && currentUnit != -1)
			{
				std::cout << "ok" << std::endl;
				/*if (base->addBuilding((_buildingModels[currentUnit]->getName()).c_str(), realx, realy) == true)
				{
					map = field->getData();
					currentUnit = -1;
				}*/
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
		
	squarex = realx;
	squarey = realy;
}

void Initialize()
{
	base = new Base();
	army = new Army();

	//std::cout << *(base->getField());

	field = base->getField();
	map = field->getData();

	memset(textureImage, 0, sizeof(void *) * 1);

	textureImage[0] = createTexture("tile-green.png");
	textureImage[1] = createTexture("tile-sand.png");
	textureImage[2] = createTexture("tile-rock.png");

	textureImage[3] = createTexture("tile-house.png");

	textureImage[4] = createTexture("tile-sniper.png");
	textureImage[5] = createTexture("tile-lanceflamme.png");
	textureImage[6] = createTexture("tile-mitrailleuse.png");

	textureImage[7] = createTexture("tile-repare.png");
	textureImage[8] = createTexture("tile-shield.png");
	textureImage[9] = createTexture("tile-energy.png");

	_buildingModels = base->getBuildingsPossibilities();
	_unitModels = army->getUnitsPossibilities();
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
			else if (tile == 4)
				glBindTexture(GL_TEXTURE_2D, textureImage[6]);
			else if (tile == 5)
				glBindTexture(GL_TEXTURE_2D, textureImage[7]);
			else if (tile == 6)
				glBindTexture(GL_TEXTURE_2D, textureImage[8]);
			else if (tile == 7)
				glBindTexture(GL_TEXTURE_2D, textureImage[9]);
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

	currentSquare.x = squarex * sizewidth;
	currentSquare.y = squarey * sizeheight;

	if (currentBuilding != -1)
	{
		float sizeheight = heightMap / (base->getField()->getHeight());
		float sizewidth = widthMap / (base->getField()->getWidth());

		currentSquare.width = sizewidth;
		currentSquare.height = sizeheight;

		currentSquare.width *= _buildingModels[currentBuilding]->getWidth();
		currentSquare.height *= _buildingModels[currentBuilding]->getHeight();
	}

	else
	{
		float sizeheight = heightMap / (base->getField()->getHeight());
		float sizewidth = widthMap / (base->getField()->getWidth());

		currentSquare.width = sizewidth;
		currentSquare.height = sizeheight;
	}

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
	army->saveArmy();
}

void load_callback()
{
	base->loadBase();
	army->loadArmy();
}

void add_building(int nbBuilding)
{
	currentBuilding = nbBuilding;
}

void drop_unit(int nbUnit)
{
	currentUnit = nbUnit;
}

void add_unit(int nbUnits)
{
	army->addUnit((_unitModels[nbUnits]->getName()).c_str());
}

int get_army_money()
{
	return army->getMoney();
}

int get_base_money()
{
	return base->getMoney();
}

int get_building_max(int nbBuilding)
{
	return _buildingModels[nbBuilding]->getMaxInstances();
}
int get_building_instances(int nbBuilding)
{
	return base->getBuildingFactory()->getInstances(_buildingModels[nbBuilding]->getName());
}
int get_unit_max(int nbUnits)
{
	return _unitModels[nbUnits]->getMaxInstances();
}
int get_unit_instances(int nbUnits)
{
	return army->getUnitFactory()->getInstances(_unitModels[nbUnits]->getName());
}

std::vector<Building*> get_buildings()
{
	return base->getCurrentBuildings();
}
std::vector<Unit*> get_units()
{
	return army->getCurrentUnits();
}

void enhance_building(int index)
{
	base->enhanceBuilding(index);
}
void delete_building(int index)
{
	base->destroyBuilding(index);
}
void enhance_unit(int index)
{
	army->enhanceUnit(index);
}
void delete_unit(int index)
{
	army->deleteUnit(index);
}