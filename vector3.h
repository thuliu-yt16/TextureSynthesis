#ifndef VECTOR3_H
#define VECTOR3_H
#include "all.h"
#define DOT(A,B)		(A.x*B.x+A.y*B.y+A.z*B.z)
#define NORMALIZE(A)	{double l=1/sqrt(A.x*A.x+A.y*A.y+A.z*A.z);A.x*=l;A.y*=l;A.z*=l;}
#define LENGTH(A)		(sqrtf(A.x*A.x+A.y*A.y+A.z*A.z))
#define SQRLENGTH(A)	(A.x*A.x+A.y*A.y+A.z*A.z)
#define SQRDISTANCE(A,B) ((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)+(A.z-B.z)*(A.z-B.z))

class Vector3{
public:
    Vector3();
    Vector3(double a_X,double a_Y,double a_Z);
    void Set(double a_X,double a_Y,double a_Z);
    void Normalize();
    double Length() const;
    double SqrLength() const;
    double Dot(Vector3 a_V) const;
    Vector3 Normal() const;
    Vector3 Cross(const Vector3& b) const;
    double Max() const;
    void operator += (const Vector3& a_V);
    void operator += (Vector3* a_V);
    void operator -= (const Vector3& a_V);
    void operator -= (Vector3* a_V);
    void operator *= (double f);
    void operator *= (const Vector3& a_V);
    void operator *= (Vector3* a_V);
    void operator /= (double f);
    Vector3 operator- () const;
    friend istream& operator >> (istream& in, Vector3& v);
    friend ostream& operator << (ostream& out, const Vector3& v);
    friend Vector3 operator + (const Vector3& v1,const Vector3& v2);
    friend Vector3 operator - (const Vector3& v1,const Vector3& v2);
    friend Vector3 operator + (const Vector3& v1,Vector3* v2);
    friend Vector3 operator - (const Vector3& v1,Vector3* v2);
    friend Vector3 operator * (const Vector3& v,double f);
    friend Vector3 operator * (const Vector3& v1,const Vector3& v2);
    friend Vector3 operator * (double f,const Vector3& v);
    friend Vector3 operator / (const Vector3& v, double f);
    union{
        struct { double x, y, z; };
        struct { double r, g, b; };
        struct { double cell[3]; };
    };
};
typedef Vector3 Color;


#endif
