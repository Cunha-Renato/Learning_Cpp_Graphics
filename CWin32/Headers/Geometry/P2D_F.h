#pragma once

class P2D_F
{
    public:
        float x = 0.0f;
        float y = 0.0f;

        P2D_F() = default;
        P2D_F(const P2D_F &src_p2d) noexcept;
        P2D_F(const P2D_F &&src_p2d);
        P2D_F(float x, float y);
        ~P2D_F() {}

        P2D_F& operator=(const P2D_F &src_p2d)
        {
            x = src_p2d.x;
            y = src_p2d.y;

            return *this;
        }
};