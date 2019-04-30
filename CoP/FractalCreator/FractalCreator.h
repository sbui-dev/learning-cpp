#pragma once
#include <string>
#include <memory>
#include <cstdint>
#include <cmath>
#include <vector>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "RGB.h"
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
    unique_ptr<int[]> m_fractal;
    Bitmap m_bitmap;
    ZoomList m_zoomList;

    vector<int> m_ranges;
    vector<RGB> m_colors;
    vector<int> m_rangeTotals;

    bool m_bGotFirstRange{false};

    void calculateIteration();
    void calculateTotalIterations();
    void calculateRangeTotals();
    void drawFractal();
    void writeBitmap(string name);
    int getRange(int iterations) const;

public:
    FractalCreator(int width, int height);
    ~FractalCreator();
    void addRange(double rangeEnd, const RGB& rgb);
    void addZoom(const Zoom& zoom);
    void run(string name);
};

