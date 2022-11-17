#pragma once

#include "Scene.h"
#include "..\Geometry.h"

class Scene01 : public Scene
{
    private:
        bool m_Move = false;
        bool m_MoveUp = false;
        float m_Angle = 100;
        Rect m_Rect;
        Rect m_Player;
        EEllipse m_Ball;

        void ballColision();

    public:
        Scene01();
        ~Scene01();
        void init();
        void update();
        void render();
        void input(bool wasDown, bool isDown, long keyCode);
};