#pragma once
#include <cstdint>

using namespace std;

// 2 byte alignment needed
#pragma pack(push, 2)
struct BitmapFileHeader {
    char header[2]{ 'B', 'M' };
    int32_t fileSize;
    int32_t reserved{ 0 };
    int32_t dataOffset;
};

#pragma pack(pop)