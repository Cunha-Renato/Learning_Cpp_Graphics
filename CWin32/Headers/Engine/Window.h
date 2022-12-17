#pragma once

#include <windows.h>
#include "Graphics.h"
#include "Scenes.h"

class Window
{
    private:
        //Variables
        static WNDCLASSW m_Window_Class;
        static HWND m_Window_Handle;
        static HINSTANCE m_Instance;
        static LPCWSTR m_Name;
        static LPCWSTR m_Title;
        static Scene *m_Scene;
        static Graphics *m_Window_Graphics;

        //Private Functions
        static void createWindowObj();
        static void MainLoop();
        static void regWindow();
        static LRESULT CALLBACK windowProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam);

    public:
        Window(LPCWSTR class_name, LPCWSTR title);
        ~Window() {};

        //Sets the active scene to the given scene.
        //The previous pointer will NOT be deleted.
        static void setActiveScene(Scene *scn);

        static void run();
};