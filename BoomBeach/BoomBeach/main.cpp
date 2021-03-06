#include "GL/glew.h"
#include "Building.h"
#include "Base.h"
#include <iostream>
#include "glut.h"
#include "Tools.h"
#define NOMINMAX
#define WIN32

void launchConsole();
void launchOpengl();
void reshapeWindow(int w, int h);
void renderScene(void);
void menu(int item);
void processConstructionMenu(int option);
void processUnitsMenu(int option);

void mouse(int button, int state, int x, int y);


//std::vector <Building*> _buildingModels;
//Base *base;
//Army *army;
//GLuint textureImage[6];
//Field *field;
//int *map;


#include "UIForm.h"
using namespace UIBoomBeach;

[STAThreadAttribute]
int main(int argc, char *argv[])
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	glutInit(&argc, argv);
	Application::Run(gcnew UIForm());
	return 0;
}


/*int main(int argc, char *argv[])
{
	std::cout << "Hi !" << std::endl;
	std::cout << "Welcome in Ravonyxland" << std::endl << std::endl;
	std::cout << "Initialization" << std::endl;
	std::cout << "/////////////////////////////////" << std::endl << std::endl;
	std::cout << "(0) Console or (1) Opengl " << std::endl << std::endl;

	int input;
	std::cin >> input;
	if (input == 0)
	{
		base = new Base();
		army = new Army();
		launchConsole();

	}
	else if (input == 1)
	{
		base = new Base();
		army = new Army();

		std::cout << *(base->getField());

		field = base->getField();
		map = field->getData();

		memset(textureImage, 0, sizeof(void *) * 1);

		glutInit(&argc, argv);
		launchOpengl();
	}
	return 1;
}*/

/*void launchOpengl()
{
	/** CREATION FENETRE **/
	/*glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Boom Beach");*/

	/** FONCTIONS GLUT **/
	/*glutDisplayFunc(renderScene);
	glutReshapeFunc(reshapeWindow);
	glutIdleFunc(renderScene);
	glutMouseFunc(mouse);

	Fl_Window window(200, 120, "Paramètres");
	save = new Fl_Button(20, 10, 100, 50, "Save");
	save->callback(save_callback);
	load = new Fl_Button(20, 60, 100, 50, "Load");
	load->callback(load_callback);
	window.end();
	window.show();

	textureImage[0] = createTexture("tile-green.png");
	textureImage[1] = createTexture("tile-sand.png");
	textureImage[2] = createTexture("tile-rock.png");
	textureImage[3] = createTexture("tile-tower.png");
	textureImage[4] = createTexture("tile-house.png");
	textureImage[5] = createTexture("tile-mortar.png");

	//Create Menu
	int constructionMenu = glutCreateMenu(processConstructionMenu);

	_buildingModels = base->getBuildingsPossibilies();

	for (int i = 0; i < _buildingModels.size(); i++)
	{
		glutAddMenuEntry((_buildingModels[i]->getName()).c_str(), i);
	}
	
	int unitsMenu = glutCreateMenu(processUnitsMenu);
	glutAddMenuEntry("Brute", 0);
	glutAddMenuEntry("Kamikaze", 1);
	glutAddMenuEntry("Fusilleur", 2);
	glutAddMenuEntry("Sniper", 3);
	glutAddMenuEntry("Bazooka", 4);
	glutAddMenuEntry("Medecin contact", 5);
	glutAddMenuEntry("Medecin seringue", 6);
	glutAddMenuEntry("Medecin zone", 7);

	glutCreateMenu(menu);
	glutAddSubMenu("Construct", constructionMenu);
	glutAddSubMenu("Units", unitsMenu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}*/

/*void renderScene(void)
{
	//Clear screen
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	//Set view and zoom
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 800, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	int tile;
	for (int y = 0; y < field->getHeight(); y++)
	{
		for (int x = 0; x < field->getWidth(); x++)
		{
			tile = map[x + y *field->getWidth()];

			glEnable(GL_TEXTURE_2D);
			if (tile == -1)
				glBindTexture(GL_TEXTURE_2D, textureImage[0]);
			else if(tile == -2)
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

	glutSwapBuffers();
}*/

/*void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		std::cout << "X " << x << " Y " << y << std::endl;
		int size = 800 / (base->getField()->getHeight());
		int realx = x / size;
		int realy = y / size;
		std::cout << "X " << realx << " Y " << realy << std::endl;

		int tile = map[realx + realy *field->getWidth()];
		std::cout << "tile " << tile << std::endl;
	}

	glutPostRedisplay();
}*/

/** GESTION FENETRE **/
void reshapeWindow(int w, int h)
{
	if (h == 0)
		h = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);
	glMatrixMode(GL_MODELVIEW);
}

// Menu handling function definition
/*void menu(int item)
{
	switch (item)
	{
		default:
		{
			break;
		}
	}
	glutPostRedisplay();
}

void processConstructionMenu(int option)
{
	switch (option)
	{
		case 0:
			base->addBuilding((_buildingModels[0]->getName()).c_str());
			map = field->getData();
			 break;
		case 1:
			base->addBuilding((_buildingModels[1]->getName()).c_str());
			map = field->getData();
			break;
		case 2:
			base->addBuilding((_buildingModels[2]->getName()).c_str());
			map = field->getData();
			break;
		case 3:
			base->addBuilding((_buildingModels[3]->getName()).c_str());
			map = field->getData();
			break;
		case 4:
			base->addBuilding((_buildingModels[4]->getName()).c_str());
			map = field->getData();
			break;
		case 5:
			base->addBuilding((_buildingModels[5]->getName()).c_str());
			map = field->getData();
			break;
		case 6:
			base->addBuilding((_buildingModels[6]->getName()).c_str());
			map = field->getData();
			break;
		default:
			break;
	}
}

*/
/*
void launchConsole()
{
	int exitCode = 0;
	while (exitCode != 1)
	{
		std::cout << "What do you want to do ?" << std::endl;
		std::cout << "(1) View base" << std::endl;
		std::cout << "(2) Select Building Factory" << std::endl;
		std::cout << "(3) Select Unit Factory" << std::endl;
		std::cout << "(4) Save base" << std::endl;
		std::cout << "(5) Load a base" << std::endl;
		std::cout << "(0) Exit application" << std::endl;
		int input(99);
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cin >> input;
		}
		switch (input)
		{
		case 0:
			exitCode = 1;
			break;
		case 1:
		{
			std::cout << "--------------------------------" << std::endl;
			std::cout << *(base->getField());
			std::cout << "--------------------------------" << std::endl;
			std::cout << "-1 : Empty ";
			std::cout << "-2 : Loading Zone ";
			std::cout << "-3 : Tree" << std::endl;
			while (exitCode != 1)
			{
				std::cout << std::endl;
				std::cout << "What do you want to see ?" << std::endl;
				std::cout << "(1) List of building" << std::endl;
				std::cout << "(2) List of units" << std::endl;
				std::cout << "(0) Back To Menu" << std::endl;
				int input;
				std::cin >> input;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<int>::max(), '\n');
					std::cin >> input;
				}
				switch (input)
				{
				case 0:
					exitCode = 1;
					break;
				case 1:
					base->printBuildings();
					while (exitCode != 1)
					{
						std::cout << std::endl;
						std::cout << "What do you want to do ?" << std::endl;
						std::cout << "You have " << base->getMoney() << " gold to base" << std::endl;
						std::cout << "(1) Upgrade building" << std::endl;
						std::cout << "(2) Delete building" << std::endl;
						std::cout << "(0) Back To Menu" << std::endl;
						int input;
						std::cin >> input;
						switch (input)
						{
						case 0:
							exitCode = 1;
							break;
						case 1:
						{
							std::cout << "Which ?" << std::endl;
							std::cin >> input;
							base->enhanceBuilding(input);
							std::cout << "Upgrade Suceed" << std::endl;
							break;
						}
						case 2:
						{
							std::cout << "Which ?" << std::endl;
							std::cin >> input;
							base->destroyBuilding(input);
							std::cout << "Delete Suceed" << std::endl;
							break;
						}

						default:
							std::cout << "This is not a valid input" << std::endl;
							break;
						}
					}
					exitCode = 0;
					break;
				case 2:
				{
					while (exitCode != 1)
					{
						std::cout << *army;
						std::cout << std::endl;
						std::cout << "What do you want to do ?" << std::endl;
						std::cout << "(1) Upgrade unit" << std::endl;
						std::cout << "(2) Delete unit" << std::endl;
						std::cout << "(0) Back To Menu" << std::endl;
						int input;
						std::cin >> input;
						if (std::cin.fail())
						{
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<int>::max(), '\n');
							std::cin >> input;
						}
						switch (input)
						{
						case 0:
							exitCode = 1;
							break;
						case 1:
						{
							std::cout << "Which ?" << std::endl;
							std::cin >> input;
							if (input>0 && input < army->GetUnits().size() + 1)
								std::cout << "Updated for " << army->LevelUpUnit(input - 1) << " gold" << std::endl;
							break;
						}
						case 2:
						{
							std::cout << "Which ?" << std::endl;
							std::cin >> input;
							if (input>0 && input < army->GetUnits().size() + 1)
								army->DeleteUnit(army->GetUnits()[input - 1].getType(), army->GetUnits()[input - 1].getLevel());
							break;
						}

						default:
							std::cout << "This is not a valid input" << std::endl;
							break;
						}
					}
					exitCode = 0;
					break;
				}
				default:
					std::cout << "This is not a valid input" << std::endl;
					break;
				}
			}
			exitCode = 0;
			break;
		}
		case 2:
		{
			while (exitCode != 1)
			{
				std::cout << std::endl;
				std::cout << "What do you want to do ?" << std::endl;
				std::cout << "You have " << base->getMoney() << " gold to base" << std::endl;
				std::cout << "(1) Build building" << std::endl;
				std::cout << "(2) View building Possibilities" << std::endl;
				std::cout << "(0) Back To Menu" << std::endl;
				int input;
				std::cin >> input;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<int>::max(), '\n');
					std::cin >> input;
				}
				switch (input)
				{
				case 0:
					exitCode = 1;
					break;
				case 1:
				{
					std::string name;
					std::cout << "Name: ";
					std::cin >> name;
					base->addBuilding(name.c_str());
					break;
				}
				case 2:
				{
					base->printBuildingsPossibilies();
					break;
				}
				default:
					std::cout << "This is not a valid input" << std::endl;
					break;
				}
			}
			exitCode = 0;
			break;
		}
		case 3:
		{
			while (exitCode != 1)
			{
				std::cout << std::endl;
				std::cout << "You have " << army->getMoney() << " gold to army" << std::endl;

				std::cout << "You can create:" << std::endl;
				for (size_t i = 0; i < army->GetFactory().UnitList().size(); i++)
				{
					std::cout << "(" << i + 1 << ") " << army->GetFactory().UnitList()[i] << std::endl;;
				}
				std::cout << "(0) Back" << std::endl;
				int input;
				std::cin >> input;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<int>::max(), '\n');
					std::cin >> input;
				}
				if (input == 0)
					exitCode = 1;
				else {
					army->GetFactory().CreateUnit(unitType(input - 1), army);
				}

			}
			exitCode = 0;
			break;
		}
		case 4:
		{
			base->saveBase();
			army->SaveArmy();
			break;
		}
		case 5:
		{
			base->loadBase();
			army->LoadArmy();
			break;
		}
		default:
			std::cout << "This is not a valid input" << std::endl;
			break;
		}
		std::cout << "//////////////////////////////////" << std::endl << std::endl;
	}
}*/