#ifndef IMAGE_H
#define IMAGE_H
#include "all.h"
#include "vector3.h"
#include "vector2.h"
class Image{
private:
    Color** image;
public:
    int width;
    int height;

    Image();
    Image(int _w, int _h);
    Image(const string& filename);
    void save(const string& filename);
    Color GetColor(int x,int y) const;
    Color GetColor(const Pixel& p) const;
    void SetColor(const Pixel& p, Color color);
    void SetColor(int x,int y,Color color);
    ~Image();
};
#endif
