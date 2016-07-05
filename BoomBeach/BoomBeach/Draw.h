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

int get_army_money();
int get_base_money();


void mouse(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
void mouseMotion(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);