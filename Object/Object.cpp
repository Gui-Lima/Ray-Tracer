#include "Object.h"


Object::Object(Geometry *geometry, Material *material) {
    this->material = material;
    this->geometry = geometry;
}

bool Object::intersect(const Ray &r, ObjectIntersectionInfo *info) {
    bool didIntersect = this->geometry->intersect(r, info);
    if (info != nullptr && didIntersect)
        info->o = this;
    return didIntersect;
}

Material *Object::getMaterial() {
    return this->material;
}

bool Object::isLight() {
    return this->material->ke > 0;
}

Vec3 Object::getPoint() {
    return this->geometry->getPoint();
}
