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
    if(m_Move)
    {
        if(m_MoveUp)
            m_Player.moveY(-10);
        else if(!m_MoveUp)
            m_Player.moveY(10);

        if(m_Player.getRect().top <= m_Rect->top)
            m_Player.setOrigin(m_Player.getXOrigin(), (float)m_Rect->top);    
        else if(m_Player.getRect().bottom >= m_Rect->bottom)
            m_Player.setOrigin(m_Player.getXOrigin(), m_Rect->bottom-m_Player.getHeight());
    }
}

void Scene01::render() 
{
    m_Graphics->beginDraw();

    m_Graphics->paintBackground(0.20f, 0.20f, 0.20f);
    m_Graphics->fillRect(m_Player.getRect());

    m_Graphics->endDraw();
}

void Scene01::input(bool wasDown, bool isDown, long keyCode)
{
    if(isDown)
    {
        if(keyCode == 'W')
        {
            m_Move = true;
            m_MoveUp = true;
        }
        
        else if(keyCode == 'S')
        {
            m_Move = true;
            m_MoveUp = false;
        }
    }
    else
        m_Move = false;
}