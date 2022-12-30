#include "..\Headers\Engine\Window.h"
#include "..\Headers\Engine\SceneManager.h"

#define DEBUG 1
#if DEBUG == 1

#include <iostream>
#define LOGSTR(x) std::cout<<(x)<<std::endl

#else
#define LOGSTR(x)
#endif

WNDCLASSW Window::m_Window_Class = {0};
HWND Window::m_Window_Handle = nullptr;
HINSTANCE Window::m_Instance = nullptr;
LPCWSTR Window::m_Name = {0};
LPCWSTR Window::m_Title = {0};
SceneManager Window::m_SM;
Graphics* Window::m_Window_Graphics = nullptr;

Window::Window(LPCWSTR class_name, LPCWSTR title) 
{
    // LOGSTR("Constructor!");
    m_Name = class_name;
    m_Title = title;
    m_Instance = GetModuleHandleW(0);
    
    createWindowObj();

    if(RegisterClassW(&m_Window_Class))
        regWindow();

    m_Window_Graphics = new Graphics(m_Window_Handle);
}
//
//Private functions
//
//This function acts upon windows messages
LRESULT CALLBACK Window::windowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam) 
{
    LRESULT result=0;
    switch(message)
    {
        case WM_SYSKEYDOWN:
        case WM_SYSKEYUP:
        case WM_KEYDOWN:
        case WM_KEYUP:
        {
            uint32_t vkCode = (uint32_t)wParam;
            bool wasDown = ((lParam & (1<<30)) != 0);
            bool isDown = ((lParam & (1<<31)) == 0);

            m_SM.runInput(wasDown, isDown, vkCode);
            
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
            m_SM.runScene();
        }
    }
}

//Public functions

void Window::run()
{
    // LOGSTR("Run!");

    if(m_Window_Handle)
        MainLoop();
}