#pragma once
#include <string>
#include <memory>
#include <cstdint>
#include <cmath>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "Zoom.h"
#include "ZoomList.h"
using namespace std;

class FractalCreator
{
private:
    int m_width;
    int m_height;
    int m_total{ 0 };
    unique_ptr<int[]> m_histogram;
    unique_ptr<int[]> m_fractual;
    Bitmap m_bitmap;
    ZoomList m_zoomList;
public:
    FractalCreator(int width, int height);
    ~FractalCreator();

    void calculateIteration();
    void calculateTotalIterations();
    void drawFractal();
    void addZoom(const Zoom& zoom);
    void writeBitmap(string name);
};

