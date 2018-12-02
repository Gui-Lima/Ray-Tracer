//
// Created by guila on 17/11/18.
//

#ifndef PGAGORAVAI_CAMERA_H
#define PGAGORAVAI_CAMERA_H

#include "../Vector/Vec3.h"
#include "Ray.h"

class Camera {
private:
    Vec3 position;
    Vec3 axisX;
    Vec3 axisY;
    Vec3 axisZ;
    double fov;
    double near;
    double aspect;

public:
    Camera(Vec3 position, double fov, Vec3 target, double near, Vec3 up, int width, int height);

    Ray getRay(double x, double y) const;
};


#endif //PGAGORAVAI_CAMERA_H
