#pragma once

#include <d2d1.h>
#include <iostream>
#include "P2D_F.h"

class EObject
{
    protected:
        bool m_Solid = false;
        float m_Center = 0;
        P2D_F m_Origin;

        virtual void update() = 0;

    public:
        virtual ~EObject(){};

        virtual void setOrigin(const float &x, const float &y);
        virtual void setOrigin(const P2D_F &src_p2d);
        virtual void setOrigin(P2D_F &&src_p2d);
        virtual void setX(float val);
        virtual void setY(float val);

        P2D_F getOrigin() {return m_Origin;}
        float getXOrigin() {return m_Origin.x;}
        float getYOrigin() {return m_Origin.y;}

        //Angle in degrees
        void move(float angle, float force);
};