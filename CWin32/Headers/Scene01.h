#pragma once
#include "Scene.h"

class Scene01 : public Scene
{
    private:
        RECT* m_Rect = nullptr;

    public:
        void update();
        void render(); 

        static int test() {return m_Instances+1;}
};