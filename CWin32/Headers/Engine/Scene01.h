#pragma once

#include "Scene.h"

class Scene01 : public Scene
{
    private:
        RECT* m_Rect = nullptr;
        RECT player = {0};

    public:
        Scene01();
        ~Scene01(){}
        void update();
        void render();
};