#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace std;

Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height), m_pPixels(std::make_unique<uint8_t[]>(width * height * 3))  {
}

bool Bitmap::write(string filename) {

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    // entire file size; m_width * m_height * 3 is the data
    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
    
    // offset to where the data begins
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    ofstream file;
    file.open(filename, ios::out | ios::binary);

    if (!file) {
        return false;
    }

    // write file header to file
    file.write((char *) &fileHeader, sizeof(fileHeader));

    // write info header to file
    file.write((char *) &infoHeader, sizeof(infoHeader));

    // write data to file
    int size = m_width * m_height * 3;
    file.write((char *) m_pPixels.get(), size);

    file.close();

    return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t* pPixel = m_pPixels.get();

    pPixel += (y * 3) * m_width + (x * 3);

    // little indian format
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
}

Bitmap::~Bitmap()
{
}
