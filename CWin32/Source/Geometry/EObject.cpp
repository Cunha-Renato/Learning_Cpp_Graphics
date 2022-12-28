#include "..\..\Headers\Geometry\EObject.h"
#include <iostream>

void EObject::setOrigin(const float &x, const float &y)
{
    m_Origin.x = x;
    m_Origin.y = y;

    update();
}
void EObject::setOrigin(const P2D_F &src_p2d)
{
    m_Origin = src_p2d;

    update();
}
void EObject::setOrigin(P2D_F &&src_p2d)
{
    m_Origin = std::move(src_p2d);

    update();
}
void EObject::setX(float val)
{
    m_Origin.x=val;

    update();
}
void EObject::setY(float val)
{
    m_Origin.y=val;

    update();
}

void EObject::move(float angle = 0.0f, float force = 0.5f)
{
    #include <math.h>

    float pi = 3.1415926f;

    if(angle == 90)
        angle = pi/2.0f;

    else if(angle == 180)
        angle = pi;
    
    else if(angle == 270)
        angle = (3.0f*pi)/2.0f;

    else
        angle = (float)(angle * (pi/180.0f));

    m_Origin.x = m_Origin.x + (cos(angle) * force);
    m_Origin.y = m_Origin.y - (sin(angle) * force);

    update();
}