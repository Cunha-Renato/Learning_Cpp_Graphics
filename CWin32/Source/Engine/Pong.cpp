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
    m_Player.setRect(60, (m_Canvas.getHeight()/2 - 60.0f), 15.0f, 120.0f);

    m_Ball.setEEllipse(m_Canvas.getWidth()/2, m_Canvas.getHeight()/2, 15, 15);
    m_Speed_X = 10;
    m_Speed_Y = 10;
}

void Pong::ballColision()
{
    float ballX = m_Ball.getOrigin().x;
    float ballY = m_Ball.getOrigin().y;

    //Colision with the walls
    //
    if(ballY + m_Ball.getEllipse().radiusY >= m_Canvas.getHeight() || ballY - m_Ball.getEllipse().radiusY <= m_Canvas.getOrigin().y)
        m_Speed_Y *= -1; 
    
    else if(ballX - m_Ball.getEllipse().radiusX <= m_Canvas.getOrigin().x || ballX + m_Ball.getEllipse().radiusX >= m_Canvas.getWidth())
    {
        //TODO: Score a point.
        // init();
        m_Speed_X *= -1;
    }

    P2D_F point(m_Ball.getXOrigin() - m_Ball.getRadius(), m_Ball.getYOrigin() - m_Ball.getRadius()); 
    
    if(m_Player.colided(point))
        m_Speed_X *= -1;
}

void Pong::update() 
{
    if(m_Move)
    {
        if(m_MoveUp)
            m_Player.move(90, m_Player_Speed);
        else if(!m_MoveUp)
            m_Player.move(270, m_Player_Speed);

        if(m_Player.getRect().top <= m_Canvas.getRect().top)
            m_Player.setOrigin(m_Player.getXOrigin(), m_Canvas.getRect().top);    
            
        else if(m_Player.getRect().bottom >= m_Canvas.getRect().bottom)
            m_Player.setOrigin(m_Player.getXOrigin(), m_Canvas.getRect().bottom - m_Player.getHeight());
    }

    m_Ball.setOrigin(m_Ball.getXOrigin() - m_Speed_X, m_Ball.getYOrigin() + m_Speed_Y);

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
    if(keyCode == 'W' || keyCode == 'S' || keyCode == VK_SPACE)
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

            if(keyCode == VK_SPACE)
                m_Player_Speed = 20;
        }
        else if(keyCode != VK_SPACE)
            m_Move = false;

        else
            m_Player_Speed = 10;
    }
}