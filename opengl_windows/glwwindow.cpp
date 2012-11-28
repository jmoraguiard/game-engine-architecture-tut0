#include "glwwindow.h"

GLWindow::GLWindow(HINSTANCE instance_handler) {
		instance_handler_ = instance_handler;
}

bool GLWindow::create() {
		const char CLASS_NAME[]  = "Windows Window Class";

		window_class.cbSize					= sizeof(WNDCLASSEX);						// The size, in bytes, of this structure.
		window_class.style					= CS_HREDRAW | CS_VREDRAW;
    window_class.lpfnWndProc		= GLWindow::StaticWindowProcess;	// A pointer to an application-defined function called the window procedure or "window proc." 
		window_class.cbClsExtra			= 0;
    window_class.cbWndExtra			= 0;
    window_class.hInstance			= instance_handler_;							// A handle to the instance that contains the window procedure for the class. 
    window_class.lpszClassName	= CLASS_NAME;										// A pointer to a null-terminated string or is an atom.
		window_class.hCursor				= LoadCursor(NULL, IDC_ARROW);		// A handle to the class cursor.
		window_class.hIconSm				= LoadIcon(NULL, IDI_WINLOGO);		// A handle to a small icon that is associated with the window class.
		window_class.hIcon					= LoadIcon(NULL, IDI_APPLICATION);  // default icon
    window_class.hbrBackground	= NULL;                             // don't need background
    window_class.lpszMenuName		= NULL; 

    RegisterClassEx(&window_class); // Registers a window class with the operating system for subsequent use in calls to the CreateWindow or CreateWindowEx function.
    
    HWND window_handler = CreateWindowEx( // Creates an overlapped, pop-up, or child window with an extended window style.
        NULL,                         // Optional window styles.
        CLASS_NAME,                   // Window class
        "Learn to Program Windows",   // Window text
        WS_OVERLAPPEDWINDOW,          // Window style
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, // Size and position
        NULL,													// Parent window    
        NULL,													// Menu
        instance_handler_,						// Instance handle
        this													// Additional application data
        );

    if (window_handler == NULL)
        return false;

		ShowWindow(window_handler, SW_SHOW);
		is_running_ = true;
		
		return true;
}

void GLWindow::destroy() 
{
    // Destroy Window
}

bool GLWindow::isRunning()
{
    return is_running_;
}

void GLWindow::processEvents()
{
    MSG msg;

    //While there are messages in the queue, store them in msg
    while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
        //Process the messages one-by-one
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

void GLWindow::OnResize(HWND window_handler, UINT flag, int width, int height) {
    // Handle resizing
}

void GLWindow::setupPixelFormat(void) {
    int pixelFormat;

    PIXELFORMATDESCRIPTOR pfd =
    {   
        sizeof(PIXELFORMATDESCRIPTOR),  // size
            1,                          // version
            PFD_SUPPORT_OPENGL |        // OpenGL window
            PFD_DRAW_TO_WINDOW |        // render to window
            PFD_DOUBLEBUFFER,           // support double-buffering
            PFD_TYPE_RGBA,              // color type
            32,                         // prefered color depth
            0, 0, 0, 0, 0, 0,           // color bits (ignored)
            0,                          // no alpha buffer
            0,                          // alpha bits (ignored)
            0,                          // no accumulation buffer
            0, 0, 0, 0,                 // accum bits (ignored)
            16,                         // depth buffer
            0,                          // no stencil buffer
            0,                          // no auxiliary buffers
            PFD_MAIN_PLANE,             // main layer
            0,                          // reserved
            0, 0, 0,                    // no layer, visible, damage masks
    };

    pixelFormat = ChoosePixelFormat(device_context_handler_, &pfd);
    SetPixelFormat(device_context_handler_, pixelFormat, &pfd);
}


LRESULT GLWindow::WindowProcess(HWND window_handler, UINT message_code, WPARAM w_additional_data, LPARAM l_additional_data) {
    switch (message_code) {
				case WM_CREATE:
				{
						device_context_handler_ = GetDC(window_handler);
						setupPixelFormat();

						//Set the version that we want, in this case 3.0
						int attribs[] = {
							WGL_CONTEXT_MAJOR_VERSION_ARB, 3,
							WGL_CONTEXT_MINOR_VERSION_ARB, 0,
						0}; //zero indicates the end of the array

						//Create temporary context so we can get a pointer to the function
						HGLRC tmpContext = wglCreateContext(m_hdc);
						//Make it current
						wglMakeCurrent(m_hdc, tmpContext);
				}
				break;
				case WM_CLOSE:
				{
						if (MessageBox(window_handler, "Really quit?", "My application", MB_OKCANCEL) == IDOK)
								DestroyWindow(window_handler);
						else
								return 0;
				}
				break;
				case WM_DESTROY:
				{
						is_running_ = false;
						PostQuitMessage(0);
						return 0;
				}
				break;
				case WM_PAINT:
				{
						PAINTSTRUCT ps;
						HDC hdc = BeginPaint(window_handler, &ps);

						FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

						EndPaint(window_handler, &ps);
				}
				break;
				case WM_SIZE:
				{
						int width = LOWORD(l_additional_data);  // Macro to get the low-order word.
            int height = HIWORD(l_additional_data); // Macro to get the high-order word.

            // Respond to the message:
            OnResize(window_handler, (UINT)w_additional_data, width, height);
				}
				break;
				case WM_KEYDOWN:
					if (w_additional_data == VK_ESCAPE) //If the escape key was pressed
					{
							if (MessageBox(window_handler, "Really quit?", "My application", MB_OKCANCEL) == IDOK)
									DestroyWindow(window_handler);
							else
									return 0;
					}
				default:
					break;
    }

    return DefWindowProc(window_handler, message_code, w_additional_data, l_additional_data);
}

LRESULT GLWindow::StaticWindowProcess(HWND window_handler, UINT message_code, WPARAM w_additional_data, LPARAM l_additional_data) {
		GLWindow* window = NULL;

    //If this is the create message
    switch(message_code) {
				case WM_CREATE:
				{
						//Get the pointer we stored during create
						window = (GLWindow*)((LPCREATESTRUCT)l_additional_data)->lpCreateParams;

						//Associate the window pointer with the hwnd for the other events to access
						SetWindowLongPtr(window_handler, GWL_USERDATA, (LONG_PTR)window);
				}
				break;
				default:
				{
						//If this is not a creation event, then we should have stored a pointer to the window
						window = (GLWindow*)GetWindowLongPtr(window_handler, GWL_USERDATA);

						if(!window) 
						{
								return DefWindowProc(window_handler, message_code, w_additional_data, l_additional_data);    
						}
				}
		}

    //Call our window's member WndProc (allows us to access member variables)
		return window->WindowProcess(window_handler, message_code, w_additional_data, l_additional_data);
}
