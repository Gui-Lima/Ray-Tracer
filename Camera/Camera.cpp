//
// Created by guila on 17/11/18.
//

#include "Camera.h"

Camera::Camera(Vec3 position, double fov, Vec3 target, double near, Vec3 up, int width, int height) {
    this->axisZ = (position - target).getUnitVector();
    this->axisX = axisZ.cross(axisZ, up).getUnitVector();
    this->axisY = axisZ.cross(axisZ, axisX).getUnitVector();

    this->aspect = (float) width/ (float )height;
    this->near = near;
    this->fov = fov*M_PI/float(180);
    this->position = position;
}

Ray Camera::getRay(double x, double y) const {
    double halfHeight = this->near * tanf(this->fov/2);
    double halfWidth = aspect * halfHeight;

    double pointX = 2 * (x - 0.5) * halfWidth;
    double pointY = 2 * (y - 0.5) * halfHeight;
    double pointZ = -near;

    //mudando a base
    double pX = this->axisX.getCordX() * pointX + this->axisY.getCordX() * pointY + this->axisZ.getCordX() * pointZ;
    double pY = this->axisX.getCordY() * pointX + this->axisY.getCordY() * pointY + this->axisZ.getCordY() * pointZ;
    double pZ = this->axisX.getCordZ() * pointX + this->axisY.getCordZ() * pointY + this->axisZ.getCordZ() * pointZ;

    Vec3 point(pX, pY, pZ);
    return Ray(this->position, point.getUnitVector());
}
