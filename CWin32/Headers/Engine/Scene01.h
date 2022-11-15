#pragma once

#include "Scene.h"
#include "..\Geometry.h"

class Scene01 : public Scene
{
    private:
        bool m_Move = false;
        bool m_MoveUp = false;
        float m_Angle = 0;
        Rect m_Rect;
        Rect m_Player;
        D2D1_ELLIPSE m_Ball = {0};

    public:
        Scene01();
        ~Scene01();
        void init();
        void update();
        void render();
        void input(bool wasDown, bool isDown, long keyCode);
};