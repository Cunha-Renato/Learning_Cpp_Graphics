#include "..\Headers\Engine\Graphics.h"
#include "d2d1.h"

Graphics::Graphics(HWND window_handle)
{
    //Creates a factory in single thread mode
    HRESULT res = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_Factory);

    //Gets the dimensions of the window client
    GetClientRect(window_handle, &m_Rect);

    //Creates a render target based on the client size
    res = m_Factory->CreateHwndRenderTarget
    (
        D2D1::RenderTargetProperties(), 
        D2D1::HwndRenderTargetProperties
        (
            window_handle, 
            D2D1::SizeU(abs(m_Rect.left - m_Rect.right), abs(m_Rect.bottom - m_Rect.top))
        ),
        &m_Render_Target
    );

    res = m_Render_Target->CreateSolidColorBrush
    (
        D2D1::ColorF(1.0f, 1.0f, 1.0f, 1.0f),
        &m_Brush
    );
}

Graphics::~Graphics()
{
    if(m_Factory) m_Factory->Release();
    if(m_Render_Target) m_Render_Target->Release();
    if(m_Brush) m_Brush->Release();
}

void Graphics::drawLine(float x1, float y1, float x2, float y2)
{
    m_Render_Target->DrawLine(D2D1::Point2F(x1, y1), D2D1::Point2F(x2, y2), m_Brush);
}

void Graphics::fillRect(const D2D1_RECT_F *const rect)
{
    m_Render_Target->FillRectangle(rect, m_Brush);
}

void Graphics::fillRect(const D2D1_RECT_F &&rect)
{
    m_Render_Target->FillRectangle(&rect, m_Brush);
}

void Graphics::fillEllipse(const D2D1_ELLIPSE *const ellipse)
{
    m_Render_Target->FillEllipse(ellipse, m_Brush);
}

void Graphics::paintBackground(float r, float g, float b)
{
    m_Render_Target->Clear(D2D1::ColorF(r, g, b));
}