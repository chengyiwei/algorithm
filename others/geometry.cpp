#include<bits/stdc++.h>
using namespace std;

struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){};
};

typedef Point Vector;

Vector operator + (Vector A,Vector B) {return Vector{A.x+B.x,A.y+B.y};} //向量+向量=向量
Vector operator - (Point A,Point B) {return Vector{A.x-B.x,A.y-B.y};} //点-点=向量
Vector operator * (Vector A,double p) {return Vector{A.x*p,A.y*p};} //向量*数=向量
Vector operator / (Vector A,double p) {return Vector{A.x/p,A.y/p};} //向量/数=向量

bool operator<(const Point& a,const Point& b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

const double eps=1e-9;
int dcmp(double x){if(fabs(x)<eps) return 0;else return x<0?-1:1;}
bool operator ==(const Point &a,const Point &b){
    return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
}

double Dot(Vector A,Vector B) {return A.x*B.x+A.y*B.y;}
double Length(Vector A) {return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B) {return acos(Dot(A,B)/Length(A)/Length(B));}

double Cross(Vector A,Vector B) {return A.x*B.y-A.y*B.x;}
double Area2(Point A,Point B,Point C) {return Cross(B-A,C-A);}

//向量逆时针旋转 rad
Vector Rotate(Vector A,double rad){return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));} //rad是弧度

//求向量的单位法线,调用前判断 A 是不是零向量
Vector Normal(Vector A){double L=Length(A);return Vector(-A.y/L,A.x/L);}

//求两条直线的交点
Point GetLineInersection(Point P,Vector v,Point Q,Vector w){
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}

//点到直线的距离
double DistanceToLine(Point P,Point A,Point B){
    Vector v1=B-A,v2=P-A;
    return fabs(Cross(v1,v2))/Length(v1);
}

//点到线段的距离
double DistanceToSegment(Point P,Point A,Point B){
    if(A==B) return Length(P-A);
    Vector v1=B-A,v2=P-A,v3=P-B;
    if(dcmp(Dot(v1,v2))<0) return Length(v2);
    else if(dcmp(Dot(v1,v3)>0)) return Length(v3);
    else return fabs(Cross(v1,v2))/Length(v1);
}

int main(){

}