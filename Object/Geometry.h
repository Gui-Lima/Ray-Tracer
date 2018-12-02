//
// Created by guila on 17/11/18.
//

#ifndef PGAGORAVAI_GEOMETRY_H
#define PGAGORAVAI_GEOMETRY_H

#include "../Camera/Ray.h"
#include "ObjectIntersectionInfo.h"
#include "../Math/secondDegreeEquation.h"

class Geometry{
public:
    virtual bool intersect(const Ray &r, ObjectIntersectionInfo* info=nullptr) const=0;

    //Ponto que é a fonte luz
    virtual Vec3 getPoint() const=0;
};


class Sphere:public Geometry{
private:
    Vec3 center;
    double radius;
public:
    Sphere(Vec3 center, double radius);
    bool intersect(const Ray &r, ObjectIntersectionInfo* info=nullptr) const override;
    Vec3 getPoint() const override;
};

#endif //PGAGORAVAI_GEOMETRY_H
