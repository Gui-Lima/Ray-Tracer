//
// Created by guila on 17/11/18.
//

#ifndef PGAGORAVAI_SCENE_H
#define PGAGORAVAI_SCENE_H

#include <vector>
#include "../Object/Object.h"

class Scene {
    std::vector<Object*> objects;
public:

    Scene();

    bool intersect(const Ray& r, ObjectIntersectionInfo* info= nullptr) const;

    Vec3 phong(Object* objLight, ObjectIntersectionInfo objInfo, Ray incidenceRay, Ray objectIntersectedToObjLight)const;

    Vec3 trace(const Ray& r,int recursionLevel = 0) const ;

    void add(Object* object);
};


#endif //PGAGORAVAI_SCENE_H
