#ifndef PG_VEC3_H
#define PG_VEC3_H

#include <math.h>
#include <stdlib.h>
#include <iostream>

class Vec3  {
private:

public:
    float e[3];
    Vec3();
    Vec3(float e0, float e1, float e2);
    float getCordX() const ;
    float getCordY() const;
    float getCordZ() const;
    float getColorR() const ;
    float getColorG() const;
    float getColorB() const;


    // Overloading useful unary operators
    Vec3 operator-() const;
    float operator[](int i) const;
    float& operator[](int i);


    friend Vec3 operator+(const Vec3 &v1, const Vec3 &v2){
        Vec3 v =  Vec3(v1.getCordX() + v2.getCordX(), v1.getCordY() + v2.getCordY(), v1.getCordZ()+v2.getCordZ());
        return v;
    }


    friend Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
        return {v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]};
    }

    friend Vec3 operator*(const Vec3 &v1, const Vec3 &v2) {
        return {v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]};
    }

    friend Vec3 operator/(const Vec3 &v1, const Vec3 &v2) {
        return {v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]};
    }

    friend Vec3 operator*(float t, const Vec3 &v) {
        return {t*v.e[0], t*v.e[1], t*v.e[2]};
    }

    friend Vec3 operator/(Vec3 v, float t) {
        return {v.e[0]/t, v.e[1]/t, v.e[2]/t};
    }

    friend Vec3 operator*(const Vec3 &v, float t) {
        return {t*v.e[0], t*v.e[1], t*v.e[2]};
    }

    Vec3& operator+=(const Vec3 &v2);
    Vec3& operator-=(const Vec3 &v2);
    Vec3& operator*=(const Vec3 &v2);
    Vec3& operator/=(const Vec3 &v2);
    Vec3& operator*=(const float t);
    Vec3& operator/=(const float t);

    float length() const;
    float squared_length() const;

    void make_unit_vector();

    float dotProduct(const Vec3 &v1, const Vec3 &v2);
    Vec3 cross(const Vec3 &v1, const Vec3 &v2);
    Vec3 getUnitVector();

};


#endif //PG_VEC3_H