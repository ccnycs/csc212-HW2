#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

#include <gtest/gtest.h>
#include "sphere.h"
#include "point.h"


class SphereTest : public testing::Test{
  protected:
    static Point randPoint(double &x,
 		  double &y, double &z){
      x = rand()%10;
      y = rand()%10;
      z = rand()%10;
      return Point(x, y, z);
    }
  
  static constexpr double T_PI = 3.14159265358979323846;
};

TEST_F(SphereTest, TestConstructorInvalid){
   double radius = -1*(rand()%10+1);
   Point init(0,0, 0);
   ASSERT_THROW(Sphere(init, radius), double);
}

TEST_F(SphereTest,TestGetPrivateAttrs){
  double x,y,z;
  double radius = rand()%9+10;
  Point init = randPoint(x, y, z);
  Sphere S(init, radius);
  ASSERT_DOUBLE_EQ(x, S.getCenter().getX()); 
  ASSERT_DOUBLE_EQ(y, S.getCenter().getY());
  ASSERT_DOUBLE_EQ(z, S.getCenter().getZ());
  ASSERT_DOUBLE_EQ(radius, S.getRadius());
}

TEST_F(SphereTest, TestSurfaceArea){
  double area = (rand()%5+5)*100;
  double x,y,z;
  Point init = randPoint(x,y,z);
  double r = sqrt(area/(4.0*T_PI));
  Sphere S(init, r);
  ASSERT_DOUBLE_EQ(area, S.surfaceArea());
}

TEST_F(SphereTest, TestVolume){
  double volume = (rand()%5+5)*100;
  double x,y,z;
  Point init = randPoint(x,y,z);
  double r = pow((3*volume)/(4*T_PI), 1/3.);
  Sphere S(init, r);
  ASSERT_DOUBLE_EQ(volume, S.volume());
}

TEST_F(SphereTest, TestInTrue){
  double r = rand()%10+10;
  double x,y,z;
  Point init = randPoint(x,y,z);
  Sphere S(init, r);
  
  double p1 = x+(r/2.0)*pow(-1,rand()%2);
  double p2 = y+(r/2.0)*pow(-1,rand()%2);
  double p3 = z+(r/2.0)*pow(-1,rand()%2);

  Point P(p1, p2, p3);
  ASSERT_EQ(true, S.in(P));
}

TEST_F(SphereTest, TestInFalse){   
  double r = rand()%10+10;
  double x, y, z;
  Point init = randPoint(x,y,z);
  Sphere S(init, r);
  double xt = x+(r*2)*pow(-1,rand()%2);
  Point P1(xt, y, z);
  ASSERT_EQ(false, S.in(P1));
  double yt = y+(r*2)*pow(-1,rand()%2);
  Point P2(x, yt, z);
  ASSERT_EQ(false, S.in(P2));
  double zt = z+(r*2)*pow(-1,rand()%2);
  Point P3(z, y, zt);
  ASSERT_EQ(false, S.in(P3));
}

TEST_F(SphereTest, TestLessTrue){
  double r1 = rand()%10+1;
  double x1,y1,z1;
  Point init = randPoint(x1,y1,z1);
  Sphere Small(init, r1);
  double r2 = r1*(rand()%3+2);
  double x2,y2,z2;
  Point init2 = randPoint(x2,y2,z2);
  Sphere Large(init2, r2);   
  ASSERT_EQ(true, Small<Large);
}
   
TEST_F(SphereTest, TestLessFalse){
  double r1 = rand()%10+1;
  double x1,y1,z1;
  Point init = randPoint(x1,y1,z1);
  Sphere Small(init, r1);
  double r2 = r1*(rand()%3+2);
  double x2,y2,z2;
  Point init2 = randPoint(x2,y2,z2);
  Sphere Large(init2, r2);
  ASSERT_EQ(false, Large<Small);
}
   
TEST_F(SphereTest, TestLargestEmpty){
  std::vector <Sphere> spheres;
  ASSERT_THROW(largest(spheres), int);
}
   
TEST_F(SphereTest, TestLargestEqual){
  double x,y,z;
  Point init = randPoint(x,y,z);
  double r = rand()%10 + 10;
  Sphere S(init, r);
  int size = static_cast<int>(rand()%10+20);
  std::vector <Sphere> spheres(size, S);
  Sphere Actual = largest(spheres);
  
  ASSERT_DOUBLE_EQ(x, Actual.getCenter().getX());
  ASSERT_DOUBLE_EQ(y, Actual.getCenter().getY());
  ASSERT_DOUBLE_EQ(z, Actual.getCenter().getZ());
  ASSERT_DOUBLE_EQ(r, Actual.getRadius());
}
   
TEST_F(SphereTest, TestLargestNotEqual){
  double r = rand()%10 + 10;
  int size = static_cast<int>(rand()%10+20);
  int l = size-1;
  std::vector <Sphere> spheres(size);
  double *x = new double[size];
  double *y = new double[size];
  double *z = new double [size];
  double *radius = new double[size];
  
  for (int i=0; i<size; i++){
    Point center = randPoint(x[i], y[i], z[i]);
    radius[i] = r*(i+1);
    spheres[i] = Sphere(center, radius[i]);
  }

  random_shuffle(spheres.begin(), spheres.end());
  Sphere Actual = largest(spheres);
  
  ASSERT_DOUBLE_EQ(x[l], Actual.getCenter().getX());
  ASSERT_DOUBLE_EQ(y[l], Actual.getCenter().getY());
  ASSERT_DOUBLE_EQ(z[l], Actual.getCenter().getZ());
  ASSERT_DOUBLE_EQ(radius[l], Actual.getRadius());
}

//-----------------------------------------------------------------------------
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

