#pragma once

#include "Graphics.h"
// #include "Window.h"

class Scene
{
    protected:
        //Keeps the number of instances of this class.
        static int m_Instances;
        static bool m_Has_Graphics;
        static Graphics *m_Graphics;

    public:
        Scene();
        virtual ~Scene();
        static void setGraphics(Graphics *gfx);
        static bool hasGraphics() {return m_Has_Graphics;}

        virtual void init() = 0;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void input(bool wasDown, bool isDown, long keyCode) = 0;

        static int test() {return m_Instances;}
};