#include "..\Headers\Window.h"

#define DEBUG 1
#if DEBUG == 1

#include <iostream>
#define LOGSTR(x) std::cout<<(x)<<std::endl

#else
#define LOGSTR(x)
#endif

Window::Window(HINSTANCE instance, LPCWSTR class_name, LPCWSTR title) 
{
    // LOGSTR("Constructor!");
    m_Name = class_name;
    m_Title = title;
    m_Instance = instance;

    createWindowObj();

    if(RegisterClassW(&m_Window_Class))
        regWindow();
    
}
//
//Private functions
//
//This function acts upon windows messages
LRESULT CALLBACK windowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) 
{
    LRESULT result=0;
    switch(message)
    {
        case WM_SIZE:
        {
            // LOGSTR("WM_SIZE\n");
            break;
        }

        case WM_DESTROY:    
        {
            PostQuitMessage(0);
            break;
        }

        case WM_CLOSE:
        {
            // if (MessageBoxW(window, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
            PostQuitMessage(0);
            break;
        }

        case WM_ACTIVATEAPP:
        {
            // LOGSTR("WM_ACTIVATEAPP\n");
            break;
        }

        default:
        {
            result = DefWindowProcW(window, message, wParam, lParam);
            break;
        }
    }

    return result;
}

//Note: the obj that this functions is creating is not this class, its the window_class struct
void Window::createWindowObj() 
{
    m_Window_Class.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;
    m_Window_Class.lpfnWndProc = &windowProc;
    m_Window_Class.hInstance = m_Instance;
    // window_class.hIcon=;
    m_Window_Class.lpszClassName = m_Name;
}

void Window::MainLoop() 
{
    MSG message;
    message.message = WM_NULL;

    while(message.message != WM_QUIT)
    {
        if(PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
        {
            //Handles the messages
            TranslateMessage(&message);
            DispatchMessageA(&message);
        }
        else
        {
            //Main Loop
            //Update
            m_Scene->update();

            // //Render
            m_Scene->render();
        }
    }
}

//Registers this window
void Window::regWindow()
{
    m_Window_Handle = CreateWindowExW
    (
        0,
        m_Window_Class.lpszClassName, 
        m_Title, 
        WS_OVERLAPPEDWINDOW|WS_VISIBLE, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        CW_USEDEFAULT, 
        NULL, 
        NULL, 
        m_Instance, 
        NULL
    );
}

//Public functions

void Window::setActiveScene(Scene *scn)
{
    m_Scene = scn;
    
    if(!m_Scene->hasGraphics())
        m_Scene->setGraphics(new Graphics(m_Window_Handle));
    
}

void Window::run()
{
    // LOGSTR("Run!");

    if(m_Window_Handle)
        MainLoop();
}