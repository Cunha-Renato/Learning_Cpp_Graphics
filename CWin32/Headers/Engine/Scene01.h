#pragma once

#include "Scene.h"
#include "..\Geometry.h"

class Scene01 : public Scene
{
    private:
        bool m_Move = false;
        bool m_MoveUp = false;
        RECT* m_Rect = nullptr;
        Rect m_Player;

    public:
        Scene01();
        ~Scene01();
        void init();
        void update();
        void render();
        void input(bool wasDown, bool isDown, long keyCode);
};