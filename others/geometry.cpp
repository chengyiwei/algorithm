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

double Dot(Vector )
int main(){

}