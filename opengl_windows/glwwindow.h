#ifndef _GLWINDOW_H
#define _GLWINDOW_H

#include <windows.h>
#include <GL/gl.h>

#include "wglext.h"

class Example; //Declare our Example class

class GLWindow 
{
		public:
				GLWindow(HINSTANCE instance_handler); //default constructor
				
				bool create();
				void destroy();
				void processEvents();
				void attachExample(Example* example);
    
				bool isRunning(); //Is the window running?

				static LRESULT CALLBACK StaticWindowProcess(HWND window_handler, UINT message_code, WPARAM w_additional_data, LPARAM l_additional_data);
				LRESULT CALLBACK WindowProcess(HWND window_handler, UINT message_code, WPARAM w_additional_data, LPARAM l_additional_data);

		private:
				void OnResize(HWND window_handler, UINT flag, int width, int height);
				void setupPixelFormat(void);

				bool is_running_;

				HWND window_handler_;
				HDC device_context_handler_;
				HINSTANCE instance_handler_;
				WNDCLASSEX window_class; //Contains window class information. (http://msdn.microsoft.com/en-us/library/windows/desktop/ms633577%28v=vs.85%29.aspx)
};

#endif
