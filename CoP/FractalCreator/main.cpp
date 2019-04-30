#include <iostream>
#include <cstdint>
#include <memory>
#include <cmath>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"

using namespace std;

int main()
{
    int const WIDTH = 800;
    int const HEIGHT = 600;

    Bitmap bitmap(WIDTH, HEIGHT);

    bitmap.setPixel(WIDTH/2, HEIGHT/2, 255, 255, 255);

    double min = 9999999;
    double max = -9999999;

    ZoomList zoomList(WIDTH, HEIGHT);
    zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 4.0 / WIDTH));

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{});
    unique_ptr<int[]> fractual(new int[WIDTH * HEIGHT]{});

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pair<double, double> coordinates = zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(coordinates.first, coordinates.second);
           
            fractual[y * WIDTH + x] = iterations;

            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                histogram[iterations]++;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        total += histogram[i];
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = fractual[y * WIDTH + x];

            if (iterations != Mandelbrot::MAX_ITERATIONS) {

                double hue = 0.0;

                for (int i = 0; i <= iterations; i++) {
                    hue += static_cast<double>(histogram[i]) / total;
                }

                green = pow(255, hue);
            }

            bitmap.setPixel(x, y, red, green, blue);
        }
    }

    bitmap.write("test.bmp");
    cout << "Finished" << endl;
    return 0;
}