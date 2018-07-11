#ifndef VECTOR2_H
#define VECTOR2_H
#include "all.h"

class Vector2{
public:
    Vector2();
    Vector2(int X, int Y);
    void operator += (const Vector2& v);
    void operator -= (const Vector2& v);
    void operator *= (int i);
    friend ostream& operator << (ostream& out, const Vector2& v);
    friend Vector2 operator + (const Vector2& v1,const Vector2& v2);
    friend Vector2 operator - (const Vector2& v1,const Vector2& v2);
    friend Vector2 operator * (const Vector2& v,int i);
    friend Vector2 operator * (int i,const Vector2& v);
    union{
        struct { int x, y; };
        struct { double cell[2]; };
    };
};
typedef Vector2 Pixel;
#endif
