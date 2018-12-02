//
// Created by ggfl on 07/11/18.
//

#include "secondDegreeEquation.h"
//Apenas automatizando e organizando resolução de equação de segundo grau
secondDegreeEquation::secondDegreeEquation(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->deltha = (b*b) - (4.0*a*c);
    if(deltha > 0){
        this->root1 = (-b - sqrt(deltha))/(2.0*a);
        this->root2 = (-b + sqrt(deltha))/(2.0*a);
    }

    else if(deltha < 0){
        root1 = root2 = 0;
    }

    else{
        root1 = (-b - sqrt(deltha))/(2.0*a);
        root2  = (-b - sqrt(deltha))/(2.0*a);
    }

}

double secondDegreeEquation::getDeltha() {
    return this->deltha;
}

std::pair<double, double> secondDegreeEquation::getRoots() {
    return std::make_pair(root1, root2);
}