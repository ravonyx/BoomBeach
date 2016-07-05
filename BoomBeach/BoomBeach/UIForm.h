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

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  buildingsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  unitsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  qGToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sniperTowerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lanceFlammeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mitrailleusseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  repareBuildingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  shieldBuildingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  energyBuildingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bruteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  kamikazeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fusilleurToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sniperToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bazookaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  medecinContactToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  medecinSeringueToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  medecinZoneToolStripMenuItem;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Label^  baseMoney;
	private: System::Windows::Forms::Label^  armyMoney;


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
				 this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->unitsBox = (gcnew System::Windows::Forms::GroupBox());
				 this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->baseMoney = (gcnew System::Windows::Forms::Label());
				 this->armyMoney = (gcnew System::Windows::Forms::Label());
				 this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->load = (gcnew System::Windows::Forms::Button());
				 this->save = (gcnew System::Windows::Forms::Button());
				 this->timer = (gcnew System::Windows::Forms::Timer(this->components));
				 this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
				 this->buildingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->qGToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->sniperTowerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->lanceFlammeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->mitrailleusseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->repareBuildingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->shieldBuildingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->energyBuildingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->unitsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->bruteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->kamikazeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->fusilleurToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->sniperToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->bazookaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->medecinContactToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->medecinSeringueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->medecinZoneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
				 this->splitContainer1->Panel1->SuspendLayout();
				 this->splitContainer1->Panel2->SuspendLayout();
				 this->splitContainer1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
				 this->splitContainer2->Panel1->SuspendLayout();
				 this->splitContainer2->Panel2->SuspendLayout();
				 this->splitContainer2->SuspendLayout();
				 this->tableLayoutPanel2->SuspendLayout();
				 this->tableLayoutPanel3->SuspendLayout();
				 this->tableLayoutPanel1->SuspendLayout();
				 this->menuStrip2->SuspendLayout();
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
				 this->splitContainer1->Size = System::Drawing::Size(659, 342);
				 this->splitContainer1->SplitterDistance = 377;
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
				 this->pictureBox->Size = System::Drawing::Size(371, 336);
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
				 this->splitContainer2->Panel1->Controls->Add(this->tableLayoutPanel2);
				 // 
				 // splitContainer2.Panel2
				 // 
				 this->splitContainer2->Panel2->Controls->Add(this->tableLayoutPanel1);
				 this->splitContainer2->Size = System::Drawing::Size(272, 336);
				 this->splitContainer2->SplitterDistance = 291;
				 this->splitContainer2->TabIndex = 1;
				 // 
				 // tableLayoutPanel2
				 // 
				 this->tableLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->tableLayoutPanel2->ColumnCount = 1;
				 this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel2->Controls->Add(this->unitsBox, 0, 1);
				 this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 0);
				 this->tableLayoutPanel2->Location = System::Drawing::Point(0, 3);
				 this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				 this->tableLayoutPanel2->RowCount = 2;
				 this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 32.2807F)));
				 this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 67.7193F)));
				 this->tableLayoutPanel2->Size = System::Drawing::Size(269, 285);
				 this->tableLayoutPanel2->TabIndex = 0;
				 // 
				 // unitsBox
				 // 
				 this->unitsBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->unitsBox->Location = System::Drawing::Point(3, 94);
				 this->unitsBox->Name = L"unitsBox";
				 this->unitsBox->Size = System::Drawing::Size(263, 188);
				 this->unitsBox->TabIndex = 0;
				 this->unitsBox->TabStop = false;
				 this->unitsBox->Text = L"Units";
				 // 
				 // tableLayoutPanel3
				 // 
				 this->tableLayoutPanel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->tableLayoutPanel3->ColumnCount = 2;
				 this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel3->Controls->Add(this->baseMoney, 0, 0);
				 this->tableLayoutPanel3->Controls->Add(this->armyMoney, 1, 0);
				 this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
				 this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				 this->tableLayoutPanel3->RowCount = 1;
				 this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				 this->tableLayoutPanel3->Size = System::Drawing::Size(263, 85);
				 this->tableLayoutPanel3->TabIndex = 1;
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
				 this->baseMoney->Size = System::Drawing::Size(125, 85);
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
				 this->armyMoney->Location = System::Drawing::Point(134, 0);
				 this->armyMoney->Name = L"armyMoney";
				 this->armyMoney->Size = System::Drawing::Size(126, 85);
				 this->armyMoney->TabIndex = 1;
				 this->armyMoney->Text = L"Army Money :";
				 this->armyMoney->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // tableLayoutPanel1
				 // 
				 this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->tableLayoutPanel1->ColumnCount = 2;
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel1->Controls->Add(this->load, 1, 0);
				 this->tableLayoutPanel1->Controls->Add(this->save, 0, 0);
				 this->tableLayoutPanel1->Location = System::Drawing::Point(4, 3);
				 this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				 this->tableLayoutPanel1->RowCount = 1;
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
				 this->tableLayoutPanel1->Size = System::Drawing::Size(265, 35);
				 this->tableLayoutPanel1->TabIndex = 1;
				 // 
				 // load
				 // 
				 this->load->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->load->AutoSize = true;
				 this->load->Location = System::Drawing::Point(135, 3);
				 this->load->Name = L"load";
				 this->load->Size = System::Drawing::Size(127, 29);
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
				 this->save->Size = System::Drawing::Size(126, 29);
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
				 // menuStrip2
				 // 
				 this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					 this->buildingsToolStripMenuItem,
						 this->unitsToolStripMenuItem
				 });
				 this->menuStrip2->Location = System::Drawing::Point(0, 0);
				 this->menuStrip2->Name = L"menuStrip2";
				 this->menuStrip2->Size = System::Drawing::Size(659, 24);
				 this->menuStrip2->TabIndex = 1;
				 this->menuStrip2->Text = L"menuStrip2";
				 // 
				 // buildingsToolStripMenuItem
				 // 
				 this->buildingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
					 this->qGToolStripMenuItem,
						 this->sniperTowerToolStripMenuItem, this->lanceFlammeToolStripMenuItem, this->mitrailleusseToolStripMenuItem, this->repareBuildingToolStripMenuItem,
						 this->shieldBuildingToolStripMenuItem, this->energyBuildingToolStripMenuItem
				 });
				 this->buildingsToolStripMenuItem->Name = L"buildingsToolStripMenuItem";
				 this->buildingsToolStripMenuItem->Size = System::Drawing::Size(68, 20);
				 this->buildingsToolStripMenuItem->Text = L"Buildings";
				 // 
				 // qGToolStripMenuItem
				 // 
				 this->qGToolStripMenuItem->Name = L"qGToolStripMenuItem";
				 this->qGToolStripMenuItem->Size = System::Drawing::Size(154, 22);
				 this->qGToolStripMenuItem->Text = L"QG";
				 this->qGToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::QGClick);
				 // 
				 // sniperTowerToolStripMenuItem
				 // 
				 this->sniperTowerToolStripMenuItem->Name = L"sniperTowerToolStripMenuItem";
				 this->sniperTowerToolStripMenuItem->Size = System::Drawing::Size(154, 22);
				 this->sniperTowerToolStripMenuItem->Text = L"SniperTower";
				 this->sniperTowerToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::sniperTowerClick);
				 // 
				 // lanceFlammeToolStripMenuItem
				 // 
				 this->lanceFlammeToolStripMenuItem->Name = L"lanceFlammeToolStripMenuItem";
				 this->lanceFlammeToolStripMenuItem->Size = System::Drawing::Size(154, 22);
				 this->lanceFlammeToolStripMenuItem->Text = L"Lance Flamme";
				 this->lanceFlammeToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::lanceFlammeClick);
				 // 
				 // mitrailleusseToolStripMenuItem
				 // 
				 this->mitrailleusseToolStripMenuItem->Name = L"mitrailleusseToolStripMenuItem";
				 this->mitrailleusseToolStripMenuItem->Size = System::Drawing::Size(154, 22);
				 this->mitrailleusseToolStripMenuItem->Text = L"Mitrailleuse";
				 this->mitrailleusseToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::mitrailleuseClick);
				 // 
				 // repareBuildingToolStripMenuItem
				 // 
				 this->repareBuildingToolStripMenuItem->Name = L"repareBuildingToolStripMenuItem";
				 this->repareBuildingToolStripMenuItem->Size = System::Drawing::Size(154, 22);
				 this->repareBuildingToolStripMenuItem->Text = L"RepareBuilding";
				 this->repareBuildingToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::repareBuildingClick);
				 // 
				 // shieldBuildingToolStripMenuItem
				 // 
				 this->shieldBuildingToolStripMenuItem->Name = L"shieldBuildingToolStripMenuItem";
				 this->shieldBuildingToolStripMenuItem->Size = System::Drawing::Size(154, 22);
				 this->shieldBuildingToolStripMenuItem->Text = L"ShieldBuilding";
				 this->shieldBuildingToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::shieldBuildingClick);
				 // 
				 // energyBuildingToolStripMenuItem
				 // 
				 this->energyBuildingToolStripMenuItem->Name = L"energyBuildingToolStripMenuItem";
				 this->energyBuildingToolStripMenuItem->Size = System::Drawing::Size(154, 22);
				 this->energyBuildingToolStripMenuItem->Text = L"EnergyBuilding";
				 this->energyBuildingToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::energyBuildingClick);
				 // 
				 // unitsToolStripMenuItem
				 // 
				 this->unitsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
					 this->bruteToolStripMenuItem,
						 this->kamikazeToolStripMenuItem, this->fusilleurToolStripMenuItem, this->sniperToolStripMenuItem, this->bazookaToolStripMenuItem,
						 this->medecinContactToolStripMenuItem, this->medecinSeringueToolStripMenuItem, this->medecinZoneToolStripMenuItem
				 });
				 this->unitsToolStripMenuItem->Name = L"unitsToolStripMenuItem";
				 this->unitsToolStripMenuItem->Size = System::Drawing::Size(46, 20);
				 this->unitsToolStripMenuItem->Text = L"Units";
				 // 
				 // bruteToolStripMenuItem
				 // 
				 this->bruteToolStripMenuItem->Name = L"bruteToolStripMenuItem";
				 this->bruteToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->bruteToolStripMenuItem->Text = L"Brute";
				 this->bruteToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::bruteClick);
				 // 
				 // kamikazeToolStripMenuItem
				 // 
				 this->kamikazeToolStripMenuItem->Name = L"kamikazeToolStripMenuItem";
				 this->kamikazeToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->kamikazeToolStripMenuItem->Text = L"Kamikaze";
				 this->kamikazeToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::kamikazeClick);
				 // 
				 // fusilleurToolStripMenuItem
				 // 
				 this->fusilleurToolStripMenuItem->Name = L"fusilleurToolStripMenuItem";
				 this->fusilleurToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->fusilleurToolStripMenuItem->Text = L"Fusilleur";
				 this->fusilleurToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::fusilleurClick);
				 // 
				 // sniperToolStripMenuItem
				 // 
				 this->sniperToolStripMenuItem->Name = L"sniperToolStripMenuItem";
				 this->sniperToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->sniperToolStripMenuItem->Text = L"Sniper";
				 this->sniperToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::sniperClick);
				 // 
				 // bazookaToolStripMenuItem
				 // 
				 this->bazookaToolStripMenuItem->Name = L"bazookaToolStripMenuItem";
				 this->bazookaToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->bazookaToolStripMenuItem->Text = L"Bazooka";
				 this->bazookaToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::bazookaClick);
				 // 
				 // medecinContactToolStripMenuItem
				 // 
				 this->medecinContactToolStripMenuItem->Name = L"medecinContactToolStripMenuItem";
				 this->medecinContactToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->medecinContactToolStripMenuItem->Text = L"Medecin contact";
				 this->medecinContactToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::medecinContactClick);
				 // 
				 // medecinSeringueToolStripMenuItem
				 // 
				 this->medecinSeringueToolStripMenuItem->Name = L"medecinSeringueToolStripMenuItem";
				 this->medecinSeringueToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->medecinSeringueToolStripMenuItem->Text = L"Medecin seringue";
				 this->medecinSeringueToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::medecinSeringueClick);
				 // 
				 // medecinZoneToolStripMenuItem
				 // 
				 this->medecinZoneToolStripMenuItem->Name = L"medecinZoneToolStripMenuItem";
				 this->medecinZoneToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->medecinZoneToolStripMenuItem->Text = L"Medecin zone";
				 this->medecinZoneToolStripMenuItem->Click += gcnew System::EventHandler(this, &UIForm::medecinZoneClick);
				 // 
				 // UIForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
				 this->ClientSize = System::Drawing::Size(659, 366);
				 this->Controls->Add(this->splitContainer1);
				 this->Controls->Add(this->menuStrip2);
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
				 this->tableLayoutPanel2->ResumeLayout(false);
				 this->tableLayoutPanel3->ResumeLayout(false);
				 this->tableLayoutPanel3->PerformLayout();
				 this->tableLayoutPanel1->ResumeLayout(false);
				 this->tableLayoutPanel1->PerformLayout();
				 this->menuStrip2->ResumeLayout(false);
				 this->menuStrip2->PerformLayout();
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
		OpenGL->processUnitsMenu(0);
	}
	private: System::Void medecinSeringueClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processUnitsMenu(5);
	}
	private: System::Void medecinZoneClick(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenGL->processUnitsMenu(6);
	}
};
}

