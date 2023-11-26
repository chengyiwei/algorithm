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
double Cross(Vector A,Vector B) {return A.x*B.y-A.y*B.x;} //叉积

Vector Normal(Vector A){double L=Length(A);return Vector(-A.y/L,A.x/L);}

//点 p 在有向直线 L 的左边(线上不算)
bool OnLeft(Line L,Point p){
    return Cross(L.v,p-L.P)>0;
}

Point GetIntersction(Line a,Line b){//二直线交点，假定交点唯一存在
    Vector u=a.P-b.P;
    double t=Cross(b.v,u)/Cross(a.v,b.v);
    return a.P+a.v*t;
}

int HalfplanIntersection(Line *L,int n,Point* poly){
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


Point p[205],poly[205];
Line L[205];
Vector v[205],v2[205];

int main(){
    // freopen("1396.in","r",stdin);
    int n;
    while(scanf("%d",&n)==1&&n){
        int m,x,y;
        for(int i=0;i<n;i++) {scanf("%d%d",&x,&y);p[i]=Point(x,y);}
        for(int i=0;i<n;i++){
            v[i]=p[(i+1)%n]-p[i];
            v2[i]=Normal(v[i]);
        }
        double left=0,right=20000;
        while(right-left>1e-8){
            double mid=left+(right-left)/2;
            for(int i=0;i<n;i++) L[i]=Line(p[i]+v2[i]*mid,v[i]);

            m=HalfplanIntersection(L,n,poly);
            if(!m) right=mid;
            else left=mid;
        }
        printf("%.6lf\n",left);
    }
    return 0;
}