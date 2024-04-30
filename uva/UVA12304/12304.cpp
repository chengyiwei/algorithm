#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
const double PI=3.1415926;

struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){};
};

typedef Point Vector;

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

//向量逆时针旋转 rad
Vector Rotate(Vector A,double rad){return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));} //rad是弧度

struct Line {
    Point p;
    Vector v;
    Point point(double t){
        return p+v*t;
    }
};

struct Circle{
    Point c;
    double r;
    Circle(Point c,double r):c(c),r(r){}
    Point point(double a){return Point(c.x+cos(a)*r,c.y+sin(a)*r);} //根据圆心角求坐标
};

int getLineCircleIntersection(Line L,Circle C,double& t1,double& t2,vector<Point>& sol){
    double a=L.v.x,b=L.p.x-C.c.x,c=L.v.y,d=L.p.y-C.c.y;
    double e=a*a+c*c,f=2*(a*b+c*d),g=b*b+d*d-C.r*C.r;
    double delta=f*f-4*e*g;
    if(dcmp(delta)<0) return 0;
    if(dcmp(delta)==0) {
        t1=t2=-f/(2*e); sol.push_back(L.point(t1));
        return 1;
    }
    t1=(-f-sqrt(delta))/(2*e);sol.push_back(L.point(t1));
    t2=(-f+sqrt(delta))/(2*e);sol.push_back(L.point(t2));
    return 2;
}

double angle(Vector v) {return atan2(v.y,v.x);} //求极角，注意不要错用 atan 了

//求两圆交点
int getCircleCircleIntersection(Circle C1,Circle C2,vector<Point>& sol){
    double d=Length(C1.c-C2.c);
    if(dcmp(d)==0){
        if(dcmp(C1.r-C2.r)==0) return -1; //两圆重合
        return 0;
    }
    if(dcmp(C1.r+C2.r-d)<0) return 0;  //相离
    if(dcmp(fabs(C1.r-C2.r)-d)) return 0; //包含

    double a=angle(C2.c-C1.c); //向量C1C2的极角
    double da=acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d)); //余弦定理 C1C2到C1P1 的角
    Point p1=C1.point(a-da),p2=C1.point(a+da);
    
    sol.push_back(p1);
    if(p1==p2) return 1;
    sol.push_back(p2);
    return 2;
}

int getTangents(Point p,Circle C,Vector* v){
    Vector u=C.c-p;
    double dist=Length(u);
    if(dist<C.r) return 0; //没有切线
    else if(dcmp(dist-C.r)==0) { // p 在圆上，只有一条切线
        v[0]=Rotate(u,PI/2);  //逆时针旋转90°
        return 1;
    }
    else{ //两个切线
        double ang=asin(C.r/dist);
        v[0]=Rotate(u,-ang);
        v[1]=Rotate(u,+ang);
        return 2;
    }
}

//返回切线的条数。-1表示无穷条切线
//a[i]和b[i]分别是第i条切线在圆A和圆B上的切点
int getTangents(Circle A,Circle B,Point* a,Point* b){
    int cnt=0;
    if(A.r<B.r){swap(A,B);swap(a,b);} //A的半径要大于 B的半径
    int d2=(A.c.x-B.c.x)*(A.c.x-B.c.x)+(A.c.y-B.c.y)*(A.c.y*B.c.y);
    int rdiff=A.r-B.r,rsum=A.r+B.r;
    if(d2<rdiff*rdiff) return 0; //内含
    
    double base=atan2(B.c.y-A.c.y,B.c.x-A.c.x);
    if(d2==0&&A.r==B.r) return -1;
    if(d2==rdiff*rdiff){ //内切 1条切线
        a[cnt]=A.point(base); b[cnt]=B.point(base);cnt++;
        return 1;
    }
    
    //有外公切线
    double ang=acos((A.r-B.r)/sqrt(d2));
    a[cnt]=A.point(base+ang);b[cnt]=B.point(base+ang);cnt++;
    a[cnt]=A.point(base-ang);b[cnt]=B.point(base-ang);cnt++;
    
    if(d2==rsum*rsum){  //一条内公切线
        a[cnt]=A.point(base);b[cnt]=B.point(PI+base);cnt++;
    }
    else if(d2>rsum*rsum){  //两条内公切线
        double ang=acos((A.r+B.r)/sqrt(d2));
        a[cnt]=A.point(base+ang);b[cnt]=B.point(PI+base+ang);cnt++;
        a[cnt]=A.point(base-ang);b[cnt]=B.point(PI+base-ang);cnt++;
    }
    return cnt;
}

int main(){
    freopen("12304.in","r",stdin);
    freopen("12304.out","w",stdout);
    string s;
    
}