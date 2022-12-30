#pragma once

#include "Scene.h"
#include "..\Geometry.h"

class EndScene : public Scene
{
    private:
        int m_Winner = 0;
        Rect m_Rect;
    
    public:
        void init();
        void update() {}
        void render();
        void input(bool wasDown, bool isDown, long keyCode) {};
};