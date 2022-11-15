#pragma once

#include <d2d1.h>
#include <iostream>
#include "P2D_F.h"

class EObject
{
    protected:
        bool m_Solid = false;
        P2D_F *m_Origin = new P2D_F();

        virtual void update() = 0;

    public:
        virtual ~EObject() {if(m_Origin) delete m_Origin;}

        virtual void setOrigin(float x, float y);
        virtual void setOrigin(const P2D_F &src_p2d);
        virtual void setOrigin(P2D_F &&src_p2d);

        P2D_F getOrigin() {return *m_Origin;}
        float getXOrigin() {return m_Origin->x;}
        float getYOrigin() {return m_Origin->y;}

        virtual void moveX(float val);
        virtual void moveY(float val);
};