#include <windows.h>
#include <iostream>

#include "..\Headers\Engine.h"
#include "..\Headers\Geometry.h"

int main()
{
    Window window(L"Window", L"WindowTitle");

    Pong pong;
    EndScene es;
    
    SceneManager sm(&window);
    sm.add(&pong);
    sm.add(&es);
    sm.setActiveScene(&pong);
 
    window.run();

    return 0;
}