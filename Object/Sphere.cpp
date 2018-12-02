#include "Object.h"


Sphere::Sphere(Vec3 center, double radius) {
    this->center = center;
    this->radius = radius;
}

Vec3 Sphere::getPoint() const {
    return center;
}

bool Sphere::intersect(const Ray &r, ObjectIntersectionInfo *info) const {
    Vec3 originToCenter = r.origin() - this->center;
    //Calculando intersecção via equação de segundo grau
    double a = originToCenter.dotProduct(r.direction(), r.direction());
    double b = 2.0 * (originToCenter.dotProduct(originToCenter, r.direction()));
    double c = originToCenter.dotProduct(originToCenter, originToCenter) - (this->radius * this->radius);

    secondDegreeEquation sde(a,b,c);
    double deltha = sde.getDeltha();

    if(deltha > 0){
        double firstRoot = sde.getRoots().first;
        double secondRoot = sde.getRoots().second;

        if (firstRoot > 0) {
            if(info != nullptr){
                info->t = firstRoot;
                info->pHit = r.positionAt(info->t);
                info->normal = (info->pHit - center).getUnitVector();
            }
            return true;
        }

        if (secondRoot > 0) {
            if(info != nullptr){
                info->t = secondRoot;
                info->pHit = r.positionAt(info->t);
                info->normal = (info->pHit - center).getUnitVector();
            }
            return true;
        }
    }
    return false;
}
