#include<bits/stdc++.h>
using namespace std;

struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){};
};
typedef Point Vector;
struct Line{
    Point P;
    Vector v;
    double ang;
    Line(){}
    Line(Point p,Vector v):P(p),v(v){ang=atan2(v.y,v.x);}
    bool operator <(const Line& L) const{return ang<L.ang;}
};
Vector operator + (Vector A,Vector B) {return Vector{A.x+B.x,A.y+B.y};} //向量+向量=向量
Vector operator - (Point A,Point B) {return Vector{A.x-B.x,A.y-B.y};} //点-点=向量
Vector operator * (Vector A,double p) {return Vector{A.x*p,A.y*p};} //向量*数=向量
Vector operator / (Vector A,double p) {return Vector{A.x/p,A.y/p};} //向量/数=向量

bool operator<(const Point& a,const Point& b){return a.x<b.x||(a.x==b.x&&a.y<b.y);}

const double eps=1e-9;
int dcmp(double x){if(fabs(x)<eps) return 0;else return x<0?-1:1;}  //自定义比较函数
bool operator ==(const Point &a,const Point &b){
    return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
}

double Dot(Vector A,Vector B) {return A.x*B.x+A.y*B.y;}  //典籍
double Length(Vector A) {return sqrt(Dot(A,A));}  //长度
double Angle(Vector A,Vector B) {return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vector A,Vector B) {return A.x*B.y-A.y*B.x;} //叉积

double Area2(Point A,Point B,Point C) {return Cross(B-A,C-A);} //三角形有向面积的两倍

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

//点在直线上的投影
Point GetLineProjection(Point P,Point A,Point B){
    Vector v=B-A;
    return A+v*(Dot(v,P-A)/Dot(v,v));
}

//判断线段是否相交
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
    double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}

//判断一个点是否在一条线段上
bool OnSegment(Point p,Point a1,Point a2){
    return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p));
}

//计算多边形面积
double ConvexPolgonArea(Point *p,int n){
    double area=0;
    for(int i=1;i<n-1;i++)
        area += Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}

typedef Point* Polygon;

int isPointInPolygon(Point p,Polygon poly,int n){
    int wn=0;
    for(int i=0;i<n;i++){
        if(OnSegment(p,poly[i],poly[(i+1)&n])) return -1;//在边界上
        int k=dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i]));
        int d1=dcmp(poly[i].y-p.y);
        int d2=dcmp(poly[(i+1)%n].y-p.y);
        if(k>0&&d1<=0&&d2>0) wn++;
        if(k<0&&d2<=0&&d1>0) wn--;
    }
    if(wn!=0) return 1; //内部
    return 0; //外部
}

bool cmp(Point A,Point B){
    return A.x<B.x||(dcmp(A.x-B.x)==0&&A.y<B.y);
}
int ConvexHull(Point* p,int n,Point* ch){ // 凸包
    sort(p,p+n,cmp);
    int m=0; 
    for(int i=0;i<n;i++){ //下面一半
        while(m>1 && Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0)m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--){ //上面一半
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1)m--;
    return m;
}

//点 p 在有向直线 L 的左边(线上不算)
bool OnLeft(Line L,Point p){
    return Cross(L.v,p-L.P)>0;
}

Point GetIntersction(Line a,Line b){//二直线交点，假定交点唯一存在
    Vector u=a.P-b.P;
    double t=Cross(b.v,u)/Cross(a.v,b.v);
    return a.P+a.v*t;
}

int HalfplanIntersection(Line *L,int n,Point* poly){//半平面交
    sort(L,L+n); //按照极角排序

    int first,last; //双端队列的第一个元素和最后一个元素的下标
    Point *p=new Point[n]; //p[i] 为 q[i]和q[i+1]的交点
    Line *q=new Line[n]; //双端队列
    q[first=last=0]=L[0]; //双端队列初始化为只有一个半平面 L[0]
    for(int i=1;i<n;i++){
        while(first<last&&!OnLeft(L[i],p[last-1]))last--;
        while(first<last&&!OnLeft(L[i],p[first])) first++;
        q[++last]=L[i];
        if(fabs(Cross(q[last].v,q[last-1].v))<eps) {//两个向量平行且相同，取内侧 的一个
            last--;
            if(OnLeft(q[last],L[i].P)) q[last]=L[i];
        }
        if(first<last) p[last-1]=GetIntersction(q[last-1],q[last]);
    }
    while(first<last&&!OnLeft(q[first],p[last-1]))last--;
    if(last-first<=1) return 0;// 空集
    p[last]=GetIntersction(q[last],q[first]); //计算首尾两个半平面的交点

    //从deque复制到输出中
    int m=0;
    for(int i=first;i<=last;i++) poly[m++]=p[i];
    return m;
}
int main(){}