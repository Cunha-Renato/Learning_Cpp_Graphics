#include <windows.h>
#include <iostream>

#include "..\Headers\Engine.h"
#include "..\Headers\Geometry.h"

int main()
{
    Window window(L"Window", L"WindowTitle");

    Pong pong;
    pong.setWindow(&window);
    window.setActiveScene(&pong);

    window.run();

    return 0;
}