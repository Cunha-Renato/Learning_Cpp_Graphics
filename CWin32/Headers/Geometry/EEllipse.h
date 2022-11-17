#pragma once

#include "EObject.h"

class EEllipse : public EObject
{
    private:
        D2D1_ELLIPSE m_Ellipse = {0};

        void update();

    public:
        EEllipse() : EObject() {}
        EEllipse(float x, float y, float radiusX, float radiusY);
        EEllipse(const EEllipse &src_ellipse);
        EEllipse(const P2D_F &origin, float radiusX, float radiusY);
        ~EEllipse() {}

        //Seters

        void setEEllipse(float x, float y, float radiusX, float radiusY);

        D2D1_ELLIPSE getEllipse() {return m_Ellipse;}
};