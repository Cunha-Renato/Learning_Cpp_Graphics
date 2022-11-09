#include "..\..\Headers\Geometry\P2D_F.h"

P2D_F::P2D_F(const P2D_F &src_p2d) noexcept
{
    if(&src_p2d)
    {
        x = src_p2d.x;
        y = src_p2d.y;
    }
}

P2D_F::P2D_F(float x, float y)
{
    P2D_F::x = x;
    P2D_F::y = y;
}