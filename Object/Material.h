//
// Created by guila on 17/11/18.
//

#ifndef PGAGORAVAI_MATERIAL_H
#define PGAGORAVAI_MATERIAL_H


#include "../Vector/Vec3.h"

class Material {
public:
    Vec3 color;
    float ks;
    float kd;
    float alpha;
    float ke;

    Material(Vec3 color, float ks, float kd, float ke, float alpha);

    Vec3 getNormalizedColor();
};



class Luca : public Material{
};


#endif //PGAGORAVAI_MATERIAL_H
