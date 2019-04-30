#include <iostream>
#include <cstdint>
#include <memory>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;

int main()
{
    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);

    double min = 9999999;
    double max = -9999999;

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{});

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
            double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);

            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                histogram[iterations]++;
            }

            uint8_t color = static_cast<uint8_t>(256 * static_cast<double>(iterations) / Mandelbrot::MAX_ITERATIONS);

            color = color * color * color;

            bitmap.setPixel(x, y, 0, color, 0);
            if (color < min) min = color;
            if (color > max) max = color;
        }
    }

    cout << min << ", " << max << endl;

    bitmap.write("test.bmp");
    cout << "Finished" << endl;
    return 0;
}