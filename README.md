Given the **Point** class defined in the attached "point.h" and the **Sphere** class described in the following declaration (and in the attached "student.h")

```
#!c++
class Sphere{
 private:
   Point center;
   double radius;
 public:
   Sphere();
   Sphere(Point o, double r);
   Point getCenter();
   double getRadius();
   double surfaceArea();
   double volume();
   bool in(Point P);
   bool operator<(Sphere S);
   Sphere friend largest(std::vector <Sphere> spheres);
};
```
Add the following functionality:

Constructors
--------------------------------------
```
#!c++
Sphere::Sphere(){}
Sphere::Sphere(Point c, double r){...}
```
Implement the Sphere constructors. The second constructor must throw a **double** exception when given an invalid radius.

Getters
---------------------------------------
```
#!c++
Point Sphere::getCenter(){...}
double Sphere::getRadius(){...} 
```
Implement functions to return the values of the private attributes of a Sphere object. For example, given:

```
#!c++
Point P(0,0,0);
Sphere S(P, 10);
```
* **S.getCenter()** should return a **point equal to P**
* **S.getRadius()** should return **10**

Methods: Area and Volume
-------------------------------------------------------------------
```
#!c++
double Sphere::surfaceArea(){...}
double Sphere::volume(){...}
```
Implement functions to compute the surface area and volume of a sphere, given the following information:

* PI = 3.14159265358979323846  
* Area = 4πr^2
* Volume = 4/3πr^3

So, given the following code:

```
#!c++
Point P(0,0,0);
Sphere S(P, 1);
```
* **S.surfaceArea()** should return 4π
* **S.volume()** should return 4/3π

Method: Logic

```
#!c++ 
bool Sphere::in(Point P)
```
Implement a function that checks whether a Point is inside the calling sphere. For example, given:

```
#!c++
Point P(0,0,0);
Sphere S(P, 1);
Point P2(2,2);
```

* **S.in(P)** returns **true**
* **S.in(P2)** returns **false**

Note: You do not have to account for the Point P possibly being on the boundary of the Sphere. 

Method: operator <
---------------------------------
```
#!c++
bool Sphere::operator<(Sphere S){...}
```
Overload the **<** operator so that it can be used to evaluate whether one sphere is bigger than another. For example, given:

```
#!c++
Point P(0,0,0);
Sphere S1(P,1);
Sphere S2(P,2);
Sphere S3(P,3);
```
* **S1<S2** returns **true**
* **S3<S2** returns **false**

friend: largest
------------------------------------------------------
```
#!c++
Sphere largest(std::vector <Sphere> spheres){...}
```
Implement a function that returns the largest sphere in a list of spheres. The function should throw an **integer** exception on empty input. Given:

```
#!c++
Point P(0,0,0);
Sphere S1(P,1);
Sphere S2(P,2);
Sphere S3(P,3);
vector <Sphere> spheres(3);
spheres[0] = S1;
spheres[1] = S2;
spheres[3] = S3;
```
**largest(spheres)** should return a sphere *equal to S3*

If the vector contains identical elements, such as in the following example:
```
#!c++
Point P(0,0,0);
Sphere S1(P, 1);
Sphere S2(P, 1);
Sphere S3(P, 1);
vector <Sphere> spheres(3);
spheres[0] = S1;
spheres[1] = S2;
spheres[3] = S3;
```
**largest(spheres)** should return a sphere equal to **any element** in the vector (S1, S2, or S3 for example)

Notes
=====
* Submit your "student.h" file. 
* **Do not submit a main!**
* You **must** use the provided declaration and prototypes and return the specified values. 
* You may add attributes, methods, and standalone functions, but do not remove anything from the provided file. 
* Write a standalone test file to test your implementation **before** you submit it the online.
* You **must** match the output exactly (including spelling, capitalization, punctuation, and spacing). I will not answer emails unless they clearly demonstrate that **all** the directions were followed.


Submitting Code
===============

1. Click on Content in the left hand panel.
2. Go to the Homework 6 Submission
3. Paste in your solution
4. Hit run
5. View test results
6. Hit submit grade

You can resubmit your code until the due date, but **do not**  use the submission window as a compiler. Make sure to compile, run and test your code first.

You **must use Firefox** to submit your homework. We cannot get Chrome or Internet Explorer to work properly. You can get Firefox at [http://www.mozilla.org/en-US/firefox/new/](http://www.mozilla.org/en-US/firefox/new/)

You must first go to [https://134.74.146.30](https://134.74.146.30) Initially you will find this site blocked. It will say this connection is "untrusted".


1. click the text "I understand the Risks".
2. click Add Exception (button)
3. click the "Get Certificate" button
4. click the "confirm the security exception"

You should see "Welcome to nginx!" at [https://134.74.146.30](https://134.74.146.30) in Firefox. If you see that, everything should be ok. You then can go to blackboard with **Firefox**. You can't switch browers. The certificate you accepted only works for Firefox.