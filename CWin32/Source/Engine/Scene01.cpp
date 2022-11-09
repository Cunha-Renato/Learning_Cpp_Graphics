#include "..\..\Headers\Engine\Scene01.h"

#define DEBUG 1
#if DEBUG == 1

#include <iostream>
#include <string>
#include <sstream>
#define LOGSTR(x) std::cout<<(x)<<std::endl

#else
#define LOGSTR(x)
#endif

Scene01::Scene01() : Scene::Scene()
{ 
    m_Rect = m_Graphics->getRect(); 
}

void Scene01::update() {}
void Scene01::render() 
{
    m_Graphics->beginDraw();

    m_Graphics->paintBackground(0.20f, 0.20f, 0.20f);
    m_Graphics->drawLine(10.0f, 10.0f, 400.0f, 400.0f);

    m_Graphics->endDraw();
}
