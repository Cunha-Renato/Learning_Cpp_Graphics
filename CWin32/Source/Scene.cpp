#include "..\Headers\Scene.h"

int Scene::m_Instances = 0;
bool Scene::m_Has_Graphics = false;
Graphics* Scene::m_Graphics = nullptr;

Scene::Scene()
{
    m_Instances++;
}

Scene::~Scene()
{   
    m_Instances--;

    if(m_Graphics && m_Instances == 0)
        delete m_Graphics;
}

void Scene::setGraphics(Graphics *gfx)
{
    m_Graphics = gfx;
}
