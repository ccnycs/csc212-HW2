
#define M_PI 3.14159265358979323846

#include <iostream>
#include <vector>
#include <cmath>

#include "point.h"

#ifndef SPHERE_H
#define SPHERE_H
#pragma once

namespace shapes{
  class Sphere{
    private:
      Point center;
      double radius;
    public:
      Sphere(){};
      Sphere(double r);
      Sphere(Point o, double r);
      Point getCenter();
      double getRadius();
      double surfaceArea();
      double volume();
      bool in(Point P);
      bool operator<(Sphere S);
      Sphere friend largest(std::vector <Sphere> spheres);
  };
}
#endif
