#pragma once

#include "Scene.h"
#include "..\Geometry.h"

class Pong : public Scene
{
    private:
        bool m_Move = false;
        bool m_MoveUp = false;
        float m_Speed_X = 10;
        float m_Speed_Y = 10;
        float m_Player_Speed = 10;
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