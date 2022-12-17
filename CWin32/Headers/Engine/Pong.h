#pragma once

#include "Scene.h"
#include "..\Geometry.h"

class Pong : public Scene
{
    private:
        bool m_Move = false;
        bool m_MoveUp = false;
        float m_Angle = 100;
        Rect m_Canvas;
        Rect m_Player;
        EEllipse m_Ball;

        void ballColision();

    public:
        Pong();
        ~Pong();
        void init();
        void update();
        void render();
        void input(bool wasDown, bool isDown, long keyCode);
};