#include "..\Headers\Geometry\EEllipse.h"
#include "..\Headers\Engine\Graphics.h"

EEllipse::EEllipse(float x, float y, float radiusX, float radiusY)
{
    m_Origin.x = x;
    m_Origin.y = y;

    m_Ellipse.point.x = x;
    m_Ellipse.point.y = y;
    m_Ellipse.radiusX = radiusX;
    m_Ellipse.radiusY = radiusY;
}
EEllipse::EEllipse(const EEllipse &src_ellipse)
{
    m_Origin = src_ellipse.m_Origin;

    m_Ellipse.point.x = src_ellipse.m_Origin.x;
    m_Ellipse.point.y = src_ellipse.m_Origin.y;
    m_Ellipse.radiusX = src_ellipse.m_Ellipse.radiusX;
    m_Ellipse.radiusY = src_ellipse.m_Ellipse.radiusY;
}
EEllipse::EEllipse(const P2D_F &origin, float radiusX, float radiusY)
{
    m_Origin = origin;

    m_Ellipse.point.x = origin.x;
    m_Ellipse.point.y = origin.y;
    m_Ellipse.radiusX = radiusX;
    m_Ellipse.radiusY = radiusY;
}

void EEllipse::setEEllipse(float x, float y, float radiusX, float radiusY)
{
    m_Origin.x = x;
    m_Origin.y = y;

    m_Ellipse.point.x = x;
    m_Ellipse.point.y = y;
    m_Ellipse.radiusX = radiusX;
    m_Ellipse.radiusY = radiusY;
}

void EEllipse::update()
{
    m_Ellipse.point.x = m_Origin.x;
    m_Ellipse.point.y = m_Origin.y;
}

void EEllipse::draw(Graphics *gfx)
{
    gfx->fillEllipse(&this->m_Ellipse);
}