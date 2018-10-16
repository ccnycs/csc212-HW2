
#define M_PI 3.14159265358979323846

#include <iostream>
#include <vector>
#include <cmath>

#include "point.h"

#ifndef SPHERE_H
#define SPHERE_H
#pragma once

class Sphere{
 private:
   Point center;
   double radius;
 public:
   Sphere();
   Sphere(double c);
   Sphere(Point o, double r);
   Point getCenter();
   double getRadius();
   double surfaceArea();
   double volume();
   bool in(Point P);
   bool operator<(Sphere S);
   Sphere friend largest(std::vector <Sphere> spheres);
};

Sphere::Sphere(){};
Sphere::Sphere(Point c, double r){
   if (r<0){throw r;}
   center = c;
   radius = r;
}
Point Sphere::getCenter(){
   return center;
}
double Sphere::getRadius(){
   return radius;
}

double Sphere::surfaceArea(){
   return 4.0*M_PI*pow(radius, 2.0);
}

double Sphere::volume(){
   return (4.0/3.0)*M_PI*pow(radius, 3.0);
}

bool Sphere::in(Point P){
   double d = sqrt(pow(P.getX()-center.getX(),2.0)+
                   pow(P.getY()-center.getY(),2.0)+
                   pow(P.getZ()-center.getZ(),2.0));
   return (d<=radius);
}

bool Sphere::operator<(Sphere S){
   return radius<S.radius;
}

Sphere largest(std::vector <Sphere> spheres){
   if (spheres.empty()){throw -1;}
   Sphere max=spheres[0];
   for (int i=0; i<spheres.size(); i++){
      if (max<spheres[i]){
         max=spheres[i];
      }
   }     
   return max;
}

#endif