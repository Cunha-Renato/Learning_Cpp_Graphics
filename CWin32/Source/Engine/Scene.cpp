#include "..\..\Headers\Engine\Scene.h"
#include "..\..\Headers\Engine\Window.h"
#include "..\..\Headers\Engine\SceneManager.h"
#include <iostream>

Graphics* Scene::m_Graphics;
Window* Scene::m_Window;
SceneManager* Scene::m_SM;

void Scene::setSceneManager(SceneManager *sm)
{
    m_SM = std::move(sm);
}

void Scene::setGraphics(Graphics *gfx)
{
    m_Graphics = std::move(gfx);
}

void Scene::setWindow(Window *window)
{
    m_Window = std::move(window);
}
