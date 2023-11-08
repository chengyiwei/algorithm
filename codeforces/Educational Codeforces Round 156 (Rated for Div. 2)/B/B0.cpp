#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int T;
double Px,Py;
struct pos
{
    double x,y;
}A,B,P;
double sq(pos a,pos b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double One(pos X){
    return max(sq(X,(pos){0,0}),sq(X,P));
}
double Two(pos X,pos Y){
    return max(sq(X,(pos){0,0}),max(sq(Y,P),sq(X,Y)/2));
}
int main(){
    freopen("B.in","r",stdin);
    freopen("B0.out","w",stdout);
    T=read();
    while(T--){
        P.x=read(),P.y=read(),A.x=read(),A.y=read(),B.x=read(),B.y=read();
        double ans=min(min(One(A),One(B)),min(Two(A,B),Two(B,A)));
        printf("%.6lf\n",ans);
    }
    return 0;
}