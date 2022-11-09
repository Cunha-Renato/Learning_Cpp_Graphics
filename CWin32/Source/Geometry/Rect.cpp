#include "..\..\Headers\Geometry\Rect.h"

#define DEBUG 1
#if DEBUG == 1

#include <iostream>
#define LOGSTR(x) std::cout<<(x)<<std::endl

#else
#define LOGSTR(x)
#endif

Rect::Rect(const Rect &src_rect) noexcept
{
    m_Center = src_rect.m_Center;    
    *m_Origin = *src_rect.m_Origin;
    *m_Rect = *src_rect.m_Rect;

    LOGSTR("Copied!");
}

Rect::Rect(Rect &&src_rect)
{
    m_Center = src_rect.m_Center;
    m_Origin = std::move(src_rect.m_Origin);
    m_Rect = std::move(src_rect.m_Rect);

    src_rect.m_Center = 0;
    src_rect.m_Origin = nullptr;
    src_rect.m_Rect = nullptr;

    LOGSTR("Created by rvalue!");
}

Rect::Rect(const RECT &src_rect)
{
    m_Center = 0;

    m_Origin->x = (float)src_rect.left;
    m_Origin->y =(float)src_rect.top;
    *m_Rect = src_rect;

    LOGSTR("Copied RECT!");
}

Rect::Rect(RECT *src_rect)
{
    m_Center = 0;

    m_Origin->x = (float)src_rect->left;
    m_Origin->y = (float)src_rect->top;

    *m_Rect = std::move(*src_rect);

    src_rect = nullptr;

    LOGSTR("Created by pointer RECT!");
}

Rect::Rect(const RECT &&src_rect)
{
    m_Center = 0;

    m_Origin->x = std::move((float)src_rect.left);
    m_Origin->y = std::move((float)src_rect.top);

    *m_Rect = std::move(src_rect);

    LOGSTR("Created by RECT rvalue!");
}

Rect::Rect(float x, float y, float width, float height)
{
    m_Center = 0.0f;
    
    m_Origin->x = x;
    m_Origin->y = y;
    
    m_Rect->left = (long)x;
    m_Rect->top = (long)y;
    m_Rect->right = (long)(width + x);
    m_Rect->bottom = (long)(height + y); 

    LOGSTR("Created!");
}

Rect::Rect(const P2D_F &src_p2d, float width, float height)
{
    m_Center = 0;
    *m_Origin = src_p2d;

    m_Rect->left = (long)m_Origin->x;
    m_Rect->top = (long)m_Origin->y;
    m_Rect->right = (long)(width + m_Rect->left);
    m_Rect->bottom = (long)(height + m_Rect->right);
}

Rect::Rect(const P2D_F &&src_p2d, float width, float height)
{
    m_Center = 0;
    *m_Origin = std::move(src_p2d);

    m_Rect->left = (long)m_Origin->x;
    m_Rect->top = (long)m_Origin->y;
    m_Rect->right = (long)(width + m_Rect->left);
    m_Rect->bottom = (long)(height + m_Rect->right);

    LOGSTR("Created by P2D_F rvalue!");
}

Rect::~Rect()
{
    if(m_Origin) delete m_Origin;
    if(m_Rect) delete m_Rect;
    
    LOGSTR("Destroyed!");
}