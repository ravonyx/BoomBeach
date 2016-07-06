#pragma once

#include <windows.h>
#using <mscorlib.dll> 
#using <System.dll> 
#using <System.Windows.Forms.dll> 
#include "Draw.h"

using namespace System::Windows::Forms;

namespace OpenGLForm
{
	public ref class COpenGL: public System::Windows::Forms::Panel
	{
	public:
		COpenGL(System::Windows::Forms::PictureBox ^ parentForm, GLsizei iWidth, GLsizei iHeight)
		{
			this->Cursor = System::Windows::Forms::Cursors::Cross;
			//this->Cursor->Hide();
			this->Location = System::Drawing::Point(20, 20);

			//this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(keyboard);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(mouse);
			this->MouseEnter += gcnew System::EventHandler(this, &COpenGL::mouseEnter);
			this->MouseLeave += gcnew System::EventHandler(this, &COpenGL::mouseLeave);
			//this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(mouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(mouseMotion);
			//this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(mouseWheel);

			// Specify the form as the parent.
			this->Parent = parentForm;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			this->CreateParams->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if (m_hDC)
			{
				MySetPixelFormat(m_hDC);
				ResizeGLScene(iWidth, iHeight);
				InitGL();
			}
			else 
				MessageBox::Show("Can not get HDC");
		}

		bool InitGL(GLvoid)										
		{
			glClearColor(1.0f, 1.0f, 1.0f, 0.0f);	
			Initialize();			
			return TRUE;										
		}

		GLvoid ResizeGLScene(GLsizei width, GLsizei height)
		{		
			if (height == 0)
				height = 1;

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

			glViewport(0, 0, width, height);
			glMatrixMode(GL_MODELVIEW);

			UINT flags = SWP_NOZORDER | SWP_NOACTIVATE;
			SetWindowPos((HWND)this->Handle.ToPointer(), 0, 0, 0,
				width, height, flags);

			SetDimensionMap(width, height);
		}

		virtual System::Void Render(System::Void)
		{
			//Clear screen
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			//Set view and zoom
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

			DrawRender();
		}		

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}

		void processBuildingMenu(int nbBuilding)
		{
			add_building(nbBuilding);
		}
		void processUnitsMenu(int nbUnits)
		{
			add_unit(nbUnits);
		}

		void  SaveBase() 
		{
			save_callback();
		}
		void  LoadBase()
		{
			load_callback();
		}

		int GetArmyMoney()
		{
			return get_army_money();
		}
		int GetBaseMoney()
		{
			return get_base_money();
		}

		void mouseEnter(System::Object^  sender, System::EventArgs^  e)
		{
			Cursor->Hide();
		}
		void mouseLeave(System::Object^  sender, System::EventArgs^  e)
		{
			Cursor->Show();

		}
	private:
		HDC m_hDC;
		HGLRC m_hglrc;

	protected:
		~COpenGL(System::Void)
		{
			this->DestroyHandle();
		}

		GLint MySetPixelFormat(HDC hdc)
		{
			PIXELFORMATDESCRIPTOR pfd = { 
				sizeof(PIXELFORMATDESCRIPTOR),    // size of this pfd 
				1,                                // version number 
				PFD_DRAW_TO_WINDOW |              // support window 
				PFD_SUPPORT_OPENGL |              // support OpenGL 
				PFD_DOUBLEBUFFER,                 // double buffered 
				PFD_TYPE_RGBA,                    // RGBA type 
				24,                               // 24-bit color depth 
				0, 0, 0, 0, 0, 0,                 // color bits ignored 
				0,                                // no alpha buffer 
				0,                                // shift bit ignored 
				0,                                // no accumulation buffer 
				0, 0, 0, 0,                       // accum bits ignored 
				32,                               // 32-bit z-buffer     
				0,                                // no stencil buffer 
				0,                                // no auxiliary buffer 
				PFD_MAIN_PLANE,                   // main layer 
				0,                                // reserved 
				0, 0, 0                           // layer masks ignored 
			}; 
			
			GLint  iPixelFormat; 
		 
			// get the device context's best, available pixel format match 
			if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}
			 
			// make that match the device context's current pixel format 
			if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}
			
			if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}


			return 1;
		}
	};
}