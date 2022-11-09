#pragma once

#include <windows.h>
#include "Graphics.h"
#include "Scenes.h"

class Window
{
    private:
        //Variables
        WNDCLASSW m_Window_Class = {0};
        HWND m_Window_Handle = nullptr;
        HINSTANCE m_Instance = nullptr;
        LPCWSTR m_Name = {0};
        LPCWSTR m_Title = {0};
        Scene *m_Scene = nullptr;

        //Private Functions
        void createWindowObj();
        void MainLoop();
        void regWindow();

    public:
        Window(HINSTANCE instance, LPCWSTR class_name, LPCWSTR title);
        ~Window() {};

        //Sets the active scene to the given scene.
        //The previous pointer will NOT be deleted.
        void setActiveScene(Scene *scn);

        void run();
};