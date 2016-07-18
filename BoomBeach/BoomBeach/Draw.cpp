#pragma once
#include "Draw.h"
#include <iostream>
#include "glut.h"
#include "Tools.h"
#include <algorithm>

GLuint textureImage[11];
std::vector <Building*> _buildingModels;
std::vector <Unit*> _unitModels;
Base *base;
Army *army;
Field *field;
int *_map;

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

std::pair<int, int> positionOrder;

bool goToDestination = false;
bool inDrop = false;

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

		int tile = _map[(int)realx + (int)realy *field->getWidth()];
		//if can construct on that tile
		if (tile == -1 && currentBuilding != -1)
		{
			if (base->addBuilding((_buildingModels[currentBuilding]->getName()).c_str(), realx, realy) == true)
			{
				_map = field->getData();
				currentBuilding = -1;
			}
		}
		else 
		{
			//if can drop unit on that tile
			if (tile == -2 && currentUnit != -1)
			{
				army->addAttackUnit(currentUnit, realx, realy);
				std::cout << "ok" << std::endl;
				currentUnit = -1;

				inDrop = false;
			}
		}

		positionOrder.first = realx;
		positionOrder.second = realy;
		goToDestination = true;
		std::cout << positionOrder.first << " " << positionOrder.second << std::endl;
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
	_map = field->getData();

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

	textureImage[10] = createTexture("tile-brute.png");

	_buildingModels = base->getBuildingsPossibilities();
	_unitModels = army->getUnitsPossibilities();
	positionOrder.first = 0;
	positionOrder.second = 0;
}


void DrawRender()
{
	int tile;
	glOrtho(0, widthMap, heightMap, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	float sizewidth = widthMap / (base->getField()->getWidth() - 0.05f);
	float sizeheight = heightMap / (base->getField()->getHeight() - 0.05f);

	//draw map
	for (int y = 0; y < field->getHeight(); y++)
	{
		for (int x = 0; x < field->getWidth(); x++)
		{
			tile = _map[x + y *field->getWidth()];

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

	//draw army
	for (unsigned int i = 0; i < army->getCurrentAttackUnits().size(); i++)
	{
		glBindTexture(GL_TEXTURE_2D, textureImage[10]);
		float realx = army->getCurrentAttackUnits()[i]->getPosition().first * sizewidth;
		float realy = army->getCurrentAttackUnits()[i]->getPosition().second * sizeheight;
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(float(realx), float(realy), 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(float(realx + sizewidth), float(realy), 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(float(realx + sizewidth), float(realy + sizeheight), 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(float(realx), float(realy + sizeheight), 0.0f);
		glEnd();
	}

	glBindTexture(GL_TEXTURE_2D, 0);
	//Draw cell selected on map
	currentSquare.x = squarex * sizewidth;
	currentSquare.y = squarey * sizeheight;
	
	float sizeheightCell = heightMap / (base->getField()->getHeight());
	float sizewidthCell = widthMap / (base->getField()->getWidth());

	currentSquare.width = sizewidthCell;
	currentSquare.height = sizeheightCell;

	if (currentBuilding != -1)
	{
		currentSquare.width *= _buildingModels[currentBuilding]->getWidth();
		currentSquare.height *= _buildingModels[currentBuilding]->getHeight();
	}

	glBegin(GL_LINE_LOOP);
	glVertex3f(float(currentSquare.x), float(currentSquare.y), 0.0f);
	glVertex3f(float(currentSquare.x + currentSquare.width), float(currentSquare.y), 0.0f);
	glVertex3f(float(currentSquare.x + currentSquare.width), float(currentSquare.y + currentSquare.height), 0.0f);
	glVertex3f(float(currentSquare.x), float(currentSquare.y + currentSquare.height), 0.0f);
	glEnd();
}

#pragma region callbacks_ui

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
	inDrop = true;
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
std::vector<AttackUnit*> get_attackunits()
{
	return army->getCurrentAttackUnits();
}
int get_indexattackunit(int id)
{
	return army->getIndexOfAttackUnit(id);
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
void delete_attackUnit(int index)
{
	army->deleteAttackUnit(index);
}
void clear_attackUnit()
{
	army->clearAttackUnit();
}
bool in_drop()
{
	return inDrop;
}
#pragma endregion

#pragma region A*

#include <cmath>
#include <map>

struct noeud {
	float cout_g, cout_h, cout_f;
	std::pair<int, int> parent;
};

struct point {
	int x, y;
};

typedef std::map< std::pair<int, int>, noeud> l_noeud;

l_noeud liste_ouverte;
l_noeud liste_fermee;
std::vector<point> chemin;

struct point arrivee;
noeud depart;

void ajouter_cases_adjacentes(std::pair<int, int>&);
bool deja_present_dans_liste(std::pair<int, int>,
	l_noeud&);
std::pair<int, int> meilleur_noeud(l_noeud&);
void ajouter_liste_fermee(std::pair<int, int>&);
void retrouver_chemin();


std::pair<int, int> FindPath(int dx, int dy, int ax, int ay) {

	liste_ouverte.clear();
	liste_fermee.clear();
	chemin.clear();

	arrivee.x = ax;
	arrivee.y = ay;

	//std::cout << "dx " << dx << " dy " << dy << " ax " << ax << " ay " << ay << std::endl;

	depart.parent.first = dx;
	depart.parent.second = dy;

	std::pair <int, int> courant;

	/* deroulement de l'algo A* */

	courant.first = dx;
	courant.second = dy;
	// ajout de courant dans la liste ouverte

	liste_ouverte[courant] = depart;
	ajouter_liste_fermee(courant);
	ajouter_cases_adjacentes(courant);


	while (!((courant.first == arrivee.x) && (courant.second == arrivee.y))
		&&
		(!liste_ouverte.empty())
		) {

		// on cherche le meilleur noeud de la liste ouverte, on sait qu'elle n'est pas vide donc il existe
		courant = meilleur_noeud(liste_ouverte);

		// on le passe dans la liste fermee, il ne peut pas deja etre
		ajouter_liste_fermee(courant);

		ajouter_cases_adjacentes(courant);
	}

	if ((courant.first == arrivee.x) && (courant.second == arrivee.y)) {
		retrouver_chemin();
	}
	else {
		/* pas de solution */
		std::cout << "Error" << std::endl;
	}

	std::pair<int, int> result;
	if (chemin.size() > 0) {
		result.first = chemin[0].x;
		result.second = chemin[0].y;
	}
	else {
		result.first = dx;
		result.second = dy;
	}


	return result;
}

/*
ajoute toutes les cases adjacentes ? n dans la liste ouverte
*/
void ajouter_cases_adjacentes(std::pair <int, int>& n) {
	noeud tmp;

	// on met tous les noeud adjacents dans la liste ouverte (+v?rif)
	for (int i = n.first - 1; i <= n.first + 1; i++) {
		if ((i<0) || (i >= field->getWidth()))
			continue;
		for (int j = n.second - 1; j <= n.second + 1; j++) {
			if ((j<0) || (j >= field->getHeight()))
				continue;
			if ((i == n.first) && (j == n.second))  // case actuelle n
				continue;

			if (_map[i + j *field->getWidth()] != -1 && _map[i + j *field->getWidth()] != -2)
				// obstace, terrain non franchissable
				continue;

			std::pair<int, int> it(i, j);

			if (!deja_present_dans_liste(it, liste_fermee)) {
				/* le noeud n'est pas d?j? pr?sent dans la liste ferm?e */

				tmp.cout_g = liste_fermee[n].cout_g + distance(i, j, n.first, n.second);
				tmp.cout_h = distance(i, j, arrivee.x, arrivee.y);
				tmp.cout_f = tmp.cout_g + tmp.cout_h;
				tmp.parent = n;

				if (deja_present_dans_liste(it, liste_ouverte)) {
					/* le noeud est d?j? pr?sent dans la liste ouverte, il faut comparer les couts */
					if (tmp.cout_f < liste_ouverte[it].cout_f) {
						/* si le nouveau chemin est meilleur, on update */
						liste_ouverte[it] = tmp;
					}
					/* le noeud courant a un moins bon chemin, on ne change rien */
				}
				else {
					/* le noeud n'est pas pr?sent dans la liste ouverte, on l'ajoute */
					liste_ouverte[std::pair<int, int>(i, j)] = tmp;
				}
			}
		}
	}
}

bool deja_present_dans_liste(std::pair<int, int> n, l_noeud& l) {
	l_noeud::iterator i = l.find(n);
	if (i == l.end())
		return false;
	else
		return true;
}

/*
fonction qui renvoie la cl? du meilleur noeud de la liste
*/
std::pair<int, int> meilleur_noeud(l_noeud& l) {
	float m_coutf = l.begin()->second.cout_f;
	std::pair<int, int> m_noeud = l.begin()->first;

	for (l_noeud::iterator i = l.begin(); i != l.end(); i++)
		if (i->second.cout_f < m_coutf) {
			m_coutf = i->second.cout_f;
			m_noeud = i->first;
		}

	return m_noeud;
}

/*
fonction qui passe l'?l?ment p de la liste ouverte dans la ferm?e
*/
void ajouter_liste_fermee(std::pair<int, int>& p) {
	noeud& n = liste_ouverte[p];
	liste_fermee[p] = n;

	// il faut le supprimer de la liste ouverte, ce n'est plus une solution explorable
	liste_ouverte.erase(p);

	return;
}

void retrouver_chemin() {
	// l'arriv?e est le dernier ?l?ment de la liste ferm?e.
	noeud& tmp = liste_fermee[std::pair<int, int>(arrivee.x, arrivee.y)];

	struct point n;
	std::pair<int, int> prec;
	n.x = arrivee.x;
	n.y = arrivee.y;
	prec.first = tmp.parent.first;
	prec.second = tmp.parent.second;
	chemin.insert(chemin.begin(), n);

	while (prec != std::pair<int, int>(depart.parent.first, depart.parent.second)) {
		n.x = prec.first;
		n.y = prec.second;
		chemin.insert(chemin.begin(), n);

		tmp = liste_fermee[tmp.parent];
		prec.first = tmp.parent.first;
		prec.second = tmp.parent.second;
	}
}

std::pair<int, int>* findAroundEmptyTile(std::pair<int, int> &tmpPosition, int x, int y) {
	while (!field->IsEmpty(tmpPosition.first, tmpPosition.second) && tmpPosition.first > 0 && tmpPosition.second > 0 && tmpPosition.first < field->getWidth() && tmpPosition.second < field->getHeight())
	{
		tmpPosition.first += std::max(-1, std::min(x - tmpPosition.first, 1));
		tmpPosition.second += std::max(-1, std::min(y - tmpPosition.second, 1));
	}
	return &tmpPosition;
}

void move_unit(int index)
{
	int unitx = army->getCurrentAttackUnits()[army->getIndexOfAttackUnit(index)]->getPosition().first;
	int unity = army->getCurrentAttackUnits()[army->getIndexOfAttackUnit(index)]->getPosition().second;

	std::pair<int, int>* tmpPosition = &std::make_pair(0, 0);

	if (!goToDestination) {
		Zone targetZone;
		targetZone = base->GetNearestBuilding(unitx, unity)->getZone();

		tmpPosition->first = targetZone.getX() + targetZone.getWidth() / 2;
		tmpPosition->second = targetZone.getY() + targetZone.getHeight() / 2;

		tmpPosition = findAroundEmptyTile(*tmpPosition, unitx, unity);

		army->moveUnit(index, FindPath(unitx, unity, tmpPosition->first, tmpPosition->second));
	}
	else {
		tmpPosition->first = positionOrder.first;
		tmpPosition->second = positionOrder.second;

		if (!field->IsEmpty(positionOrder.first, positionOrder.second)) {

			tmpPosition = findAroundEmptyTile(*tmpPosition, unitx, unity);
		}
		army->moveUnit(index, FindPath(unitx, unity, tmpPosition->first, tmpPosition->second));
	}

	if (unitx == tmpPosition->first && unity == tmpPosition->second) {
		goToDestination = false;
	}
	//std::cout << std::endl;
}

// Attaque des unités
void attack_unit(int index) {
	int unitX = army->getCurrentAttackUnits()[army->getIndexOfAttackUnit(index)]->getPosition().first;
	int unitY = army->getCurrentAttackUnits()[army->getIndexOfAttackUnit(index)]->getPosition().second;
	Zone targetZone;
	targetZone = base->GetNearestBuilding(unitX, unitY)->getZone();
	if (distance((float)unitX + 1.0f / 2.0f, (float)unitY + 1.0f / 2.0f,
		targetZone.getX() + targetZone.getWidth() / 2.0f, targetZone.getY() + targetZone.getHeight() / 2.0f)
		- distance((float)targetZone.getX(), (float)targetZone.getY(), targetZone.getX() + targetZone.getWidth() / 2.0f,
			targetZone.getY() + targetZone.getHeight() / 2.0f) <= army->getCurrentAttackUnits()[army->getIndexOfAttackUnit(index)]->getRange())
	{
		Building* nearestBuilding = base->GetNearestBuilding(unitX, unitY);
		AttackUnit* unit = army->getCurrentAttackUnits()[army->getIndexOfAttackUnit(index)];
		int damage = unit->getAttack();
		if (unit->getType() == 1)
			unit->takeDamage(unit->getLife());

		nearestBuilding->takeDamage(damage);
	}
}

// Attaque des batiments
void attack_building(int index)
{
	Zone buildingZone = base->getBuilding(index)->getZone();
	std::pair<int, int> unitPos;
	if (army->getCurrentAttackUnits().size() > 0) 
	{
		unitPos = army->GetNearestUnit(buildingZone.getX(), buildingZone.getY())->getPosition();
		if (distance((float)unitPos.first + 1.0f / 2.0f, (float)unitPos.second + 1.0f / 2.0f,
			buildingZone.getX() + buildingZone.getWidth() / 2.0f, buildingZone.getY() + buildingZone.getHeight() / 2.0f)
			- distance((float)buildingZone.getX(), (float)buildingZone.getY(), buildingZone.getX() + buildingZone.getWidth() / 2.0f,
				buildingZone.getY() + buildingZone.getHeight() / 2.0f) <= base->getBuilding(index)->getRange())
	
			army->GetNearestUnit(buildingZone.getX(), buildingZone.getY())->takeDamage(base->getBuilding(index)->getPower());
	}
}

void triggerBuildingActions()
{

	for (unsigned int i = 0; i < base->getCurrentBuildings().size(); i++)
	{
		int targetedIndex;
		int distance = 0;
		//For Support Units
		
		if (base->getCurrentBuildings()[i]->getType() == 5)
		{

		}
		else if (base->getCurrentBuildings()[i]->getType() == 6)
		{

		}
		else if (base->getCurrentBuildings()[i]->getType() == 7)
		{

		}
		else
			//For Attack Units
		{
			if (base->getCurrentBuildings()[i]->getTargetType() == 0) //Nothing
			{

			}
			else if (base->getCurrentBuildings()[i]->getTargetType() == 1) //Low HP Unit
			{
				//Boucler sur les unités voulues
				int lowest=999999;
				for (unsigned int j = 0; j < army->getCurrentUnits().size(); j++) {
					if (army->getCurrentUnits()[j]->getLife() < lowest)
					{
						lowest = army->getCurrentUnits()[j]->getLife();
						targetedIndex = j;
					}
				}

				base->getCurrentBuildings()[i]->attackUnit(army->getCurrentUnits()[targetedIndex]);
			}
			else if (base->getCurrentBuildings()[i]->getTargetType() == 2) //High HP Unit
			{
				int heighest = 0;
				for (unsigned int j = 0; j < army->getCurrentUnits().size(); j++) {
					if (army->getCurrentUnits()[j]->getLife() > heighest)
					{
						heighest = army->getCurrentUnits()[j]->getLife();
						targetedIndex = j;
					}
				}

				base->getCurrentBuildings()[i]->attackUnit(army->getCurrentUnits()[targetedIndex]);
			}
			else if (base->getCurrentBuildings()[i]->getTargetType() == 3) //Closest Unit
			{

			}
			else if (base->getCurrentBuildings()[i]->getTargetType() == 4) //Closest to HQ
			{
				
			}
			else if (base->getCurrentBuildings()[i]->getTargetType() == 5) //Strongest Unit
			{
				int heighest = 0;
				for (unsigned int j = 0; j < army->getCurrentUnits().size(); j++) {
					if (army->getCurrentUnits()[j]->getAttack() > heighest)
					{
						heighest = army->getCurrentUnits()[j]->getAttack();
						targetedIndex = j;
					}
				}

				base->getCurrentBuildings()[i]->attackUnit(army->getCurrentUnits()[targetedIndex]);
			}
			else if (base->getCurrentBuildings()[i]->getTargetType() == 6) //Closest Support Unit
			{
				int closest = 999;
				for (unsigned int j = 0; j < army->getCurrentUnits().size(); j++) {
					if (army->getCurrentUnits()[j]->getType() == 0 /*Mettre le type pour type d'unité de soutien*/) {
						
					}
					
				}
			}
		}

	}
}


void goToNextTargetType(int index)
{

	if (base->getCurrentBuildings()[index] != nullptr)
	{
		int a = base->getCurrentBuildings()[index]->getTargetType();
		base->getCurrentBuildings()[index]->setTargetType( a + 1);
	}
}

#pragma endregion