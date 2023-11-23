#include<bits/stdc++.h>
using namespace std;

struct Point3{
    double x,y,z;
    Point3(double x=0,double y=0,double z=0):x(x),y(y),z(z){}
};
typedef Point3 Vector3;

Vector3 operator +(Vector3 A,Vector3 B) {return Vector3(A.x+B.x,A.y+B.y,A.z+B.z);}
Vector3 operator -(Point3 A,Point3 B) {return Vector3(A.x-B.x,A.y-B.y,A.z-B.z);}
Vector3 operator *(Vector3 A,double p) {return Vector3(A.x*p,A.y*p,A.z*p);}
Vector3 operator /(Vector3 A,double p) {return Vector3(A.x/p,A.y/p,A.z/p);}

double Dot(Vector3 A,Vector3 B) {return A.x*B.x+A.y*B.y+A.z*B.z;}
double Length(Vector3 A) {return sqrt(Dot(A,A));}
double Angle(Vector3 A,Vector3 B) {return acos(Dot(A,B)/Length(A)/Length(B));}
double DistanceToPlane(Point3 p,Point3 p0,Vector3 n){return fabs(Dot(p-p0,n))/Length(n);}//点 p 到平面 p0-n 的距离，如果不取绝对值，得到的是有向距离
Point3 GetPlaneProjection(Point3 p,Point3 p0,Vector3 n){//点在平面上的投影
    double d=Dot(p-p0,n)/Length(n);
    return p-n*d;
}
Point3 LinePlaneIntersection(Point3 p1,Point3 p2,Point3 p0,Vector3 n){
    Vector3 v=p2-p1;
    double t=(Dot(n,p0-p1)/Dot(n,p2-p1));
    return p1+v*t;
}


int main(){}