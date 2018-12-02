//
// Created by ggfl on 07/11/18.
//

#ifndef PG_SECONDDEGREEEQUATION_H
#define PG_SECONDDEGREEEQUATION_H



#include <cstdio>
#include <cmath>
#include <utility>


class secondDegreeEquation {
private:
    double a;
    double b;
    double c;
    double deltha;
    double root1;
    double root2;
public:
    secondDegreeEquation(double a, double b, double c);

    double getDeltha();

    std::pair<double, double> getRoots();


};


#endif //PG_SECONDDEGREEEQUATION_H