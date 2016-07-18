#pragma once
#include "GL/glew.h"
#include "Building.h"
#include "Base.h"

void Initialize();
void DrawRender();
void SetDimensionMap(GLsizei width, GLsizei height);

void save_callback();
void load_callback();

void add_building(int nbBuilding);
void add_unit(int nbUnits);

void attack_building(int index);

void attack_unit(int index);
void move_unit(int index);
void drop_unit(int nbUnit);

int get_army_money();
int get_base_money();

int get_building_max(int nbBuilding);
int get_building_instances(int nbBuilding);
int get_unit_max(int nbUnits);
int get_unit_instances(int nbUnits);

void enhance_building(int index);
void delete_building(int index);
void enhance_unit(int index);
void delete_unit(int index);
void delete_attackUnit(int index);
void clear_attackUnit();

void triggerBuildingActions();
void goToNextTargetType(int index);


std::vector<Building*> get_buildings();
std::vector<Unit*> get_units();
std::vector<AttackUnit*> get_attackunits();

void mouse(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
void mouseMotion(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);