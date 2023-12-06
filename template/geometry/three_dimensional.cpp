#include<bits/stdc++.h>
using namespace std;

const double eps=1e-9;
struct Point3{
    double x,y,z;
    Point3(double x=0,double y=0,double z=0):x(x),y(y),z(z){}
};
typedef Point3 Vector3;


Vector3 operator +(Vector3 A,Vector3 B) {return Vector3(A.x+B.x,A.y+B.y,A.z+B.z);}
Vector3 operator -(Point3 A,Point3 B) {return Vector3(A.x-B.x,A.y-B.y,A.z-B.z);}
Vector3 operator *(Vector3 A,double p) {return Vector3(A.x*p,A.y*p,A.z*p);}
Vector3 operator /(Vector3 A,double p) {return Vector3(A.x/p,A.y/p,A.z/p);}
int dcmp(double x){if(fabs(x)<eps) return 0;else return x<0?-1:1;}  //自定义比较函数
bool operator ==(const Point3 &a,const Point3 &b){return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0 && dcmp(a.z-b.z)==0;}
double Dot(Vector3 A,Vector3 B) {return A.x*B.x+A.y*B.y+A.z*B.z;}
double Length(Vector3 A) {return sqrt(Dot(A,A));}
double Angle(Vector3 A,Vector3 B) {return acos(Dot(A,B)/Length(A)/Length(B));}
double DistanceToPlane(Point3 p,Point3 p0,Vector3 n){return fabs(Dot(p-p0,n))/Length(n);}//点 p 到平面 p0-n 的距离，如果不取绝对值，得到的是有向距离
Vector3 Cross(Vector3 A, Vector3 B) {return Vector3(A.y*B.z-A.z*B.y,A.z*B.x-A.x*B.z,A.x*B.y-A.y*B.x);}
double Area2(Point3 A,Point3 B,Point3 C) {return Length(Cross(B-A,C-A));}
Point3 GetPlaneProjection(Point3 p,Point3 p0,Vector3 n){//点在平面上的投影
    double d=Dot(p-p0,n)/Length(n);
    return p-n*d;
}
Point3 LinePlaneIntersection(Point3 p1,Point3 p2,Point3 p0,Vector3 n){
    Vector3 v=p2-p1;
    double t=(Dot(n,p0-p1)/Dot(n,p2-p1));
    return p1+v*t;
}
bool PointInTri(Point3 P,Point3 P0,Point3 P1,Point3 P2){//点p在▲P0P1P2中
    double area1=Area2(P,P0,P1),area2=Area2(P,P1,P2),area3=Area2(P,P2,P0);
    return dcmp(area1+area2+area3-Area2(P0,P1,P2))==0;
}
bool TriSegIntersection(Point3 P0,Point3 P1,Point3 P2,Point3 A,Point3 B,Point3& P){//▲P0P1P2是否和线段AB相交
    Vector3 n=Cross(P1-P0,P2-P0);
    if(dcmp(Dot(n,B-A))==0) return false; //线段 AB 和平面 P0P1P2 平行或共面
    else{
        double t=Dot(n,P0-A)/Dot(n,B-A);
        if(dcmp(t)<0||dcmp(t-1)>0) return false; //交点不在线段AB上
        P=A+(B-A)*t;  //计算交点
        return PointInTri(P,P0,P1,P2);  //判断交点是否在三角形 P0-P1-P2 内
    }
}
double DistanceToLine(Point3 P,Point3 A,Point3 B){//点P到直线AB的距离
    Vector3 v1=B-A,v2=P-A;
    return Length(Cross(v1,v2))/Length(v1);
}
double DistanceToSegment(Point3 P,Point3 A,Point3 B){//点P到线段AB的距离
    if(A==B) return Length(P-A);
    Vector3 v1=B-A,v2=P-A,v3=P-B;
    if(dcmp(Dot(v1,v2))<0) return Length(v2);
    else if(dcmp(Dot(v1,v3))>0) return Length(v3);
    else return Length(Cross(v1,v2))/Length(v1);
}
double Volume6(Point3 A,Point3 B,Point3 C,Point3 D){return Dot(D-A,Cross(B-A,C-A));} //返回AB，AC，AD的混合积。它也等于四面体ABCD的有向面积的6倍

struct Face{
    int v[3]; //v表示三个点的序号
    Vector3 normal(Point3 *P) const{return Cross(P[v[1]]-P[v[0]],P[v[2]]-P[v[0]]);}
    int cansee(Point3 *P,int i) const{return Dot(P[i]-P[v[0]],normal(P))>0?1:0;} //i能不能看到P这个平面
};

int vis[505][505];
//没有考虑各种特殊情况(如4点共面，实践中要在表用前堆输入点进行微小扰动)
double rand01() {return rand()/(double)RAND_MAX;}  
double randeps() {return (rand01()-0.5)*eps;} //-eps/2到eps/2的随机数
Point3 add_noise(Point3 p){return Point3(p.x+randeps(),p.y+randeps(),p.z+randeps());}
vector<Face> CH3D(Point3 *P,int n){
    vector<Face> cur; //cur表示现在选中在凸包里面的面、
    cur.push_back((Face){{0,1,2}});
    cur.push_back((Face){{2,1,0}});
    for(int i=3;i<n;i++){
        vector<Face> next;
        for(int j=0;j<cur.size();j++){
            Face& f=cur[j];
            int res=f.cansee(P,i);
            if(!res) next.push_back(f); //如果不能看见，则不管
            for(int k=0;k<3;k++) //如果能看见，把这个面的每一条边标记
                vis[f.v[k]][f.v[(k+1)%3]]=res;
        }
        for(int j=0;j<cur.size();j++)
            for(int k=0;k<3;k++){
                int a=cur[j].v[k],b=cur[k].v[(k+1)%3];
                if(vis[a][b]!=vis[b][a]&&vis[a][b])  //如果一个边，只有相邻的一个平面被标记，那么这个边就被选中
                    next.push_back((Face){{a,b,i}});
            }
        cur=next;
    }
    return cur;
}
int main(){}