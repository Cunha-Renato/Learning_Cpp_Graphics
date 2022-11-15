#include "..\..\Headers\Geometry\Rect.h"

#define DEBUG 0
#if DEBUG == 1

#include <iostream>
#define LOGSTR(x) std::cout<<(x)<<std::endl

#else
#define LOGSTR(x)
#endif

Rect::Rect(const Rect &src_rect) noexcept : EObject()
{
    m_Width = src_rect.m_Width;
    m_Height = src_rect.m_Height;

    *m_Origin = *src_rect.m_Origin;
    *m_Rect = *src_rect.m_Rect;

    LOGSTR("Copied!");
}

Rect::Rect(Rect &&src_rect) : EObject()
{
    m_Width = src_rect.m_Width;
    m_Height = src_rect.m_Height;

    m_Origin = std::move(src_rect.m_Origin);
    m_Rect = std::move(src_rect.m_Rect);

    src_rect.m_Origin = nullptr;
    src_rect.m_Rect = nullptr;

    LOGSTR("Created by rvalue!");
}

Rect::Rect(const D2D1_RECT_F &src_rect) : EObject()
{
    m_Width = abs(src_rect.right - src_rect.left);
    m_Height = abs(src_rect.bottom - src_rect.top);

    m_Origin->x = src_rect.left;
    m_Origin->y = src_rect.top;
    *m_Rect = src_rect;

    LOGSTR("Copied RECT!");
}

Rect::Rect(D2D1_RECT_F *src_rect) : EObject()
{
    m_Width = abs(src_rect->right - src_rect->left);
    m_Height = abs(src_rect->bottom - src_rect->top);

    m_Origin->x = (float)src_rect->left;
    m_Origin->y = (float)src_rect->top;

    *m_Rect = std::move(*src_rect);

    src_rect = nullptr;

    LOGSTR("Created by pointer RECT!");
}

Rect::Rect(const D2D1_RECT_F &&src_rect) : EObject()
{
    m_Width = abs(src_rect.right - src_rect.left);
    m_Height = abs(src_rect.bottom - src_rect.top);

    m_Origin->x = std::move(src_rect.left);
    m_Origin->y = std::move(src_rect.top);

    *m_Rect = std::move(src_rect);

    LOGSTR("Created by RECT rvalue!");
}

Rect::Rect(float x, float y, float width, float height) : EObject()
{
    m_Width = width;
    m_Height = height;
    
    m_Origin->x = x;
    m_Origin->y = y;
    
    m_Rect->left = x;
    m_Rect->top = y;
    m_Rect->right = (width + x);
    m_Rect->bottom = (height + y); 

    LOGSTR("Created!");
}

Rect::Rect(const P2D_F &src_p2d, float width, float height) : EObject()
{
    m_Width = width;
    m_Height = height;

    *m_Origin = src_p2d;

    m_Rect->left = m_Origin->x;
    m_Rect->top = m_Origin->y;
    m_Rect->right = (width + m_Rect->left);
    m_Rect->bottom = (height + m_Rect->right);
}

Rect::Rect(const P2D_F &&src_p2d, float width, float height) : EObject()
{
    m_Width = width;
    m_Height = height;

    *m_Origin = std::move(src_p2d);

    m_Rect->left = m_Origin->x;
    m_Rect->top = m_Origin->y;
    m_Rect->right = (width + m_Rect->left);
    m_Rect->bottom = (height + m_Rect->right);

    LOGSTR("Created by P2D_F rvalue!");
}

Rect::~Rect()
{
    if(m_Origin) delete m_Origin;
    if(m_Rect) delete m_Rect;
    
    LOGSTR("Destroyed!");
}

//Seters

void Rect::setRect(float x, float y, float width, float height)
{
    m_Width = width;
    m_Height = height;
    
    m_Origin->x = x;
    m_Origin->y = y;
    
    m_Rect->left = x;
    m_Rect->top = y;
    m_Rect->right = (width + x);
    m_Rect->bottom = (height + y);
}

void Rect::setRect(const RECT &src_rect)
{
    m_Origin->x = (float)src_rect.left;
    m_Origin->y = (float)src_rect.top;

    m_Rect->left = (float)src_rect.left;
    m_Rect->top = (float)src_rect.top;
    m_Rect->right = (float)src_rect.right;
    m_Rect->bottom = (float)src_rect.bottom;

    m_Height = abs(m_Rect->bottom - m_Rect->top);
    m_Height = abs(m_Rect->right - m_Rect->left);
}

void Rect::update()
{
    m_Rect->left = m_Origin->x;
    m_Rect->top = m_Origin->y;
    m_Rect->right = (m_Rect->left + m_Width);
    m_Rect->bottom = (m_Rect->top + m_Height);
}