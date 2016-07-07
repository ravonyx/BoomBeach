#pragma once

#include "OpenGL.h"

#include <iostream>

namespace UIBoomBeach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;

	/// <summary>
	/// </summary>
	public ref class UIForm : public System::Windows::Forms::Form
	{
	public:
		UIForm(void)
		{
			InitializeComponent();
			this->timer->Enabled = false;
			OpenGL = gcnew COpenGL(pictureBox, pictureBox->Width, pictureBox->Height);
			this->timer->Enabled = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UIForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		OpenGLForm::COpenGL ^ OpenGL;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Button^  load;
	private: System::Windows::Forms::Button^  save;
	private: System::Windows::Forms::GroupBox^  unitsBox;
	private: System::Windows::Forms::PictureBox^  pictureBox;
	private: System::Windows::Forms::TableLayoutPanel^  saveLoad;


	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::MenuStrip^  menu;
	private: System::Windows::Forms::ToolStripMenuItem^  buildingsMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  unitsMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  QGMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sniperTowerMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lanceFlammeMenuItem;





	private: System::Windows::Forms::ToolStripMenuItem^  mitrailleuseMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  repareBuildingMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  shieldBuildingMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  energyBuildingMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bruteMenuItem;



	private: System::Windows::Forms::ToolStripMenuItem^  kamikazeMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fusilleurMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  sniperMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bazookaMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  medecinContactMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  medecinSeringueMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  medecinZoneMenuItem;

	private: System::Windows::Forms::TableLayoutPanel^  visualisationValuesGame;
	private: System::Windows::Forms::TableLayoutPanel^  money;


	private: System::Windows::Forms::Label^  baseMoney;
	private: System::Windows::Forms::Label^  armyMoney;
	private: System::Windows::Forms::TableLayoutPanel^  layoutUnits;

	private: System::Windows::Forms::Label^  bruteName;

	private: System::Windows::Forms::Label^  bruteValue;
	private: System::Windows::Forms::Label^  kamikazeName;
	private: System::Windows::Forms::Label^  fusilleurName;
	private: System::Windows::Forms::Label^  kamikazeValue;








	private: System::Windows::Forms::Label^  sniperName;
	private: System::Windows::Forms::Label^  bazookaName;
	private: System::Windows::Forms::Label^  medecinContactName;
	private: System::Windows::Forms::Label^  medecinSeringueName;
	private: System::Windows::Forms::Label^  medecinZoneName;
	private: System::Windows::Forms::Label^  fusilleurValue;
	private: System::Windows::Forms::Label^  sniperValue;
	private: System::Windows::Forms::Label^  bazookaValue;
	private: System::Windows::Forms::Label^  medecinContactValue;
	private: System::Windows::Forms::Label^  medecinSeringueValue;
	private: System::Windows::Forms::Label^  medecinZoneValue;
	private: System::Windows::Forms::TableLayoutPanel^  buildingsUnits;

	private: System::Windows::Forms::GroupBox^  buildingsBox;
	private: System::Windows::Forms::TableLayoutPanel^  layoutBuildings;
	private: System::Windows::Forms::Label^  QGName;
	private: System::Windows::Forms::Label^  sniperTowerName;
	private: System::Windows::Forms::Label^  lanceflammeName;
	private: System::Windows::Forms::Label^  mitrailleuseName;
	private: System::Windows::Forms::Label^  repareBuildingName;
	private: System::Windows::Forms::Label^  shieldBuildingName;






private: System::Windows::Forms::Label^  energyBuildingName;
private: System::Windows::Forms::Label^  QGValue;
private: System::Windows::Forms::Label^  sniperTowerValue;
private: System::Windows::Forms::Label^  lanceflammeValue;
private: System::Windows::Forms::Label^  mitrailleuseValue;
private: System::Windows::Forms::Label^  repareBuildingValue;
private: System::Windows::Forms::Label^  shieldBuildingValue;
private: System::Windows::Forms::Label^  energyBuildingValue;












































	private: System::Windows::Forms::Timer^  timer;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
				 this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
				 this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
				 this->visualisationValuesGame = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->money = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->baseMoney = (gcnew System::Windows::Forms::Label());
				 this->armyMoney = (gcnew System::Windows::Forms::Label());
				 this->buildingsUnits = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->unitsBox = (gcnew System::Windows::Forms::GroupBox());
				 this->layoutUnits = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->bruteName = (gcnew System::Windows::Forms::Label());
				 this->bruteValue = (gcnew System::Windows::Forms::Label());
				 this->kamikazeName = (gcnew System::Windows::Forms::Label());
				 this->fusilleurName = (gcnew System::Windows::Forms::Label());
				 this->kamikazeValue = (gcnew System::Windows::Forms::Label());
				 this->sniperName = (gcnew System::Windows::Forms::Label());
				 this->bazookaName = (gcnew System::Windows::Forms::Label());
				 this->medecinContactName = (gcnew System::Windows::Forms::Label());
				 this->medecinSeringueName = (gcnew System::Windows::Forms::Label());
				 this->medecinZoneName = (gcnew System::Windows::Forms::Label());
				 this->fusilleurValue = (gcnew System::Windows::Forms::Label());
				 this->sniperValue = (gcnew System::Windows::Forms::Label());
				 this->bazookaValue = (gcnew System::Windows::Forms::Label());
				 this->medecinContactValue = (gcnew System::Windows::Forms::Label());
				 this->medecinSeringueValue = (gcnew System::Windows::Forms::Label());
				 this->medecinZoneValue = (gcnew System::Windows::Forms::Label());
				 this->buildingsBox = (gcnew System::Windows::Forms::GroupBox());
				 this->layoutBuildings = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->QGName = (gcnew System::Windows::Forms::Label());
				 this->sniperTowerName = (gcnew System::Windows::Forms::Label());
				 this->lanceflammeName = (gcnew System::Windows::Forms::Label());
				 this->mitrailleuseName = (gcnew System::Windows::Forms::Label());
				 this->repareBuildingName = (gcnew System::Windows::Forms::Label());
				 this->shieldBuildingName = (gcnew System::Windows::Forms::Label());
				 this->energyBuildingName = (gcnew System::Windows::Forms::Label());
				 this->QGValue = (gcnew System::Windows::Forms::Label());
				 this->sniperTowerValue = (gcnew System::Windows::Forms::Label());
				 this->lanceflammeValue = (gcnew System::Windows::Forms::Label());
				 this->mitrailleuseValue = (gcnew System::Windows::Forms::Label());
				 this->repareBuildingValue = (gcnew System::Windows::Forms::Label());
				 this->shieldBuildingValue = (gcnew System::Windows::Forms::Label());
				 this->energyBuildingValue = (gcnew System::Windows::Forms::Label());
				 this->saveLoad = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->load = (gcnew System::Windows::Forms::Button());
				 this->save = (gcnew System::Windows::Forms::Button());
				 this->timer = (gcnew System::Windows::Forms::Timer(this->components));
				 this->menu = (gcnew System::Windows::Forms::MenuStrip());
				 this->buildingsMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->QGMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->sniperTowerMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->lanceFlammeMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->mitrailleuseMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->repareBuildingMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->shieldBuildingMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->energyBuildingMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->unitsMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->bruteMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->kamikazeMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->fusilleurMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->sniperMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->bazookaMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->medecinContactMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->medecinSeringueMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->medecinZoneMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
				 this->splitContainer1->Panel1->SuspendLayout();
				 this->splitContainer1->Panel2->SuspendLayout();
				 this->splitContainer1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
				 this->splitContainer2->Panel1->SuspendLayout();
				 this->splitContainer2->Panel2->SuspendLayout();
				 this->splitContainer2->SuspendLayout();
				 this->visualisationValuesGame->SuspendLayout();
				 this->money->SuspendLayout();
				 this->buildingsUnits->SuspendLayout();
				 this->unitsBox->SuspendLayout();
				 this->layoutUnits->SuspendLayout();
				 this->buildingsBox->SuspendLayout();
				 this->layoutBuildings->SuspendLayout();
				 this->saveLoad->SuspendLayout();
				 this->menu->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // splitContainer1
				 // 
				 this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->splitContainer1->Location = System::Drawing::Point(0, 24);
				 this->splitContainer1->Name = L"splitContainer1";
				 // 
				 // splitContainer1.Panel1
				 // 
				 this->splitContainer1->Panel1->Controls->Add(this->pictureBox);
				 // 
				 // splitContainer1.Panel2
				 // 
				 this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
				 this->splitContainer1->Size = System::Drawing::Size(873, 397);
				 this->splitContainer1->SplitterDistance = 459;
				 this->splitContainer1->TabIndex = 0;
				 // 
				 // pictureBox
				 // 
				 this->pictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->pictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				 this->pictureBox->Location = System::Drawing::Point(3, 3);
				 this->pictureBox->Name = L"pictureBox";
				 this->pictureBox->Size = System::Drawing::Size(453, 391);
				 this->pictureBox->TabIndex = 0;
				 this->pictureBox->TabStop = false;
				 // 
				 // splitContainer2
				 // 
				 this->splitContainer2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->splitContainer2->Location = System::Drawing::Point(3, 3);
				 this->splitContainer2->Name = L"splitContainer2";
				 this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
				 // 
				 // splitContainer2.Panel1
				 // 
				 this->splitContainer2->Panel1->Controls->Add(this->visualisationValuesGame);
				 // 
				 // splitContainer2.Panel2
				 // 
				 this->splitContainer2->Panel2->Controls->Add(this->saveLoad);
				 this->splitContainer2->Size = System::Drawing::Size(404, 391);
				 this->splitContainer2->SplitterDistance = 338;
				 this->splitContainer2->TabIndex = 1;
				 // 
				 // visualisationValuesGame
				 // 
				 this->visualisationValuesGame->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->visualisationValuesGame->ColumnCount = 1;
				 this->visualisationValuesGame->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->visualisationValuesGame->Controls->Add(this->money, 0, 0);
				 this->visualisationValuesGame->Controls->Add(this->buildingsUnits, 0, 1);
				 this->visualisationValuesGame->Location = System::Drawing::Point(0, 3);
				 this->visualisationValuesGame->Name = L"visualisationValuesGame";
				 this->visualisationValuesGame->RowCount = 2;
				 this->visualisationValuesGame->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
					 8.421053F)));
				 this->visualisationValuesGame->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
					 91.57895F)));
				 this->visualisationValuesGame->Size = System::Drawing::Size(401, 332);
				 this->visualisationValuesGame->TabIndex = 0;
				 // 
				 // money
				 // 
				 this->money->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->money->ColumnCount = 2;
				 this->money->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
				 this->money->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
				 this->money->Controls->Add(this->baseMoney, 0, 0);
				 this->money->Controls->Add(this->armyMoney, 1, 0);
				 this->money->Location = System::Drawing::Point(3, 3);
				 this->money->Name = L"money";
				 this->money->RowCount = 1;
				 this->money->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				 this->money->Size = System::Drawing::Size(395, 21);
				 this->money->TabIndex = 1;
				 // 
				 // baseMoney
				 // 
				 this->baseMoney->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->baseMoney->AutoSize = true;
				 this->baseMoney->ImageAlign = System::Drawing::ContentAlignment::TopRight;
				 this->baseMoney->Location = System::Drawing::Point(3, 0);
				 this->baseMoney->Name = L"baseMoney";
				 this->baseMoney->Size = System::Drawing::Size(191, 21);
				 this->baseMoney->TabIndex = 0;
				 this->baseMoney->Text = L"Base Money :";
				 this->baseMoney->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // armyMoney
				 // 
				 this->armyMoney->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->armyMoney->AutoSize = true;
				 this->armyMoney->Location = System::Drawing::Point(200, 0);
				 this->armyMoney->Name = L"armyMoney";
				 this->armyMoney->Size = System::Drawing::Size(192, 21);
				 this->armyMoney->TabIndex = 1;
				 this->armyMoney->Text = L"Army Money :";
				 this->armyMoney->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // buildingsUnits
				 // 
				 this->buildingsUnits->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->buildingsUnits->ColumnCount = 2;
				 this->buildingsUnits->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->buildingsUnits->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->buildingsUnits->Controls->Add(this->unitsBox, 1, 0);
				 this->buildingsUnits->Controls->Add(this->buildingsBox, 0, 0);
				 this->buildingsUnits->Location = System::Drawing::Point(3, 30);
				 this->buildingsUnits->Name = L"buildingsUnits";
				 this->buildingsUnits->RowCount = 1;
				 this->buildingsUnits->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				 this->buildingsUnits->Size = System::Drawing::Size(395, 299);
				 this->buildingsUnits->TabIndex = 2;
				 // 
				 // unitsBox
				 // 
				 this->unitsBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->unitsBox->Controls->Add(this->layoutUnits);
				 this->unitsBox->Location = System::Drawing::Point(200, 3);
				 this->unitsBox->Name = L"unitsBox";
				 this->unitsBox->Size = System::Drawing::Size(192, 293);
				 this->unitsBox->TabIndex = 0;
				 this->unitsBox->TabStop = false;
				 this->unitsBox->Text = L"Units";
				 // 
				 // layoutUnits
				 // 
				 this->layoutUnits->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->layoutUnits->ColumnCount = 2;
				 this->layoutUnits->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 64.44444F)));
				 this->layoutUnits->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 35.55556F)));
				 this->layoutUnits->Controls->Add(this->bruteName, 0, 0);
				 this->layoutUnits->Controls->Add(this->bruteValue, 1, 0);
				 this->layoutUnits->Controls->Add(this->kamikazeName, 0, 1);
				 this->layoutUnits->Controls->Add(this->fusilleurName, 0, 2);
				 this->layoutUnits->Controls->Add(this->kamikazeValue, 1, 1);
				 this->layoutUnits->Controls->Add(this->sniperName, 0, 3);
				 this->layoutUnits->Controls->Add(this->bazookaName, 0, 4);
				 this->layoutUnits->Controls->Add(this->medecinContactName, 0, 5);
				 this->layoutUnits->Controls->Add(this->medecinSeringueName, 0, 6);
				 this->layoutUnits->Controls->Add(this->medecinZoneName, 0, 7);
				 this->layoutUnits->Controls->Add(this->fusilleurValue, 1, 2);
				 this->layoutUnits->Controls->Add(this->sniperValue, 1, 3);
				 this->layoutUnits->Controls->Add(this->bazookaValue, 1, 4);
				 this->layoutUnits->Controls->Add(this->medecinContactValue, 1, 5);
				 this->layoutUnits->Controls->Add(this->medecinSeringueValue, 1, 6);
				 this->layoutUnits->Controls->Add(this->medecinZoneValue, 1, 7);
				 this->layoutUnits->Location = System::Drawing::Point(6, 19);
				 this->layoutUnits->Name = L"layoutUnits";
				 this->layoutUnits->RowCount = 8;
				 this->layoutUnits->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
				 this->layoutUnits->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
				 this->layoutUnits->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
				 this->layoutUnits->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
				 this->layoutUnits->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
				 this->layoutUnits->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
				 this->layoutUnits->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
				 this->layoutUnits->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.5F)));
				 this->layoutUnits->Size = System::Drawing::Size(180, 268);
				 this->layoutUnits->TabIndex = 0;
				 // 
				 // bruteName
				 // 
				 this->bruteName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->bruteName->AutoSize = true;
				 this->bruteName->Location = System::Drawing::Point(3, 0);
				 this->bruteName->Name = L"bruteName";
				 this->bruteName->Size = System::Drawing::Size(109, 33);
				 this->bruteName->TabIndex = 0;
				 this->bruteName->Text = L"Brute";
				 this->bruteName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // bruteValue
				 // 
				 this->bruteValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->bruteValue->AutoSize = true;
				 this->bruteValue->Location = System::Drawing::Point(118, 0);
				 this->bruteValue->Name = L"bruteValue";
				 this->bruteValue->Size = System::Drawing::Size(59, 33);
				 this->bruteValue->TabIndex = 1;
				 this->bruteValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // kamikazeName
				 // 
				 this->kamikazeName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->kamikazeName->AutoSize = true;
				 this->kamikazeName->Location = System::Drawing::Point(3, 33);
				 this->kamikazeName->Name = L"kamikazeName";
				 this->kamikazeName->Size = System::Drawing::Size(109, 33);
				 this->kamikazeName->TabIndex = 2;
				 this->kamikazeName->Text = L"Kamikaze";
				 this->kamikazeName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // fusilleurName
				 // 
				 this->fusilleurName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->fusilleurName->AutoSize = true;
				 this->fusilleurName->Location = System::Drawing::Point(3, 66);
				 this->fusilleurName->Name = L"fusilleurName";
				 this->fusilleurName->Size = System::Drawing::Size(109, 33);
				 this->fusilleurName->TabIndex = 3;
				 this->fusilleurName->Text = L"Fusilleur";
				 this->fusilleurName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // kamikazeValue
				 // 
				 this->kamikazeValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->kamikazeValue->AutoSize = true;
				 this->kamikazeValue->Location = System::Drawing::Point(118, 33);
				 this->kamikazeValue->Name = L"kamikazeValue";
				 this->kamikazeValue->Size = System::Drawing::Size(59, 33);
				 this->kamikazeValue->TabIndex = 4;
				 this->kamikazeValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // sniperName
				 // 
				 this->sniperName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->sniperName->AutoSize = true;
				 this->sniperName->Location = System::Drawing::Point(3, 99);
				 this->sniperName->Name = L"sniperName";
				 this->sniperName->Size = System::Drawing::Size(109, 33);
				 this->sniperName->TabIndex = 5;
				 this->sniperName->Text = L"Sniper";
				 this->sniperName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // bazookaName
				 // 
				 this->bazookaName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->bazookaName->AutoSize = true;
				 this->bazookaName->Location = System::Drawing::Point(3, 132);
				 this->bazookaName->Name = L"bazookaName";
				 this->bazookaName->Size = System::Drawing::Size(109, 33);
				 this->bazookaName->TabIndex = 6;
				 this->bazookaName->Text = L"Bazooka";
				 this->bazookaName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // medecinContactName
				 // 
				 this->medecinContactName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->medecinContactName->AutoSize = true;
				 this->medecinContactName->Location = System::Drawing::Point(3, 165);
				 this->medecinContactName->Name = L"medecinContactName";
				 this->medecinContactName->Size = System::Drawing::Size(109, 33);
				 this->medecinContactName->TabIndex = 7;
				 this->medecinContactName->Text = L"Medecin contact";
				 this->medecinContactName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // medecinSeringueName
				 // 
				 this->medecinSeringueName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->medecinSeringueName->AutoSize = true;
				 this->medecinSeringueName->Location = System::Drawing::Point(3, 198);
				 this->medecinSeringueName->Name = L"medecinSeringueName";
				 this->medecinSeringueName->Size = System::Drawing::Size(109, 33);
				 this->medecinSeringueName->TabIndex = 8;
				 this->medecinSeringueName->Text = L"Medecin seringue";
				 this->medecinSeringueName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // medecinZoneName
				 // 
				 this->medecinZoneName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->medecinZoneName->AutoSize = true;
				 this->medecinZoneName->Location = System::Drawing::Point(3, 231);
				 this->medecinZoneName->Name = L"medecinZoneName";
				 this->medecinZoneName->Size = System::Drawing::Size(109, 37);
				 this->medecinZoneName->TabIndex = 9;
				 this->medecinZoneName->Text = L"Medecin zone";
				 this->medecinZoneName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // fusilleurValue
				 // 
				 this->fusilleurValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->fusilleurValue->AutoSize = true;
				 this->fusilleurValue->Location = System::Drawing::Point(118, 66);
				 this->fusilleurValue->Name = L"fusilleurValue";
				 this->fusilleurValue->Size = System::Drawing::Size(59, 33);
				 this->fusilleurValue->TabIndex = 10;
				 this->fusilleurValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // sniperValue
				 // 
				 this->sniperValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->sniperValue->AutoSize = true;
				 this->sniperValue->Location = System::Drawing::Point(118, 99);
				 this->sniperValue->Name = L"sniperValue";
				 this->sniperValue->Size = System::Drawing::Size(59, 33);
				 this->sniperValue->TabIndex = 11;
				 this->sniperValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // bazookaValue
				 // 
				 this->bazookaValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->bazookaValue->AutoSize = true;
				 this->bazookaValue->Location = System::Drawing::Point(118, 132);
				 this->bazookaValue->Name = L"bazookaValue";
				 this->bazookaValue->Size = System::Drawing::Size(59, 33);
				 this->bazookaValue->TabIndex = 12;
				 this->bazookaValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // medecinContactValue
				 // 
				 this->medecinContactValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->medecinContactValue->AutoSize = true;
				 this->medecinContactValue->Location = System::Drawing::Point(118, 165);
				 this->medecinContactValue->Name = L"medecinContactValue";
				 this->medecinContactValue->Size = System::Drawing::Size(59, 33);
				 this->medecinContactValue->TabIndex = 13;
				 this->medecinContactValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // medecinSeringueValue
				 // 
				 this->medecinSeringueValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->medecinSeringueValue->AutoSize = true;
				 this->medecinSeringueValue->Location = System::Drawing::Point(118, 198);
				 this->medecinSeringueValue->Name = L"medecinSeringueValue";
				 this->medecinSeringueValue->Size = System::Drawing::Size(59, 33);
				 this->medecinSeringueValue->TabIndex = 14;
				 this->medecinSeringueValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // medecinZoneValue
				 // 
				 this->medecinZoneValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->medecinZoneValue->AutoSize = true;
				 this->medecinZoneValue->Location = System::Drawing::Point(118, 231);
				 this->medecinZoneValue->Name = L"medecinZoneValue";
				 this->medecinZoneValue->Size = System::Drawing::Size(59, 37);
				 this->medecinZoneValue->TabIndex = 15;
				 this->medecinZoneValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // buildingsBox
				 // 
				 this->buildingsBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->buildingsBox->Controls->Add(this->layoutBuildings);
				 this->buildingsBox->Location = System::Drawing::Point(3, 3);
				 this->buildingsBox->Name = L"buildingsBox";
				 this->buildingsBox->Size = System::Drawing::Size(191, 293);
				 this->buildingsBox->TabIndex = 1;
				 this->buildingsBox->TabStop = false;
				 this->buildingsBox->Text = L"Buildings";
				 // 
				 // layoutBuildings
				 // 
				 this->layoutBuildings->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->layoutBuildings->ColumnCount = 2;
				 this->layoutBuildings->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 63.12849F)));
				 this->layoutBuildings->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 36.87151F)));
				 this->layoutBuildings->Controls->Add(this->QGName, 0, 0);
				 this->layoutBuildings->Controls->Add(this->sniperTowerName, 0, 1);
				 this->layoutBuildings->Controls->Add(this->lanceflammeName, 0, 2);
				 this->layoutBuildings->Controls->Add(this->mitrailleuseName, 0, 3);
				 this->layoutBuildings->Controls->Add(this->repareBuildingName, 0, 4);
				 this->layoutBuildings->Controls->Add(this->shieldBuildingName, 0, 5);
				 this->layoutBuildings->Controls->Add(this->energyBuildingName, 0, 6);
				 this->layoutBuildings->Controls->Add(this->QGValue, 1, 0);
				 this->layoutBuildings->Controls->Add(this->sniperTowerValue, 1, 1);
				 this->layoutBuildings->Controls->Add(this->lanceflammeValue, 1, 2);
				 this->layoutBuildings->Controls->Add(this->mitrailleuseValue, 1, 3);
				 this->layoutBuildings->Controls->Add(this->repareBuildingValue, 1, 4);
				 this->layoutBuildings->Controls->Add(this->shieldBuildingValue, 1, 5);
				 this->layoutBuildings->Controls->Add(this->energyBuildingValue, 1, 6);
				 this->layoutBuildings->Location = System::Drawing::Point(6, 19);
				 this->layoutBuildings->Name = L"layoutBuildings";
				 this->layoutBuildings->RowCount = 7;
				 this->layoutBuildings->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.2F)));
				 this->layoutBuildings->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.2F)));
				 this->layoutBuildings->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.2F)));
				 this->layoutBuildings->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.2F)));
				 this->layoutBuildings->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.2F)));
				 this->layoutBuildings->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.2F)));
				 this->layoutBuildings->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 14.2F)));
				 this->layoutBuildings->Size = System::Drawing::Size(179, 268);
				 this->layoutBuildings->TabIndex = 0;
				 // 
				 // QGName
				 // 
				 this->QGName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->QGName->AutoSize = true;
				 this->QGName->Location = System::Drawing::Point(3, 0);
				 this->QGName->Name = L"QGName";
				 this->QGName->Size = System::Drawing::Size(106, 38);
				 this->QGName->TabIndex = 0;
				 this->QGName->Text = L"QG";
				 this->QGName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // sniperTowerName
				 // 
				 this->sniperTowerName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->sniperTowerName->AutoSize = true;
				 this->sniperTowerName->Location = System::Drawing::Point(3, 38);
				 this->sniperTowerName->Name = L"sniperTowerName";
				 this->sniperTowerName->Size = System::Drawing::Size(106, 38);
				 this->sniperTowerName->TabIndex = 1;
				 this->sniperTowerName->Text = L"SniperTower";
				 this->sniperTowerName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // lanceflammeName
				 // 
				 this->lanceflammeName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->lanceflammeName->AutoSize = true;
				 this->lanceflammeName->Location = System::Drawing::Point(3, 76);
				 this->lanceflammeName->Name = L"lanceflammeName";
				 this->lanceflammeName->Size = System::Drawing::Size(106, 38);
				 this->lanceflammeName->TabIndex = 2;
				 this->lanceflammeName->Text = L"Lance Flamme";
				 this->lanceflammeName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // mitrailleuseName
				 // 
				 this->mitrailleuseName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->mitrailleuseName->AutoSize = true;
				 this->mitrailleuseName->Location = System::Drawing::Point(3, 114);
				 this->mitrailleuseName->Name = L"mitrailleuseName";
				 this->mitrailleuseName->Size = System::Drawing::Size(106, 38);
				 this->mitrailleuseName->TabIndex = 3;
				 this->mitrailleuseName->Text = L"Mitrailleuse";
				 this->mitrailleuseName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // repareBuildingName
				 // 
				 this->repareBuildingName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->repareBuildingName->AutoSize = true;
				 this->repareBuildingName->Location = System::Drawing::Point(3, 152);
				 this->repareBuildingName->Name = L"repareBuildingName";
				 this->repareBuildingName->Size = System::Drawing::Size(106, 38);
				 this->repareBuildingName->TabIndex = 4;
				 this->repareBuildingName->Text = L"Repare Building";
				 this->repareBuildingName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // shieldBuildingName
				 // 
				 this->shieldBuildingName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->shieldBuildingName->AutoSize = true;
				 this->shieldBuildingName->Location = System::Drawing::Point(3, 190);
				 this->shieldBuildingName->Name = L"shieldBuildingName";
				 this->shieldBuildingName->Size = System::Drawing::Size(106, 38);
				 this->shieldBuildingName->TabIndex = 5;
				 this->shieldBuildingName->Text = L"Shield Building";
				 this->shieldBuildingName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // energyBuildingName
				 // 
				 this->energyBuildingName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->energyBuildingName->AutoSize = true;
				 this->energyBuildingName->Location = System::Drawing::Point(3, 228);
				 this->energyBuildingName->Name = L"energyBuildingName";
				 this->energyBuildingName->Size = System::Drawing::Size(106, 40);
				 this->energyBuildingName->TabIndex = 6;
				 this->energyBuildingName->Text = L"Energy Building";
				 this->energyBuildingName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // QGValue
				 // 
				 this->QGValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->QGValue->AutoSize = true;
				 this->QGValue->Location = System::Drawing::Point(115, 0);
				 this->QGValue->Name = L"QGValue";
				 this->QGValue->Size = System::Drawing::Size(61, 38);
				 this->QGValue->TabIndex = 7;
				 this->QGValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // sniperTowerValue
				 // 
				 this->sniperTowerValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->sniperTowerValue->AutoSize = true;
				 this->sniperTowerValue->Location = System::Drawing::Point(115, 38);
				 this->sniperTowerValue->Name = L"sniperTowerValue";
				 this->sniperTowerValue->Size = System::Drawing::Size(61, 38);
				 this->sniperTowerValue->TabIndex = 8;
				 this->sniperTowerValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // lanceflammeValue
				 // 
				 this->lanceflammeValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->lanceflammeValue->AutoSize = true;
				 this->lanceflammeValue->Location = System::Drawing::Point(115, 76);
				 this->lanceflammeValue->Name = L"lanceflammeValue";
				 this->lanceflammeValue->Size = System::Drawing::Size(61, 38);
				 this->lanceflammeValue->TabIndex = 9;
				 this->lanceflammeValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // mitrailleuseValue
				 // 
				 this->mitrailleuseValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->mitrailleuseValue->AutoSize = true;
				 this->mitrailleuseValue->Location = System::Drawing::Point(115, 114);
				 this->mitrailleuseValue->Name = L"mitrailleuseValue";
				 this->mitrailleuseValue->Size = System::Drawing::Size(61, 38);
				 this->mitrailleuseValue->TabIndex = 10;
				 this->mitrailleuseValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // repareBuildingValue
				 // 
				 this->repareBuildingValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->repareBuildingValue->AutoSize = true;
				 this->repareBuildingValue->Location = System::Drawing::Point(115, 152);
				 this->repareBuildingValue->Name = L"repareBuildingValue";
				 this->repareBuildingValue->Size = System::Drawing::Size(61, 38);
				 this->repareBuildingValue->TabIndex = 11;
				 this->repareBuildingValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // shieldBuildingValue
				 // 
				 this->shieldBuildingValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->shieldBuildingValue->AutoSize = true;
				 this->shieldBuildingValue->Location = System::Drawing::Point(115, 190);
				 this->shieldBuildingValue->Name = L"shieldBuildingValue";
				 this->shieldBuildingValue->Size = System::Drawing::Size(61, 38);
				 this->shieldBuildingValue->TabIndex = 12;
				 this->shieldBuildingValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // energyBuildingValue
				 // 
				 this->energyBuildingValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->energyBuildingValue->AutoSize = true;
				 this->energyBuildingValue->Location = System::Drawing::Point(115, 228);
				 this->energyBuildingValue->Name = L"energyBuildingValue";
				 this->energyBuildingValue->Size = System::Drawing::Size(61, 40);
				 this->energyBuildingValue->TabIndex = 13;
				 this->energyBuildingValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // saveLoad
				 // 
				 this->saveLoad->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->saveLoad->ColumnCount = 2;
				 this->saveLoad->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
				 this->saveLoad->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
				 this->saveLoad->Controls->Add(this->load, 1, 0);
				 this->saveLoad->Controls->Add(this->save, 0, 0);
				 this->saveLoad->Location = System::Drawing::Point(4, 3);
				 this->saveLoad->Name = L"saveLoad";
				 this->saveLoad->RowCount = 1;
				 this->saveLoad->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->saveLoad->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 43)));
				 this->saveLoad->Size = System::Drawing::Size(397, 43);
				 this->saveLoad->TabIndex = 1;
				 // 
				 // load
				 // 
				 this->load->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->load->AutoSize = true;
				 this->load->Location = System::Drawing::Point(201, 3);
				 this->load->Name = L"load";
				 this->load->Size = System::Drawing::Size(193, 37);
				 this->load->TabIndex = 2;
				 this->load->Text = L"Load";
				 this->load->UseVisualStyleBackColor = true;
				 this->load->Click += gcnew System::EventHandler(this, &UIForm::loadClick);
				 // 
				 // save
				 // 
				 this->save->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->save->AutoSize = true;
				 this->save->Location = System::Drawing::Point(3, 3);
				 this->save->Name = L"save";
				 this->save->Size = System::Drawing::Size(192, 37);
				 this->save->TabIndex = 1;
				 this->save->Text = L"Save";
				 this->save->UseVisualStyleBackColor = true;
				 this->save->Click += gcnew System::EventHandler(this, &UIForm::saveClick);
				 // 
				 // timer
				 // 
				 this->timer->Enabled = true;
				 this->timer->Interval = 10;
				 this->timer->Tick += gcnew System::EventHandler(this, &UIForm::timer_Tick);
				 // 
				 // menu
				 // 
				 this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->buildingsMenuItem, this->unitsMenu });
				 this->menu->Location = System::Drawing::Point(0, 0);
				 this->menu->Name = L"menu";
				 this->menu->Size = System::Drawing::Size(873, 24);
				 this->menu->TabIndex = 1;
				 this->menu->Text = L"menuStrip2";
				 // 
				 // buildingsMenuItem
				 // 
				 this->buildingsMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
					 this->QGMenuItem,
						 this->sniperTowerMenuItem, this->lanceFlammeMenuItem, this->mitrailleuseMenuItem, this->repareBuildingMenuItem, this->shieldBuildingMenuItem,
						 this->energyBuildingMenuItem
				 });
				 this->buildingsMenuItem->Name = L"buildingsMenuItem";
				 this->buildingsMenuItem->Size = System::Drawing::Size(68, 20);
				 this->buildingsMenuItem->Text = L"Buildings";
				 // 
				 // QGMenuItem
				 // 
				 this->QGMenuItem->Name = L"QGMenuItem";
				 this->QGMenuItem->Size = System::Drawing::Size(154, 22);
				 this->QGMenuItem->Text = L"QG";
				 this->QGMenuItem->Click += gcnew System::EventHandler(this, &UIForm::QGClick);
				 // 
				 // sniperTowerMenuItem
				 // 
				 this->sniperTowerMenuItem->Name = L"sniperTowerMenuItem";
				 this->sniperTowerMenuItem->Size = System::Drawing::Size(154, 22);
				 this->sniperTowerMenuItem->Text = L"SniperTower";
				 this->sniperTowerMenuItem->Click += gcnew System::EventHandler(this, &UIForm::sniperTowerClick);
				 // 
				 // lanceFlammeMenuItem
				 // 
				 this->lanceFlammeMenuItem->Name = L"lanceFlammeMenuItem";
				 this->lanceFlammeMenuItem->Size = System::Drawing::Size(154, 22);
				 this->lanceFlammeMenuItem->Text = L"Lance Flamme";
				 this->lanceFlammeMenuItem->Click += gcnew System::EventHandler(this, &UIForm::lanceFlammeClick);
				 // 
				 // mitrailleuseMenuItem
				 // 
				 this->mitrailleuseMenuItem->Name = L"mitrailleuseMenuItem";
				 this->mitrailleuseMenuItem->Size = System::Drawing::Size(154, 22);
				 this->mitrailleuseMenuItem->Text = L"Mitrailleuse";
				 this->mitrailleuseMenuItem->Click += gcnew System::EventHandler(this, &UIForm::mitrailleuseClick);
				 // 
				 // repareBuildingMenuItem
				 // 
				 this->repareBuildingMenuItem->Name = L"repareBuildingMenuItem";
				 this->repareBuildingMenuItem->Size = System::Drawing::Size(154, 22);
				 this->repareBuildingMenuItem->Text = L"RepareBuilding";
				 this->repareBuildingMenuItem->Click += gcnew System::EventHandler(this, &UIForm::repareBuildingClick);
				 // 
				 // shieldBuildingMenuItem
				 // 
				 this->shieldBuildingMenuItem->Name = L"shieldBuildingMenuItem";
				 this->shieldBuildingMenuItem->Size = System::Drawing::Size(154, 22);
				 this->shieldBuildingMenuItem->Text = L"ShieldBuilding";
				 this->shieldBuildingMenuItem->Click += gcnew System::EventHandler(this, &UIForm::shieldBuildingClick);
				 // 
				 // energyBuildingMenuItem
				 // 
				 this->energyBuildingMenuItem->Name = L"energyBuildingMenuItem";
				 this->energyBuildingMenuItem->Size = System::Drawing::Size(154, 22);
				 this->energyBuildingMenuItem->Text = L"EnergyBuilding";
				 this->energyBuildingMenuItem->Click += gcnew System::EventHandler(this, &UIForm::energyBuildingClick);
				 // 
				 // unitsMenu
				 // 
				 this->unitsMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
					 this->bruteMenuItem,
						 this->kamikazeMenuItem, this->fusilleurMenuItem, this->sniperMenuItem, this->bazookaMenuItem, this->medecinContactMenuItem, this->medecinSeringueMenuItem,
						 this->medecinZoneMenuItem
				 });
				 this->unitsMenu->Name = L"unitsMenu";
				 this->unitsMenu->Size = System::Drawing::Size(46, 20);
				 this->unitsMenu->Text = L"Units";
				 // 
				 // bruteMenuItem
				 // 
				 this->bruteMenuItem->Name = L"bruteMenuItem";
				 this->bruteMenuItem->Size = System::Drawing::Size(168, 22);
				 this->bruteMenuItem->Text = L"Brute";
				 this->bruteMenuItem->Click += gcnew System::EventHandler(this, &UIForm::bruteClick);
				 // 
				 // kamikazeMenuItem
				 // 
				 this->kamikazeMenuItem->Name = L"kamikazeMenuItem";
				 this->kamikazeMenuItem->Size = System::Drawing::Size(168, 22);
				 this->kamikazeMenuItem->Text = L"Kamikaze";
				 this->kamikazeMenuItem->Click += gcnew System::EventHandler(this, &UIForm::kamikazeClick);
				 // 
				 // fusilleurMenuItem
				 // 
				 this->fusilleurMenuItem->Name = L"fusilleurMenuItem";
				 this->fusilleurMenuItem->Size = System::Drawing::Size(168, 22);
				 this->fusilleurMenuItem->Text = L"Fusilleur";
				 this->fusilleurMenuItem->Click += gcnew System::EventHandler(this, &UIForm::fusilleurClick);
				 // 
				 // sniperMenuItem
				 // 
				 this->sniperMenuItem->Name = L"sniperMenuItem";
				 this->sniperMenuItem->Size = System::Drawing::Size(168, 22);
				 this->sniperMenuItem->Text = L"Sniper";
				 this->sniperMenuItem->Click += gcnew System::EventHandler(this, &UIForm::sniperClick);
				 // 
				 // bazookaMenuItem
				 // 
				 this->bazookaMenuItem->Name = L"bazookaMenuItem";
				 this->bazookaMenuItem->Size = System::Drawing::Size(168, 22);
				 this->bazookaMenuItem->Text = L"Bazooka";
				 this->bazookaMenuItem->Click += gcnew System::EventHandler(this, &UIForm::bazookaClick);
				 // 
				 // medecinContactMenuItem
				 // 
				 this->medecinContactMenuItem->Name = L"medecinContactMenuItem";
				 this->medecinContactMenuItem->Size = System::Drawing::Size(168, 22);
				 this->medecinContactMenuItem->Text = L"Medecin contact";
				 this->medecinContactMenuItem->Click += gcnew System::EventHandler(this, &UIForm::medecinContactClick);
				 // 
				 // medecinSeringueMenuItem
				 // 
				 this->medecinSeringueMenuItem->Name = L"medecinSeringueMenuItem";
				 this->medecinSeringueMenuItem->Size = System::Drawing::Size(168, 22);
				 this->medecinSeringueMenuItem->Text = L"Medecin seringue";
				 this->medecinSeringueMenuItem->Click += gcnew System::EventHandler(this, &UIForm::medecinSeringueClick);
				 // 
				 // medecinZoneMenuItem
				 // 
				 this->medecinZoneMenuItem->Name = L"medecinZoneMenuItem";
				 this->medecinZoneMenuItem->Size = System::Drawing::Size(168, 22);
				 this->medecinZoneMenuItem->Text = L"Medecin zone";
				 this->medecinZoneMenuItem->Click += gcnew System::EventHandler(this, &UIForm::medecinZoneClick);
				 // 
				 // UIForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
				 this->ClientSize = System::Drawing::Size(873, 421);
				 this->Controls->Add(this->splitContainer1);
				 this->Controls->Add(this->menu);
				 this->Name = L"UIForm";
				 this->Resize += gcnew System::EventHandler(this, &UIForm::UIForm_Resize);
				 this->splitContainer1->Panel1->ResumeLayout(false);
				 this->splitContainer1->Panel2->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
				 this->splitContainer1->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
				 this->splitContainer2->Panel1->ResumeLayout(false);
				 this->splitContainer2->Panel2->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
				 this->splitContainer2->ResumeLayout(false);
				 this->visualisationValuesGame->ResumeLayout(false);
				 this->money->ResumeLayout(false);
				 this->money->PerformLayout();
				 this->buildingsUnits->ResumeLayout(false);
				 this->unitsBox->ResumeLayout(false);
				 this->layoutUnits->ResumeLayout(false);
				 this->layoutUnits->PerformLayout();
				 this->buildingsBox->ResumeLayout(false);
				 this->layoutBuildings->ResumeLayout(false);
				 this->layoutBuildings->PerformLayout();
				 this->saveLoad->ResumeLayout(false);
				 this->saveLoad->PerformLayout();
				 this->menu->ResumeLayout(false);
				 this->menu->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void UIForm_Resize(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->ResizeGLScene(pictureBox->Width, pictureBox->Height);
	}

	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		UNREFERENCED_PARAMETER(sender);
		UNREFERENCED_PARAMETER(e);
		this->armyMoney->Text = "Army Money : " + OpenGL->GetArmyMoney();
		this->baseMoney->Text = "Base Money : " + OpenGL->GetBaseMoney();

		this->bruteValue->Text = OpenGL->GetUnitInstances(0) + "/" + OpenGL->GetUnitMax(0);
		this->kamikazeValue->Text = OpenGL->GetUnitInstances(1) + "/" + OpenGL->GetUnitMax(1);
		this->fusilleurValue->Text = OpenGL->GetUnitInstances(2) + "/" + OpenGL->GetUnitMax(2);
		this->sniperValue->Text = OpenGL->GetUnitInstances(3) + "/" + OpenGL->GetUnitMax(3);
		this->bazookaValue->Text = OpenGL->GetUnitInstances(4) + "/" + OpenGL->GetUnitMax(4);
		this->medecinContactValue->Text = OpenGL->GetUnitInstances(5) + "/" + OpenGL->GetUnitMax(5);
		this->medecinSeringueValue->Text = OpenGL->GetUnitInstances(6) + "/" + OpenGL->GetUnitMax(6);
		this->medecinZoneValue->Text = OpenGL->GetUnitInstances(7) + "/" + OpenGL->GetUnitMax(7);


		this->QGValue->Text = OpenGL->GetBuildingInstances(0) +  "/" + OpenGL->GetBuildingMax(0);
		this->sniperTowerValue->Text = OpenGL->GetBuildingInstances(1) + "/" + OpenGL->GetBuildingMax(1);
		this->lanceflammeValue->Text = OpenGL->GetBuildingInstances(2) + "/" + OpenGL->GetBuildingMax(2);
		this->mitrailleuseValue->Text = OpenGL->GetBuildingInstances(3) + "/" + OpenGL->GetBuildingMax(3);
		this->repareBuildingValue->Text = OpenGL->GetBuildingInstances(4) + "/" + OpenGL->GetBuildingMax(4);
		this->shieldBuildingValue->Text = OpenGL->GetBuildingInstances(5) + "/" + OpenGL->GetBuildingMax(5);
		this->energyBuildingValue->Text = OpenGL->GetBuildingInstances(6) + "/" + OpenGL->GetBuildingMax(6);

		OpenGL->Render();
		OpenGL->SwapOpenGLBuffers();
	}

	private: System::Void saveClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->SaveBase();
	}

	private: System::Void loadClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->LoadBase();
	}

	// BUILDINGS CREATION
	private: System::Void QGClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processBuildingMenu(0);
	}
	private: System::Void sniperTowerClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processBuildingMenu(1);
	}
	private: System::Void lanceFlammeClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processBuildingMenu(2);
	}
	private: System::Void mitrailleuseClick(System::Object^  sender, System::EventArgs^  e)
	{
		OpenGL->processBuildingMenu(3);
	}
	private: System::Void repareBuildingClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processBuildingMenu(4);
	}
	private: System::Void shieldBuildingClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processBuildingMenu(5);
	}
	private: System::Void energyBuildingClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processBuildingMenu(6);
	}

	// UNITS CREATION
	private: System::Void bruteClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processUnitsMenu(0);
	}
	private: System::Void kamikazeClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processUnitsMenu(1);
	}
	private: System::Void fusilleurClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processUnitsMenu(2);
	}
	private: System::Void sniperClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processUnitsMenu(3);
	}
	private: System::Void bazookaClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processUnitsMenu(4);
	}
	private: System::Void medecinContactClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processUnitsMenu(5);
	}
	private: System::Void medecinSeringueClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processUnitsMenu(6);
	}
	private: System::Void medecinZoneClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processUnitsMenu(7);
	}
};
}

