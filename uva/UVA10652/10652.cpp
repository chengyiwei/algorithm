#include<bits/stdc++.h>
using namespace std;

const double eps=1e-9;
const double PI=3.14159;
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){};
};

typedef Point Vector;

Vector operator + (Vector A,Vector B) {return Vector{A.x+B.x,A.y+B.y};} //向量+向量=向量
Vector operator - (Point A,Point B) {return Vector{A.x-B.x,A.y-B.y};} //点-点=向量
Vector operator * (Vector A,double p) {return Vector{A.x*p,A.y*p};} //向量*数=向量
Vector operator / (Vector A,double p) {return Vector{A.x/p,A.y/p};} //向量/数=向量

//向量逆时针旋转 rad
Vector Rotate(Vector A,double rad){return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));} //rad是弧度
double Dot(Vector A,Vector B) {return A.x*B.x+A.y*B.y;}  //典籍
double Length(Vector A) {return sqrt(Dot(A,A));}  //长度
double Angle(Vector A,Vector B) {return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vector A,Vector B) {return A.x*B.y-A.y*B.x;} //叉积
int dcmp(double x){if(fabs(x)<eps) return 0;else return x<0?-1:1;}  //自定义比较函数
double ConvexPolgonArea(Point *p,int n){
    double area=0;
    for(int i=1;i<n-1;i++)
        area += Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}
bool cmp(Point A,Point B){return A.x<B.x||(dcmp(A.x-B.x)==0&&A.y<B.y);}
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
double torad(double degrees) {return degrees*PI/180.0;}
int main(){
    freopen("10652.in","r",stdin);
    int T;
    Point P[2500],ch[2500];
    scanf("%d",&T);
    while(T--){
        int n,pc=0;
        double area1=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            double x,y,w,h,j,ang;
            scanf("%lf%lf%lf%lf%lf",&x,&y,&w,&h,&j);
            Point o(x,y);
            ang=-torad(j);
            P[pc++]=o+Rotate(Vector(-w/2,-h/2),ang);
            P[pc++]=o+Rotate(Vector(w/2,-h/2),ang);
            P[pc++]=o+Rotate(Vector(-w/2,h/2),ang);
            P[pc++]=o+Rotate(Vector(w/2,h/2),ang);
            area1+=w*h;
        }
        sort(P,P+n,cmp);
        int m=ConvexHull(P,pc,ch);
        double area2=ConvexPolgonArea(ch,m);
        printf("%.1lf %%\n",area1*100/area2);
    }
    return 0;
}