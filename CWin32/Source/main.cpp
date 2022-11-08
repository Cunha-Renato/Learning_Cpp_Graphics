#include <windows.h>
#include <iostream>

#include "..\Headers\Window.h"

int CALLBACK WinMain(HINSTANCE instance, HINSTANCE prev_instance, LPSTR cmd_line, int show_Code)
{
    Window window(instance, L"Window", L"WindowTitle");

    Scene *s = new Scene01;
    window.setActiveScene(s);

    window.run();

    delete s;
    return 0;
}