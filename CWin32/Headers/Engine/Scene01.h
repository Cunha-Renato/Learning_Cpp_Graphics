#pragma once

#include "Scene.h"
#include "..\Geometry.h"

class Scene01 : public Scene
{
    private:
        bool m_Up = false;
        RECT* m_Rect = nullptr;
        Rect m_Player;

    public:
        Scene01();
        ~Scene01();
        void init();
        void update();
        void render();
};