#include "..\..\Headers\Engine\Scene.h"
#include "..\..\Headers\Engine\Window.h"
#include <iostream>

Graphics* Scene::m_Graphics;
Window* Scene::m_Window;

void Scene::setGraphics(Graphics *gfx)
{
    m_Graphics = std::move(gfx);
}

void Scene::setWindow(Window *window)
{
    m_Window = std::move(window);
}
