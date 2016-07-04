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
				 this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
				 this->unitsBox = (gcnew System::Windows::Forms::GroupBox());
				 this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->load = (gcnew System::Windows::Forms::Button());
				 this->save = (gcnew System::Windows::Forms::Button());
				 this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
				 this->timer = (gcnew System::Windows::Forms::Timer(this->components));
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
				 this->splitContainer1->Panel1->SuspendLayout();
				 this->splitContainer1->Panel2->SuspendLayout();
				 this->splitContainer1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
				 this->splitContainer2->Panel1->SuspendLayout();
				 this->splitContainer2->Panel2->SuspendLayout();
				 this->splitContainer2->SuspendLayout();
				 this->tableLayoutPanel1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // splitContainer1
				 // 
				 this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->splitContainer1->Location = System::Drawing::Point(0, 0);
				 this->splitContainer1->Name = L"splitContainer1";
				 // 
				 // splitContainer1.Panel1
				 // 
				 this->splitContainer1->Panel1->Controls->Add(this->pictureBox);
				 // 
				 // splitContainer1.Panel2
				 // 
				 this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
				 this->splitContainer1->Size = System::Drawing::Size(889, 479);
				 this->splitContainer1->SplitterDistance = 509;
				 this->splitContainer1->TabIndex = 0;
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
				 this->splitContainer2->Panel1->Controls->Add(this->unitsBox);
				 // 
				 // splitContainer2.Panel2
				 // 
				 this->splitContainer2->Panel2->Controls->Add(this->tableLayoutPanel1);
				 this->splitContainer2->Size = System::Drawing::Size(370, 473);
				 this->splitContainer2->SplitterDistance = 411;
				 this->splitContainer2->TabIndex = 1;
				 // 
				 // unitsBox
				 // 
				 this->unitsBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->unitsBox->Location = System::Drawing::Point(7, 3);
				 this->unitsBox->Name = L"unitsBox";
				 this->unitsBox->Size = System::Drawing::Size(357, 405);
				 this->unitsBox->TabIndex = 0;
				 this->unitsBox->TabStop = false;
				 this->unitsBox->Text = L"Units";
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
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 133)));
				 this->tableLayoutPanel1->Size = System::Drawing::Size(363, 52);
				 this->tableLayoutPanel1->TabIndex = 1;
				 // 
				 // load
				 // 
				 this->load->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->load->AutoSize = true;
				 this->load->Location = System::Drawing::Point(184, 3);
				 this->load->Name = L"load";
				 this->load->Size = System::Drawing::Size(176, 46);
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
				 this->save->Size = System::Drawing::Size(175, 46);
				 this->save->TabIndex = 1;
				 this->save->Text = L"Save";
				 this->save->UseVisualStyleBackColor = true;
				 this->save->Click += gcnew System::EventHandler(this, &UIForm::saveClick);
				 // 
				 // pictureBox
				 // 
				 this->pictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->pictureBox->Location = System::Drawing::Point(3, 3);
				 this->pictureBox->Name = L"pictureBox";
				 this->pictureBox->Size = System::Drawing::Size(503, 473);
				 this->pictureBox->TabIndex = 0;
				 this->pictureBox->TabStop = false;
				 // 
				 // timer
				 // 
				 this->timer->Enabled = true;
				 this->timer->Interval = 10;
				 this->timer->Tick += gcnew System::EventHandler(this, &UIForm::timer_Tick);
				 // 
				 // UIForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
				 this->ClientSize = System::Drawing::Size(889, 479);
				 this->Controls->Add(this->splitContainer1);
				 this->Name = L"UIForm";
				 this->Resize += gcnew System::EventHandler(this, &UIForm::UIForm_Resize);
				 this->splitContainer1->Panel1->ResumeLayout(false);
				 this->splitContainer1->Panel2->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
				 this->splitContainer1->ResumeLayout(false);
				 this->splitContainer2->Panel1->ResumeLayout(false);
				 this->splitContainer2->Panel2->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
				 this->splitContainer2->ResumeLayout(false);
				 this->tableLayoutPanel1->ResumeLayout(false);
				 this->tableLayoutPanel1->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
				 this->ResumeLayout(false);

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
};
}

