#include "sphere.h"

namespace shapes{
    Sphere::Sphere(Point c, double r){
        //throw a double exception when given an invalid radius.
    };
    Point Sphere::getCenter(){
        //return the center (Point) of the sphere
    };
    double Sphere::getRadius(){
        //return the radius of the sphere
    };
    double Sphere::surfaceArea(){
        //return the surface area 4*pi*r^2
    };
    double Sphere::volume(){
        //return the volume (4/3)*pi*r^3
    };
    bool Sphere::in(Point P){
        // true: point P is in the sphere
        // false: point is not on the sphere
        // not tested: point is on boundary of sphere
    };
    bool Sphere::operator<(Sphere S){
        //true: S1 < S2, S1 is smaller
        // false: S1 < S2, S1 is greater or equal
    };
    Sphere largest(std::vector <Sphere> spheres){
        //return the largest sphere in a list
        // when multiple spheres of same size, return any
        // throw an integer exception on empty input
    };
}