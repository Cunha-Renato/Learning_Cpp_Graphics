#pragma once

#include <iostream>
#include <d2d1.h>
#include "P2D_F.h"

//TODO: Finish implementing the calculation for the center
class Rect
{
    private:
        float m_Center = 0;
        float m_Width = 0;
        float m_Height = 0;
        P2D_F *m_Origin = new P2D_F();
        D2D1_RECT_F *m_Rect = new D2D1_RECT_F;

        void update();

    public:
        Rect() = default;
        Rect(const Rect &src_rect) noexcept;

        //Will set de provided pointer to nullptr
        Rect(D2D1_RECT_F *src_rect);
        Rect(Rect &&src_rect);
        Rect(const D2D1_RECT_F &src_rect);
        Rect(const D2D1_RECT_F &&src_rect);

        Rect(float x, float y, float width, float height);
        Rect(const P2D_F &src_p2d, float width, float height);
        Rect(const P2D_F &&src_p2d, float width, float height);
        ~Rect();

        Rect& operator=(const Rect &src_rect)
        {
            m_Center = src_rect.m_Center;
            *m_Origin = *src_rect.m_Origin;
            *m_Rect = *src_rect.m_Rect;

            std::cout << "Assignment "<<std::endl;
            return *this;
        }
        Rect& operator=(Rect &&src_rect)
        {
            if(&src_rect == this) return *this; 

            m_Center = src_rect.m_Center;
            m_Origin = std::move(src_rect.m_Origin);
            m_Rect = std::move(src_rect.m_Rect);

            src_rect.m_Center = 0;
            src_rect.m_Origin = nullptr;
            src_rect.m_Rect = nullptr;

            std::cout << "Assignment by rvalue!"<<std::endl;

            return *this;
        }   

        //Seters
        //TODO: Do all the other setters, but not now
        void setOrigin(float x, float y);
        void setOrigin(const P2D_F &src_p2d);
        void setOrigin(P2D_F &&src_p2d);
        void setRect(float x, float y, float width, float height);

        float getCenter() {return m_Center;}
        P2D_F getOrigin() {return *m_Origin;}
        const D2D1_RECT_F getRect() {return *m_Rect;}
        float getXOrigin() {return m_Origin->x;}
        float getYOrigin() {return m_Origin->y;}
        float getHeight() {return m_Height;}
        float getWidth() {return m_Width;}

        void moveX(float val);
        void moveY(float val);
};