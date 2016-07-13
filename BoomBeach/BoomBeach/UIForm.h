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
	private: int counterValue;
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
	private: System::Windows::Forms::TabControl^  tabController;
	private: System::Windows::Forms::TabPage^  generalPage;
	private: System::Windows::Forms::TabPage^  buildingsPage;
	private: System::Windows::Forms::TabPage^  unitsPage;
private: System::Windows::Forms::TableLayoutPanel^  panelBuildings;
private: System::Windows::Forms::TableLayoutPanel^  panelUnits;

private: System::Windows::Forms::Label^  counterText;






	private: System::Windows::Forms::Timer^  timer;
private: System::Windows::Forms::Button^  combatButton;
	private: System::Windows::Forms::Timer^  counter;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
				 this->counterText = (gcnew System::Windows::Forms::Label());
				 this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
				 this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
				 this->tabController = (gcnew System::Windows::Forms::TabControl());
				 this->generalPage = (gcnew System::Windows::Forms::TabPage());
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
				 this->buildingsPage = (gcnew System::Windows::Forms::TabPage());
				 this->panelBuildings = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->unitsPage = (gcnew System::Windows::Forms::TabPage());
				 this->panelUnits = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->saveLoad = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->load = (gcnew System::Windows::Forms::Button());
				 this->save = (gcnew System::Windows::Forms::Button());
				 this->combatButton = (gcnew System::Windows::Forms::Button());
				 this->timer = (gcnew System::Windows::Forms::Timer(this->components));
				 this->counter = (gcnew System::Windows::Forms::Timer(this->components));
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
				 this->tabController->SuspendLayout();
				 this->generalPage->SuspendLayout();
				 this->visualisationValuesGame->SuspendLayout();
				 this->money->SuspendLayout();
				 this->buildingsUnits->SuspendLayout();
				 this->unitsBox->SuspendLayout();
				 this->layoutUnits->SuspendLayout();
				 this->buildingsBox->SuspendLayout();
				 this->layoutBuildings->SuspendLayout();
				 this->buildingsPage->SuspendLayout();
				 this->unitsPage->SuspendLayout();
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
				 this->splitContainer1->Size = System::Drawing::Size(971, 397);
				 this->splitContainer1->SplitterDistance = 474;
				 this->splitContainer1->TabIndex = 0;
				 // 
				 // counterText
				 // 
				 this->counterText->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->counterText->AutoSize = true;
				 this->counterText->BackColor = System::Drawing::Color::Transparent;
				 this->counterText->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->counterText->Location = System::Drawing::Point(3, 0);
				 this->counterText->Name = L"counterText";
				 this->counterText->Size = System::Drawing::Size(114, 43);
				 this->counterText->TabIndex = 1;
				 this->counterText->Text = L"0 seconds";
				 this->counterText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // pictureBox
				 // 
				 this->pictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->pictureBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				 this->pictureBox->Location = System::Drawing::Point(3, 3);
				 this->pictureBox->Name = L"pictureBox";
				 this->pictureBox->Size = System::Drawing::Size(468, 391);
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
				 this->splitContainer2->Panel1->Controls->Add(this->tabController);
				 // 
				 // splitContainer2.Panel2
				 // 
				 this->splitContainer2->Panel2->Controls->Add(this->saveLoad);
				 this->splitContainer2->Size = System::Drawing::Size(487, 391);
				 this->splitContainer2->SplitterDistance = 338;
				 this->splitContainer2->TabIndex = 1;
				 // 
				 // tabController
				 // 
				 this->tabController->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->tabController->Controls->Add(this->generalPage);
				 this->tabController->Controls->Add(this->buildingsPage);
				 this->tabController->Controls->Add(this->unitsPage);
				 this->tabController->Location = System::Drawing::Point(4, 4);
				 this->tabController->Multiline = true;
				 this->tabController->Name = L"tabController";
				 this->tabController->SelectedIndex = 0;
				 this->tabController->Size = System::Drawing::Size(480, 331);
				 this->tabController->TabIndex = 0;
				 this->tabController->Selected += gcnew System::Windows::Forms::TabControlEventHandler(this, &UIForm::tabSelected);
				 // 
				 // generalPage
				 // 
				 this->generalPage->Controls->Add(this->visualisationValuesGame);
				 this->generalPage->Location = System::Drawing::Point(4, 22);
				 this->generalPage->Name = L"generalPage";
				 this->generalPage->Padding = System::Windows::Forms::Padding(3);
				 this->generalPage->Size = System::Drawing::Size(472, 305);
				 this->generalPage->TabIndex = 0;
				 this->generalPage->Text = L"General";
				 this->generalPage->UseVisualStyleBackColor = true;
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
				 this->visualisationValuesGame->Location = System::Drawing::Point(0, 0);
				 this->visualisationValuesGame->Name = L"visualisationValuesGame";
				 this->visualisationValuesGame->RowCount = 2;
				 this->visualisationValuesGame->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
					 8.421053F)));
				 this->visualisationValuesGame->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
					 91.57895F)));
				 this->visualisationValuesGame->Size = System::Drawing::Size(472, 305);
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
				 this->money->Size = System::Drawing::Size(466, 19);
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
				 this->baseMoney->Size = System::Drawing::Size(227, 19);
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
				 this->armyMoney->Location = System::Drawing::Point(236, 0);
				 this->armyMoney->Name = L"armyMoney";
				 this->armyMoney->Size = System::Drawing::Size(227, 19);
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
				 this->buildingsUnits->Location = System::Drawing::Point(3, 28);
				 this->buildingsUnits->Name = L"buildingsUnits";
				 this->buildingsUnits->RowCount = 1;
				 this->buildingsUnits->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				 this->buildingsUnits->Size = System::Drawing::Size(466, 274);
				 this->buildingsUnits->TabIndex = 2;
				 // 
				 // unitsBox
				 // 
				 this->unitsBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->unitsBox->Controls->Add(this->layoutUnits);
				 this->unitsBox->Location = System::Drawing::Point(236, 3);
				 this->unitsBox->Name = L"unitsBox";
				 this->unitsBox->Size = System::Drawing::Size(227, 268);
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
				 this->layoutUnits->Size = System::Drawing::Size(215, 243);
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
				 this->bruteName->Size = System::Drawing::Size(132, 30);
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
				 this->bruteValue->Location = System::Drawing::Point(141, 0);
				 this->bruteValue->Name = L"bruteValue";
				 this->bruteValue->Size = System::Drawing::Size(71, 30);
				 this->bruteValue->TabIndex = 1;
				 this->bruteValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // kamikazeName
				 // 
				 this->kamikazeName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->kamikazeName->AutoSize = true;
				 this->kamikazeName->Location = System::Drawing::Point(3, 30);
				 this->kamikazeName->Name = L"kamikazeName";
				 this->kamikazeName->Size = System::Drawing::Size(132, 30);
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
				 this->fusilleurName->Location = System::Drawing::Point(3, 60);
				 this->fusilleurName->Name = L"fusilleurName";
				 this->fusilleurName->Size = System::Drawing::Size(132, 30);
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
				 this->kamikazeValue->Location = System::Drawing::Point(141, 30);
				 this->kamikazeValue->Name = L"kamikazeValue";
				 this->kamikazeValue->Size = System::Drawing::Size(71, 30);
				 this->kamikazeValue->TabIndex = 4;
				 this->kamikazeValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // sniperName
				 // 
				 this->sniperName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->sniperName->AutoSize = true;
				 this->sniperName->Location = System::Drawing::Point(3, 90);
				 this->sniperName->Name = L"sniperName";
				 this->sniperName->Size = System::Drawing::Size(132, 30);
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
				 this->bazookaName->Location = System::Drawing::Point(3, 120);
				 this->bazookaName->Name = L"bazookaName";
				 this->bazookaName->Size = System::Drawing::Size(132, 30);
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
				 this->medecinContactName->Location = System::Drawing::Point(3, 150);
				 this->medecinContactName->Name = L"medecinContactName";
				 this->medecinContactName->Size = System::Drawing::Size(132, 30);
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
				 this->medecinSeringueName->Location = System::Drawing::Point(3, 180);
				 this->medecinSeringueName->Name = L"medecinSeringueName";
				 this->medecinSeringueName->Size = System::Drawing::Size(132, 30);
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
				 this->medecinZoneName->Location = System::Drawing::Point(3, 210);
				 this->medecinZoneName->Name = L"medecinZoneName";
				 this->medecinZoneName->Size = System::Drawing::Size(132, 33);
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
				 this->fusilleurValue->Location = System::Drawing::Point(141, 60);
				 this->fusilleurValue->Name = L"fusilleurValue";
				 this->fusilleurValue->Size = System::Drawing::Size(71, 30);
				 this->fusilleurValue->TabIndex = 10;
				 this->fusilleurValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // sniperValue
				 // 
				 this->sniperValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->sniperValue->AutoSize = true;
				 this->sniperValue->Location = System::Drawing::Point(141, 90);
				 this->sniperValue->Name = L"sniperValue";
				 this->sniperValue->Size = System::Drawing::Size(71, 30);
				 this->sniperValue->TabIndex = 11;
				 this->sniperValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // bazookaValue
				 // 
				 this->bazookaValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->bazookaValue->AutoSize = true;
				 this->bazookaValue->Location = System::Drawing::Point(141, 120);
				 this->bazookaValue->Name = L"bazookaValue";
				 this->bazookaValue->Size = System::Drawing::Size(71, 30);
				 this->bazookaValue->TabIndex = 12;
				 this->bazookaValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // medecinContactValue
				 // 
				 this->medecinContactValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->medecinContactValue->AutoSize = true;
				 this->medecinContactValue->Location = System::Drawing::Point(141, 150);
				 this->medecinContactValue->Name = L"medecinContactValue";
				 this->medecinContactValue->Size = System::Drawing::Size(71, 30);
				 this->medecinContactValue->TabIndex = 13;
				 this->medecinContactValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // medecinSeringueValue
				 // 
				 this->medecinSeringueValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->medecinSeringueValue->AutoSize = true;
				 this->medecinSeringueValue->Location = System::Drawing::Point(141, 180);
				 this->medecinSeringueValue->Name = L"medecinSeringueValue";
				 this->medecinSeringueValue->Size = System::Drawing::Size(71, 30);
				 this->medecinSeringueValue->TabIndex = 14;
				 this->medecinSeringueValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // medecinZoneValue
				 // 
				 this->medecinZoneValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->medecinZoneValue->AutoSize = true;
				 this->medecinZoneValue->Location = System::Drawing::Point(141, 210);
				 this->medecinZoneValue->Name = L"medecinZoneValue";
				 this->medecinZoneValue->Size = System::Drawing::Size(71, 33);
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
				 this->buildingsBox->Size = System::Drawing::Size(227, 268);
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
				 this->layoutBuildings->Size = System::Drawing::Size(215, 243);
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
				 this->QGName->Size = System::Drawing::Size(129, 34);
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
				 this->sniperTowerName->Location = System::Drawing::Point(3, 34);
				 this->sniperTowerName->Name = L"sniperTowerName";
				 this->sniperTowerName->Size = System::Drawing::Size(129, 34);
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
				 this->lanceflammeName->Location = System::Drawing::Point(3, 68);
				 this->lanceflammeName->Name = L"lanceflammeName";
				 this->lanceflammeName->Size = System::Drawing::Size(129, 34);
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
				 this->mitrailleuseName->Location = System::Drawing::Point(3, 102);
				 this->mitrailleuseName->Name = L"mitrailleuseName";
				 this->mitrailleuseName->Size = System::Drawing::Size(129, 34);
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
				 this->repareBuildingName->Location = System::Drawing::Point(3, 136);
				 this->repareBuildingName->Name = L"repareBuildingName";
				 this->repareBuildingName->Size = System::Drawing::Size(129, 34);
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
				 this->shieldBuildingName->Location = System::Drawing::Point(3, 170);
				 this->shieldBuildingName->Name = L"shieldBuildingName";
				 this->shieldBuildingName->Size = System::Drawing::Size(129, 34);
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
				 this->energyBuildingName->Location = System::Drawing::Point(3, 204);
				 this->energyBuildingName->Name = L"energyBuildingName";
				 this->energyBuildingName->Size = System::Drawing::Size(129, 39);
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
				 this->QGValue->Location = System::Drawing::Point(138, 0);
				 this->QGValue->Name = L"QGValue";
				 this->QGValue->Size = System::Drawing::Size(74, 34);
				 this->QGValue->TabIndex = 7;
				 this->QGValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // sniperTowerValue
				 // 
				 this->sniperTowerValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->sniperTowerValue->AutoSize = true;
				 this->sniperTowerValue->Location = System::Drawing::Point(138, 34);
				 this->sniperTowerValue->Name = L"sniperTowerValue";
				 this->sniperTowerValue->Size = System::Drawing::Size(74, 34);
				 this->sniperTowerValue->TabIndex = 8;
				 this->sniperTowerValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // lanceflammeValue
				 // 
				 this->lanceflammeValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->lanceflammeValue->AutoSize = true;
				 this->lanceflammeValue->Location = System::Drawing::Point(138, 68);
				 this->lanceflammeValue->Name = L"lanceflammeValue";
				 this->lanceflammeValue->Size = System::Drawing::Size(74, 34);
				 this->lanceflammeValue->TabIndex = 9;
				 this->lanceflammeValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // mitrailleuseValue
				 // 
				 this->mitrailleuseValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->mitrailleuseValue->AutoSize = true;
				 this->mitrailleuseValue->Location = System::Drawing::Point(138, 102);
				 this->mitrailleuseValue->Name = L"mitrailleuseValue";
				 this->mitrailleuseValue->Size = System::Drawing::Size(74, 34);
				 this->mitrailleuseValue->TabIndex = 10;
				 this->mitrailleuseValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // repareBuildingValue
				 // 
				 this->repareBuildingValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->repareBuildingValue->AutoSize = true;
				 this->repareBuildingValue->Location = System::Drawing::Point(138, 136);
				 this->repareBuildingValue->Name = L"repareBuildingValue";
				 this->repareBuildingValue->Size = System::Drawing::Size(74, 34);
				 this->repareBuildingValue->TabIndex = 11;
				 this->repareBuildingValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // shieldBuildingValue
				 // 
				 this->shieldBuildingValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->shieldBuildingValue->AutoSize = true;
				 this->shieldBuildingValue->Location = System::Drawing::Point(138, 170);
				 this->shieldBuildingValue->Name = L"shieldBuildingValue";
				 this->shieldBuildingValue->Size = System::Drawing::Size(74, 34);
				 this->shieldBuildingValue->TabIndex = 12;
				 this->shieldBuildingValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // energyBuildingValue
				 // 
				 this->energyBuildingValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->energyBuildingValue->AutoSize = true;
				 this->energyBuildingValue->Location = System::Drawing::Point(138, 204);
				 this->energyBuildingValue->Name = L"energyBuildingValue";
				 this->energyBuildingValue->Size = System::Drawing::Size(74, 39);
				 this->energyBuildingValue->TabIndex = 13;
				 this->energyBuildingValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // buildingsPage
				 // 
				 this->buildingsPage->Controls->Add(this->panelBuildings);
				 this->buildingsPage->Location = System::Drawing::Point(4, 22);
				 this->buildingsPage->Name = L"buildingsPage";
				 this->buildingsPage->Padding = System::Windows::Forms::Padding(3);
				 this->buildingsPage->Size = System::Drawing::Size(472, 305);
				 this->buildingsPage->TabIndex = 1;
				 this->buildingsPage->Text = L"Buildings";
				 this->buildingsPage->UseVisualStyleBackColor = true;
				 // 
				 // panelBuildings
				 // 
				 this->panelBuildings->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->panelBuildings->AutoScroll = true;
				 this->panelBuildings->ColumnCount = 5;
				 this->panelBuildings->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 25)));
				 this->panelBuildings->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 15)));
				 this->panelBuildings->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 20)));
				 this->panelBuildings->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 20)));
				 this->panelBuildings->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 20)));
				 this->panelBuildings->Location = System::Drawing::Point(3, 3);
				 this->panelBuildings->Name = L"panelBuildings";
				 this->panelBuildings->RowCount = 1;
				 this->panelBuildings->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->panelBuildings->Size = System::Drawing::Size(466, 299);
				 this->panelBuildings->TabIndex = 0;
				 // 
				 // unitsPage
				 // 
				 this->unitsPage->Controls->Add(this->panelUnits);
				 this->unitsPage->Location = System::Drawing::Point(4, 22);
				 this->unitsPage->Name = L"unitsPage";
				 this->unitsPage->Size = System::Drawing::Size(472, 305);
				 this->unitsPage->TabIndex = 2;
				 this->unitsPage->Text = L"Units";
				 this->unitsPage->UseVisualStyleBackColor = true;
				 // 
				 // panelUnits
				 // 
				 this->panelUnits->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->panelUnits->AutoScroll = true;
				 this->panelUnits->ColumnCount = 5;
				 this->panelUnits->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 26.04167F)));
				 this->panelUnits->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 15.625F)));
				 this->panelUnits->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 20.83333F)));
				 this->panelUnits->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 20.83333F)));
				 this->panelUnits->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
				 this->panelUnits->Location = System::Drawing::Point(3, 3);
				 this->panelUnits->Name = L"panelUnits";
				 this->panelUnits->RowCount = 1;
				 this->panelUnits->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->panelUnits->Size = System::Drawing::Size(466, 299);
				 this->panelUnits->TabIndex = 0;
				 // 
				 // saveLoad
				 // 
				 this->saveLoad->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->saveLoad->ColumnCount = 4;
				 this->saveLoad->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25)));
				 this->saveLoad->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25)));
				 this->saveLoad->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25)));
				 this->saveLoad->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25)));
				 this->saveLoad->Controls->Add(this->load, 2, 0);
				 this->saveLoad->Controls->Add(this->save, 3, 0);
				 this->saveLoad->Controls->Add(this->combatButton, 1, 0);
				 this->saveLoad->Controls->Add(this->counterText, 0, 0);
				 this->saveLoad->Location = System::Drawing::Point(4, 3);
				 this->saveLoad->Name = L"saveLoad";
				 this->saveLoad->RowCount = 1;
				 this->saveLoad->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->saveLoad->Size = System::Drawing::Size(480, 43);
				 this->saveLoad->TabIndex = 1;
				 // 
				 // load
				 // 
				 this->load->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->load->AutoSize = true;
				 this->load->Location = System::Drawing::Point(243, 3);
				 this->load->Name = L"load";
				 this->load->Size = System::Drawing::Size(114, 37);
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
				 this->save->Location = System::Drawing::Point(363, 3);
				 this->save->Name = L"save";
				 this->save->Size = System::Drawing::Size(114, 37);
				 this->save->TabIndex = 1;
				 this->save->Text = L"Save";
				 this->save->UseVisualStyleBackColor = true;
				 this->save->Click += gcnew System::EventHandler(this, &UIForm::saveClick);
				 // 
				 // combatButton
				 // 
				 this->combatButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->combatButton->Location = System::Drawing::Point(123, 3);
				 this->combatButton->Name = L"combatButton";
				 this->combatButton->Size = System::Drawing::Size(114, 37);
				 this->combatButton->TabIndex = 3;
				 this->combatButton->Text = L"Combat";
				 this->combatButton->UseVisualStyleBackColor = true;
				 this->combatButton->Click += gcnew System::EventHandler(this, &UIForm::combatButton_Click);
				 // 
				 // timer
				 // 
				 this->timer->Enabled = true;
				 this->timer->Interval = 10;
				 this->timer->Tick += gcnew System::EventHandler(this, &UIForm::timer_Tick);
				 // 
				 // counter
				 // 
				 this->counter->Interval = 1000;
				 this->counter->Tick += gcnew System::EventHandler(this, &UIForm::counter_Tick);
				 // 
				 // menu
				 // 
				 this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->buildingsMenuItem, this->unitsMenu });
				 this->menu->Location = System::Drawing::Point(0, 0);
				 this->menu->Name = L"menu";
				 this->menu->Size = System::Drawing::Size(971, 24);
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
				 this->ClientSize = System::Drawing::Size(971, 421);
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
				 this->tabController->ResumeLayout(false);
				 this->generalPage->ResumeLayout(false);
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
				 this->buildingsPage->ResumeLayout(false);
				 this->unitsPage->ResumeLayout(false);
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

	private: System::Void combatButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->counter->Enabled = true;
		this->counter->Start();
		counterValue = 60;
	}

	private: System::Void counter_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		UNREFERENCED_PARAMETER(sender);
		UNREFERENCED_PARAMETER(e);

		counterValue--;
		if (counterValue == 0)
			this->counter->Stop();
		std::cout << counterValue << std::endl;
		this->counterText->Text = counterValue + " seconds";
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

	private: System::Void enhanceBuilding(System::Object^  sender, System::EventArgs^  e)
	{
		System::Windows::Forms::Control^ controller = (System::Windows::Forms::Control^) sender;
		
		int row = (controller->Location.Y - 3) / 30;
		std::cout << "row number " << row << std::endl;

		OpenGL->EnhanceBuilding(row + 1);
		fillDataBuilding();
	}

	private: System::Void deleteBuilding(System::Object^  sender, System::EventArgs^  e)
	{
		System::Windows::Forms::Control^ controller = (System::Windows::Forms::Control^) sender;

		int row = (controller->Location.Y - 3) / 30;
		OpenGL->DeleteBuilding(row + 1);
		fillDataBuilding();
	}

	private: System::Void enhanceUnit(System::Object^  sender, System::EventArgs^  e)
	{
		System::Windows::Forms::Control^ controller = (System::Windows::Forms::Control^) sender;

		int row = (controller->Location.Y - 3) / 30;
		OpenGL->EnhanceUnit(row + 1);
		fillDataUnit();
	}

	private: System::Void deleteUnit(System::Object^  sender, System::EventArgs^  e)
	{
		System::Windows::Forms::Control^ controller = (System::Windows::Forms::Control^) sender;

		int row = (controller->Location.Y - 3) / 30;
		OpenGL->DeleteUnit(row + 1);
		fillDataUnit();
	}

	private: System::Void tabSelected(System::Object^ sender, System::Windows::Forms::TabControlEventArgs^ e)
	{
		fillDataBuilding();
		fillDataUnit();
	}

	private: System::Void fillDataBuilding()
	{
		std::vector<Building*> buildings = OpenGL->GetBuildings();

		Type^ myType = System::Windows::Forms::Control::typeid;
		System::Reflection::PropertyInfo^ controlProperty = myType->GetProperty("DoubleBuffered", System::Reflection::BindingFlags::NonPublic | System::Reflection::BindingFlags::Instance);
		controlProperty->SetValue(panelBuildings, true, nullptr);
		//Clear all the controls
		panelBuildings->Controls->Clear();
		panelBuildings->RowStyles->Clear();
		//Set the new count
		panelBuildings->RowCount = buildings.size() + 1;

		for (int i = 0; i < buildings.size(); i++)
		{
			panelBuildings->RowStyles->Add(gcnew RowStyle(System::Windows::Forms::SizeType::Absolute, 30));

			System::Windows::Forms::Label^ nameBuilding = (gcnew System::Windows::Forms::Label());
			nameBuilding->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			nameBuilding->AutoSize = true;
			nameBuilding->TabIndex = 0;
			String^ str = gcnew String(buildings[i]->getName().c_str());
			nameBuilding->Text = str;
			nameBuilding->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			System::Windows::Forms::Label^ levelBuilding = (gcnew System::Windows::Forms::Label());
			levelBuilding->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			levelBuilding->AutoSize = true;
			levelBuilding->TabIndex = 1;
			str = gcnew String(buildings[i]->getLevel().ToString());
			levelBuilding->Text = str;
			levelBuilding->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			System::Windows::Forms::Label^ lifeBuilding = (gcnew System::Windows::Forms::Label());
			lifeBuilding->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			lifeBuilding->AutoSize = true;
			lifeBuilding->TabIndex = 2;
			str = gcnew String(buildings[i]->getLife().ToString());
			lifeBuilding->Text = str;
			lifeBuilding->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			System::Windows::Forms::Button^ enhanceButton = (gcnew System::Windows::Forms::Button());
			enhanceButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			enhanceButton->AutoSize = true;
			enhanceButton->TabIndex = 3;
			enhanceButton->Text = "Enhance";
			enhanceButton->Click += gcnew System::EventHandler(this, &UIForm::enhanceBuilding);

			System::Windows::Forms::Button^ deleteButton = (gcnew System::Windows::Forms::Button());
			deleteButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			deleteButton->AutoSize = true;
			deleteButton->TabIndex = 4;
			deleteButton->Text = "Delete";
			deleteButton->Click += gcnew System::EventHandler(this, &UIForm::deleteBuilding);

			panelBuildings->Controls->Add(nameBuilding, 0, i);
			panelBuildings->Controls->Add(levelBuilding, 1, i);
			panelBuildings->Controls->Add(lifeBuilding, 2, i);
			panelBuildings->Controls->Add(enhanceButton, 3, i);
			panelBuildings->Controls->Add(deleteButton, 4, i);
		}
	}

	private: System::Void fillDataUnit()
	{
		std::vector<Unit*> units = OpenGL->GetUnits();

		Type^ myType = System::Windows::Forms::Control::typeid;
		System::Reflection::PropertyInfo^ controlProperty = myType->GetProperty("DoubleBuffered", System::Reflection::BindingFlags::NonPublic | System::Reflection::BindingFlags::Instance);
		controlProperty->SetValue(panelUnits, true, nullptr);
		//Clear all the controls
		panelUnits->Controls->Clear();
		panelUnits->RowStyles->Clear();
		//Set the new count
		panelUnits->RowCount = units.size() + 1;

		for (int i = 0; i < units.size(); i++)
		{
			panelUnits->RowStyles->Add(gcnew RowStyle(System::Windows::Forms::SizeType::Absolute, 30));

			System::Windows::Forms::Label^ nameUnit = (gcnew System::Windows::Forms::Label());
			nameUnit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			nameUnit->AutoSize = true;
			nameUnit->TabIndex = 0;
			String^ str = gcnew String(units[i]->getName().c_str());
			nameUnit->Text = str;
			nameUnit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			System::Windows::Forms::Label^ levelUnit = (gcnew System::Windows::Forms::Label());
			levelUnit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			levelUnit->AutoSize = true;
			levelUnit->TabIndex = 1;
			str = gcnew String(units[i]->getLevel().ToString());
			levelUnit->Text = str;
			levelUnit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			System::Windows::Forms::Label^ lifeUnit = (gcnew System::Windows::Forms::Label());
			lifeUnit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			lifeUnit->AutoSize = true;
			lifeUnit->TabIndex = 2;
			str = gcnew String(units[i]->getLife().ToString());
			lifeUnit->Text = str;
			lifeUnit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

			System::Windows::Forms::Button^ enhanceButton = (gcnew System::Windows::Forms::Button());
			enhanceButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			enhanceButton->AutoSize = true;
			enhanceButton->TabIndex = 3;
			enhanceButton->Text = "Enhance";
			enhanceButton->Click += gcnew System::EventHandler(this, &UIForm::enhanceUnit);

			System::Windows::Forms::Button^ deleteButton = (gcnew System::Windows::Forms::Button());
			deleteButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			deleteButton->AutoSize = true;
			deleteButton->TabIndex = 4;
			deleteButton->Text = "Delete";
			deleteButton->Click += gcnew System::EventHandler(this, &UIForm::deleteUnit);

			panelUnits->Controls->Add(nameUnit, 0, i);
			panelUnits->Controls->Add(levelUnit, 1, i);
			panelUnits->Controls->Add(lifeUnit, 2, i);
			panelUnits->Controls->Add(enhanceButton, 3, i);
			panelUnits->Controls->Add(deleteButton, 4, i);
		}
	}

};
}

