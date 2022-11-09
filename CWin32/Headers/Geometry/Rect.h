#pragma once

#include <d2d1.h>
#include "P2D_F.h"

class Rect
{
    private:
        float m_Center = 0;
        P2D_F *m_Origin = nullptr;
        RECT *m_Rect = nullptr;

    public:
        Rect() = default;
        Rect(const Rect &src_rect) noexcept;
        Rect(Rect &&src_rect);
        Rect(const RECT &src_rect);
        //Will set de provided pointer to nullptr
        Rect(RECT *src_rect);
        Rect(const RECT &&src_rect);
        Rect(float x, float y, float width, float height);
        Rect(const P2D_F &src_p2d, float width, float height);
        Rect(const P2D_F &&src_p2d, float width, float height);
        ~Rect();

        // void operator=(const Rect &src_rect)
        // {
        //     m_Center = src_rect.m_Center;
        //     m_Origin = src_rect.m_Origin;
        //     m_Rect = src_rect.m_Rect;
        // }

        float getCenter() {return m_Center;}
        P2D_F getOrigin() {return *m_Origin;}
        RECT getRect() {return *m_Rect;}

        P2D_F test() 
        {
            P2D_F a(2,2);
            return a;
        }
};