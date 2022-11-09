#include <windows.h>
#include <iostream>

#include "..\Headers\Engine.h"
#include "..\Headers\Geometry.h"

// int CALLBACK WinMain(HINSTANCE instance, HINSTANCE prev_instance, LPSTR cmd_line, int show_Code)
// {
//     // Window window(instance, L"Window", L"WindowTitle");

//     // Scene01 s;
//     // window.setActiveScene(&s);

//     // window.run();

//     return 0;
// }

int main()
{
    //TODO: Revise P2D_F class
    Rect r1(1,1,10, 10);

    Rect r2(r1.test(), 3, 2);
    
    return 0;
}