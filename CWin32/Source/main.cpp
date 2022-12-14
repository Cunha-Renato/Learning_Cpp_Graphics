#include <windows.h>
#include <iostream>

#include "..\Headers\Engine.h"
#include "..\Headers\Geometry.h"

int main()
{
    Window window(L"Window", L"WindowTitle");

    Scene01 s;
    window.setActiveScene(&s);

    window.run();

    return 0;
}