//
// Created by guila on 17/11/18.
//

#ifndef PGAGORAVAI_OBJECTINTERSECTION_H
#define PGAGORAVAI_OBJECTINTERSECTION_H


#include "../Vector/Vec3.h"
#include "Object.h"

class Object;

class ObjectIntersectionInfo {
public:
    double t;
    Vec3 pHit;
    Vec3 normal;
    Object* o;
};


#endif //PGAGORAVAI_OBJECTINTERSECTION_H
