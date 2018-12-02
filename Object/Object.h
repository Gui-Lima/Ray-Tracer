//
// Created by guila on 17/11/18.
//

#ifndef PGAGORAVAI_OBJECT_H
#define PGAGORAVAI_OBJECT_H

#include "../Vector/Vec3.h"
#include "Material.h"
#include "Geometry.h"
#include "ObjectIntersectionInfo.h"

class Geometry;
class Material;
class ObjectIntersectionInfo;

class Object  {

private:
    Material *material;
    Geometry* geometry;

public:
    Object(Geometry* geometry, Material* material1);


    bool intersect(const Ray& r, ObjectIntersectionInfo* info = nullptr);

    Vec3 getPoint();

    bool isLight();

    Material* getMaterial();
};



#endif //PGAGORAVAI_OBJECT_H
