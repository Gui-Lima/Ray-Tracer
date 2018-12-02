//
// Created by p on 17/11/18.
//

#include "Vec3.h"


Vec3::Vec3() {}
Vec3::Vec3(float e0, float e1, float e2) { e[0] = e0; e[1] = e1; e[2] = e2; }
float Vec3::getCordX() const { return e[0]; }
float Vec3::getCordY() const { return e[1]; }
float Vec3::getCordZ() const { return e[2]; }
float Vec3::getColorR() const { return e[0]; }
float Vec3::getColorG() const { return e[1]; }
float Vec3::getColorB() const { return e[2]; }


Vec3 Vec3::operator-() const { return {-e[0], -e[1], -e[2]}; }
float Vec3::operator[](int i) const { return e[i]; }
float& Vec3::operator[](int i) { return e[i]; };
// More complex operators with "="

Vec3& Vec3::operator+=(const Vec3 &v){
    e[0]  += v.e[0];
    e[1]  += v.e[1];
    e[2]  += v.e[2];
    return *this;
}

Vec3& Vec3::operator*=(const Vec3 &v){
    e[0]  *= v.e[0];
    e[1]  *= v.e[1];
    e[2]  *= v.e[2];
    return *this;
}

Vec3& Vec3::operator/=(const Vec3 &v){
    e[0]  /= v.e[0];
    e[1]  /= v.e[1];
    e[2]  /= v.e[2];
    return *this;
}

Vec3& Vec3::operator-=(const Vec3& v) {
    e[0]  -= v.e[0];
    e[1]  -= v.e[1];
    e[2]  -= v.e[2];
    return *this;
}

Vec3& Vec3::operator*=(const float t) {
    e[0]  *= t;
    e[1]  *= t;
    e[2]  *= t;
    return *this;
}

Vec3& Vec3::operator/=(const float t) {
    float k = 1.0/t;
    e[0]  *= k;
    e[1]  *= k;
    e[2]  *= k;
    return *this;
}

// Util functions

float Vec3::length() const {
    return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
}

float Vec3::squared_length() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

void Vec3::make_unit_vector() {
    float k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    e[0] *= k; e[1] *= k; e[2] *= k;
}

float Vec3::dotProduct(const Vec3 &v1, const Vec3 &v2) {
    return v1.e[0] *v2.e[0] + v1.e[1] *v2.e[1]  + v1.e[2] *v2.e[2];
}

Vec3 Vec3::cross(const Vec3 &v1, const Vec3 &v2) {
    return Vec3( (v1.e[1]*v2.e[2] - v1.e[2]*v2.e[1]),
                 (-(v1.e[0]*v2.e[2] - v1.e[2]*v2.e[0])),
                 (v1.e[0]*v2.e[1] - v1.e[1]*v2.e[0]));
}

Vec3 Vec3::getUnitVector() {
    return *this/this->length();
}


