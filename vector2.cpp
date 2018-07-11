#include "vector2.h"
Vector2::Vector2():x(0),y(0){}
Vector2::Vector2(int X, int Y):x(X),y(Y){}

void Vector2::operator += (const Vector2& v){x += v.x; y += v.y;}
void Vector2::operator -= (const Vector2& v){x -= v.x; y -= v.y;}

ostream& operator << (ostream& out, const Vector2& v){
    out << "[ " << v.x << " , " << v.y << " ]";
    return out;
}
Vector2 operator + (const Vector2& v1,const Vector2& v2){
    return Vector2(v1.x + v2.x, v1.y + v2.y);
}
Vector2 operator - (const Vector2& v1,const Vector2& v2){
    return Vector2(v1.x - v2.x, v1.y - v2.y);
}
void Vector2::operator *= (int i){
    x *= i;
    y *= i;
}
Vector2 operator * (const Vector2& v,int i){
    return Vector2(v.x * i, v.y * i);
}
Vector2 operator * (int i,const Vector2& v){
    return Vector2(v.x * i, v.y * i);
}
