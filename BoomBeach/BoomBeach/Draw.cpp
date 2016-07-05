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

void mouse(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{

	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		int x = e->X;
		int y = e->Y;

		std::cout << "X " << x << " Y " << y << std::endl;
		//int size = 800 / (base->getField()->getHeight());
		//int realx = x / size;
		//int realy = y / size;
		//std::cout << "X " << realx << " Y " << realy << std::endl;
		//
		//int tile = map[realx + realy *field->getWidth()];
		//std::cout << "tile " << tile << std::endl;
	}
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

	//Create Menu
	_buildingModels = base->getBuildingsPossibilies();


	/*int unitsMenu = glutCreateMenu(processUnitsMenu);
	glutAddMenuEntry("Brute", 0);
	glutAddMenuEntry("Kamikaze", 1);
	glutAddMenuEntry("Fusilleur", 2);
	glutAddMenuEntry("Sniper", 3);
	glutAddMenuEntry("Bazooka", 4);
	glutAddMenuEntry("Medecin contact", 5);
	glutAddMenuEntry("Medecin seringue", 6);
	glutAddMenuEntry("Medecin zone", 7);*/
}


void DrawRender()
{
	int tile;
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
			int size = 800 / (base->getField()->getHeight());
			int realx = x * size;
			int realy = y * size;

			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(float(realx), float(realy), 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(float(realx + size), float(realy), 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(float(realx + size), float(realy + size), 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(float(realx), float(realy + size), 0.0f);
			glEnd();
		}
	}
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
	base->addBuilding((_buildingModels[nbBuilding]->getName()).c_str());
	map = field->getData();
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