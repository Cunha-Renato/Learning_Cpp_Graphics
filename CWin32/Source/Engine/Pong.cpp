#include "..\..\Headers\Engine\Pong.h"


#define DEBUG 1
#if DEBUG == 1

#include <iostream>
#include <string>
#include <sstream>
#define LOGSTR(x) std::cout<<(x)<<std::endl

#else
#define LOGSTR(x)
#endif

Pong::Pong() : Scene::Scene() {}

Pong::~Pong(){}

void Pong::init()
{
    m_Canvas.setRect(m_Graphics->getRect()); 
    m_Player.setRect(20, 0, 15.0f, 120.0f);

    m_Ball.setEEllipse(m_Canvas.getWidth()/2, m_Canvas.getHeight()/2, 15, 15);
}

void Pong::ballColision()
{
    float ballX = m_Ball.getOrigin().x;
    float ballY = m_Ball.getOrigin().y;

    if(ballY + m_Ball.getEllipse().radiusY >= m_Canvas.getHeight() || ballY - m_Ball.getEllipse().radiusY <= m_Canvas.getOrigin().y)
        m_Angle = 360 - m_Angle; 
    
    else if(ballX - m_Ball.getEllipse().radiusX <= m_Canvas.getOrigin().x || ballX + m_Ball.getEllipse().radiusX >= m_Canvas.getWidth())
        m_Angle = 180 - m_Angle;
}

void Pong::update() 
{
    if(m_Move)
    {
        if(m_MoveUp)
            m_Player.move(90, 10);
        else if(!m_MoveUp)
            m_Player.move(270, 10);

        if(m_Player.getRect().top <= m_Canvas.getRect().top)
            m_Player.setOrigin(m_Player.getXOrigin(), m_Canvas.getRect().top);    
            
        else if(m_Player.getRect().bottom >= m_Canvas.getRect().bottom)
            m_Player.setOrigin(m_Player.getXOrigin(), m_Canvas.getRect().bottom - m_Player.getHeight());
    }

    m_Ball.move(m_Angle, 10);

    ballColision();
}

void Pong::render() 
{
    m_Graphics->beginDraw();

    m_Graphics->paintBackground(0.20f, 0.20f, 0.20f);
    m_Player.draw(m_Graphics);
    m_Ball.draw(m_Graphics);

    m_Graphics->endDraw();
}

void Pong::input(bool wasDown, bool isDown, long keyCode)
{

    if(keyCode == 'W' || keyCode == 'S')
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
}