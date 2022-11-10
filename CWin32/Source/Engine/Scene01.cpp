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

Scene01::Scene01() : Scene::Scene() {}

Scene01::~Scene01()
{
    m_Rect = nullptr;
}

void Scene01::init()
{
    m_Rect = m_Graphics->getRect(); 

    m_Player.setRect(40.0f, 20.0f, 15.0f, 120.0f);
}

void Scene01::update() 
{
    if(m_Up)
        m_Player.setOrigin(m_Player.getOrigin().x, m_Player.getOrigin().y -10);
    
    else
        m_Player.setOrigin(m_Player.getOrigin().x, m_Player.getOrigin().y +10);

    if(m_Player.getRect().top <= m_Rect->top -5 || m_Player.getRect().bottom >= m_Rect->bottom +5)
    {
        if(m_Up)
            m_Up = false;
        else
            m_Up = true;
    }
    
}
void Scene01::render() 
{
    m_Graphics->beginDraw();

    m_Graphics->paintBackground(0.20f, 0.20f, 0.20f);
    m_Graphics->fillRect(m_Player.getRect());

    m_Graphics->endDraw();
}
