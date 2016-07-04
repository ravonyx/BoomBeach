#pragma once
#include "GL/glew.h"
#include "Building.h"
#include "Base.h"


void Initialize();
void DrawRender();
void save_callback();
void load_callback();

void menu(int item);
void processConstructionMenu(int option);
void processUnitsMenu(int option);
void mouse(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);