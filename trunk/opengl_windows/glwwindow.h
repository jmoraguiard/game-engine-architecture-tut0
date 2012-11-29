#ifndef _GLWINDOW_H
#define _GLWINDOW_H

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include "wglext.h"

class GLWindow 
{
		public:
				GLWindow(HINSTANCE instance_handler); //default constructor
				
				bool create();
				void destroy();
				void processEvents();

				float getElapsedSeconds();
    
				bool isRunning(); //Is the window running?

				void swapBuffers();

				static LRESULT CALLBACK StaticWindowProcess(HWND window_handler, UINT message_code, WPARAM w_additional_data, LPARAM l_additional_data);
				LRESULT CALLBACK WindowProcess(HWND window_handler, UINT message_code, WPARAM w_additional_data, LPARAM l_additional_data);

		private:
				void OnResize(HWND window_handler, UINT flag, int width, int height);
				void setupPixelFormat(void);

				bool is_running_;
				float last_time_;

				HWND window_handler_;
				HDC device_context_handler_;
				HGLRC rendering_context_handler_;
				HINSTANCE instance_handler_;
				WNDCLASSEX window_class; //Contains window class information. (http://msdn.microsoft.com/en-us/library/windows/desktop/ms633577%28v=vs.85%29.aspx)
				RECT window_rectangle_; //Windows size
				DWORD window_extended_style_; //Window Extended Style
				DWORD window_style_; //Window Style
};

#endif
