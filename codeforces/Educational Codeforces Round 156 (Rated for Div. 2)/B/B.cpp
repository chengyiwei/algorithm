#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int T;
double Px,Py,Ax,Ay,Bx,By;
bool check_C_P(double x,double y,double R,double Px,double Py){
    return (Px-x)*(Px-x)+(Py-y)*(Py-y)<R*R;
}
bool check_C_C(double Ax,double Ay,double Bx,double By,double R){
    return (Ax-Bx)*(Ax-Bx)+(Ay-By)*(Ay-By)<(R*2)*(R*2);
}
bool check(double R){
    if(check_C_P(Ax,Ay,R,0,0)&&check_C_P(Ax,Ay,R,Px,Py)) return 1;
    if(check_C_P(Bx,By,R,0,0)&&check_C_P(Bx,By,R,Px,Py)) return 1;
    if(check_C_C(Ax,Ay,Bx,By,R)){
        if(check_C_P(Ax,Ay,R,0,0)&&check_C_P(Bx,By,R,Px,Py)) return 1;
        if(check_C_P(Bx,By,R,0,0)&&check_C_P(Ax,Ay,R,Px,Py)) return 1;
    }
    return 0;
}
int main(){
    // freopen("B.in","r",stdin);
    // freopen("B.out","w",stdout);
    T=read();
    while(T--){
        Px=read(),Py=read(),Ax=read(),Ay=read(),Bx=read(),By=read();
        double L=0,R=5e3,ans=R,mid;
        while(abs(R-L)>1e-9){
            mid=(R+L)/2;
            if(check(mid)){
                ans=min(ans,mid);R=mid;
            }
            else L=mid;
        }
        printf("%.6lf\n",ans);
    }
    return 0;
}