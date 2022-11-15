#include "..\..\Headers\Geometry\EObject.h"
#include <iostream>

void EObject::setOrigin(float x, float y)
{
    m_Origin->x = x;
    m_Origin->y = y;

    update();
}
void EObject::setOrigin(const P2D_F &src_p2d)
{
    *m_Origin = src_p2d;

    update();
}
void EObject::setOrigin(P2D_F &&src_p2d)
{
    *m_Origin = std::move(src_p2d);

    update();
}

void EObject::moveX(float val)
{
    m_Origin->x+=val;

    update();
}
void EObject::moveY(float val)
{
    m_Origin->y+=val;

    update();
}