#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const double INF=1e5,eps=1e-12;
int n;
double ans;
vector<int> a;
vector<vector<int> > G;
vector<double> c,F;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
bool flg=0;

bool cmp(double a,double b){
    return fabs(a-b)<=eps;
}

void dfs_1(int u,int fa){
    if(flg==1) return ;
    F[u]=c[u];
    double p1=-INF,p2=-INF;
    for(int& v:G[u]){
        if(v==fa)continue;
        dfs_1(v,u);
        F[u]=max(F[u],F[v]+c[u]);
        if(p1==-INF||F[v]>p1||cmp(F[v],p1))
            p2=p1,p1=F[v];
        else {
            if(p2==-INF||F[v]>p2||cmp(F[v],p2)) p2=F[v];
        }
    }
    if(p1!=-INF) 
        if(p1+c[u]>0||cmp(p1+c[u],0)) {flg=1;return ;}
    if(p2!=-INF)
        if(p1+p2+c[u]>0||cmp(p1+p2+c[u],0)) {flg=1;return ;}
}

bool check(double mid){
    for(int i=1;i<=n;i++) c[i]=(double)a[i]-mid;
    flg=0;
    dfs_1(1,-1);
    return flg;
}

int main(){
    freopen("F.in","r",stdin);
    freopen("F1.out","w",stdout);
    n=read();
    
    a.assign(n+1,0);G.assign(n+1,vector<int>());c.assign(n+1,0); F.assign(n+1,0);

    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<n;i++){
        int u,v;u=read();v=read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    double L=0,R=INF;
    
    double ans1=-INF;
    while(abs(R-L)>=1e-10){
        double mid=(R+L)/2;
        if(check(mid)) {L=mid;}
        else R=mid;
    }
    ans1=L;
    
    for(int i=1;i<=n;i++) a[i]=-a[i];
    L=0,R=INF;
    double ans2=-INF;

    while(abs(R-L)>=1e-10){
        double mid=(R+L)/2;
        if(check(mid)) {L=mid;}
        else R=mid;
    }
    ans2=L;

    ans=max(fabs(ans1),fabs(ans2));
    // printf("%.6lf %.6lf\n",ans1,ans2);
    printf("%.4lf\n",ans*ans/4);
    cout<<clock()<<endl;
    return 0;
}