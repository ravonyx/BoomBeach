#pragma once
#include "GL/glew.h"
#include "Building.h"
#include "Base.h"

void Initialize();
void DrawRender();

void save_callback();
void load_callback();

void add_building(int nbBuilding);
void add_unit(int nbUnits);

void mouse(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);