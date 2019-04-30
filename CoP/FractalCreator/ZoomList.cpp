#include "ZoomList.h"

ZoomList::ZoomList(int width, int height) : m_width(width), m_height(height)
{
}

void ZoomList::add(const Zoom& zoom) {
    zooms.push_back(zoom);

    m_xCenter += (static_cast<double>(zoom.x) - m_width / 2) * m_scale;
    m_yCenter += -(static_cast<double>(zoom.y) - m_height / 2) * m_scale;

    m_scale *= zoom.scale;
}

pair<double, double> ZoomList::doZoom(int x, int y) {
    double xFractal = (static_cast<double>(x) - m_width / 2) * m_scale + m_xCenter;
    double yFractal = (static_cast<double>(y) - m_height / 2) * m_scale + m_yCenter;
    return pair<double, double>(xFractal, yFractal);
}

ZoomList::~ZoomList()
{
}
