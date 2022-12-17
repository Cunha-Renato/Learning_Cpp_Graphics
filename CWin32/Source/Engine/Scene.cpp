#include "..\..\Headers\Engine\Scene.h"
#include <iostream>

Graphics* Scene::m_Graphics;

void Scene::setGraphics(Graphics *gfx)
{
    m_Graphics = std::move(gfx);
}
