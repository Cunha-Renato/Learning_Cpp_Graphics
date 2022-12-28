#pragma once

#include "Scene.h"
#include "..\Geometry.h"

class Pong : public Scene
{
    private:
        bool m_Move[2] = {0, 0};
        bool m_MoveUp[2] = {0, 0};
        int m_Score_Points[2] = {0, 0};
        float m_Speed_X = 10;
        float m_Speed_Y = 10;
        float m_Player_Speed[2] = {10, 10};
        Rect m_Canvas;
        Rect m_Player[2];
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