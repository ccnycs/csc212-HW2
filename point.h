#ifndef POINT_H
#define POINT_H

#pragma once
class Point
{
 private:
   double x;
   double y;
   double z;
 public:
   Point(){};
   Point(double nx, double ny, double nz){
          x = nx; y = ny; z = nz; }
   double getX(){return x;}
   double getY(){return y;}
   double getZ(){return z;}
};
#endif