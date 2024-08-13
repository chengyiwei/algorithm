#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const double INF=1e5,eps=1e-12;
int n;
double ans;
vector<int> a,fa,vs;
vector<vector<int> > G;
vector<double> c,F;

inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

void dfs(int x,int f){
    fa[x]=f;
    for(auto v:G[x]) if(v!=f) dfs(v,x);
    vs.push_back(x);
}


bool check(double mid){
    for(auto x:vs){
        F[x]=-1e100;
        c[x]=a[x]-mid;
        for(auto v:G[x]) if(v!=fa[x]){
            F[x]=max(F[x],c[x]+c[v]);
            c[x]=max(c[x],c[v]+a[x]-mid);
            F[x]=max(F[x],F[v]);
        }
    }
    return F[1]>=0;
}

int main(){
    freopen("F.in","r",stdin);
    freopen("F.out","w",stdout);
    n=read();
    
    a.assign(n+1,0);G.assign(n+1,vector<int>());c.assign(n+1,0); F.assign(n+1,0); fa.assign(n+1,0);

    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<n;i++){
        int u,v;u=read();v=read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,0);
    
    check(3);

    double L=0,R=INF;
    double ans1=-INF;
    for(int i=1;i<=60;i++){
        double mid=(R+L)/2;
        if(check(mid)) {L=mid;}
        else R=mid;
    }
    ans1=L;
    
    for(int i=1;i<=n;i++) a[i]=-a[i];
    
    L=0,R=INF;
    double ans2=-INF;
    for(int i=1;i<=60;i++){
        double mid=(R+L)/2;
        if(check(mid)) {L=mid;}
        else R=mid;
    }
    ans2=L;

    ans=max(fabs(ans1),fabs(ans2));
    // printf("%.6lf %.6lf\n",ans1,ans2);
    printf("%.4lf\n",ans*ans/4);
    // cout<<clock()<<endl;
    return 0;
}