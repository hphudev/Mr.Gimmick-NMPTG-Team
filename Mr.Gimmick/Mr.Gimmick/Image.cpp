#include "Image.h"

Image::Image()
{
    
}

Image::Image(float width, float height, LPCWSTR filename)
{
    this->dimension = Dimension(width, height);
    this->filename = filename;
}

Dimension Image::GetDimension()
{
    return this->dimension;
}

LPCWSTR Image::GetFilename()
{
    return this->filename;
}