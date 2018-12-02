//
// Created by guila on 17/11/18.
//

#include "Material.h"

Material::Material(Vec3 color, float ks, float kd, float ke, float alpha) {
    this->color = color;
    this->ke = ke;
    this->alpha = alpha;
    this->ks = ks;
    this->kd = kd;
}

Vec3 Material::getNormalizedColor(){
    return this->color/255.0;
}


