#include "..\Headers\Scene01.h"

#define DEBUG 1
#if DEBUG == 1

#include <iostream>
#include <string>
#include <sstream>
#define LOGSTR(x) std::cout<<(x)<<std::endl

#else
#define LOGSTR(x)
#endif

void Scene01::update() 
{
    m_Rect = m_Graphics->getRect();
}
void Scene01::render() 
{
    m_Graphics->beginDraw();

    m_Graphics->paintBackground(0.1f, 0.4f, 0.6f);
    m_Graphics->drawLine(10.0f, 10.0f, 400.0f, 400.0f);

    m_Graphics->endDraw();
}
