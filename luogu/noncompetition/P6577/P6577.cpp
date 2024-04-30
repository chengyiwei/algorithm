#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long LL;
const int INF=1ll<<60;
struct KM{
    int n;
    vector<vector<int> > E;
    vector<int> lx,ly,py,vx,vy;
    int d;

    void init(int n){
        this->n=n;
        E.resize(n+1);
        for(auto& e:E) e.assign(n+1,-INF);
        lx.assign(n+1,-INF);ly.assign(n+1,0);py.assign(n+1,0);
        vx.assign(n+1,0);vy.assign(n+1,0);
    }

    bool DFS(int u){
        vx[u]=1;
        for(int i=1;i<=n;i++)if(!vy[i]){
            if(lx[u]+ly[i]==E[u][i]){ //在相等子图中
                vy[i]=1;
                if(!py[i]||DFS(py[i])){
                    py[i]=u;vy[i]=1;
                    return 1;
                }
            }
            else d=min(d,lx[u]+ly[i]-E[u][i]);
        }
        return 0;
    }

    void km(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                lx[i]=max(lx[i],E[i][j]);
        }
        for(int i=1;i<=n;i++){
            while(true){
                d=INF;vx.assign(n+1,0);vy.assign(n+1,0);
                if(DFS(i))break;  //如果能匹配就不缩小子图
                for(int j=1;j<=n;j++){
                    if(vx[j])lx[j]-=d;
                    if(vy[j])ly[j]+=d;
                }
            }
        }
    }
};
signed main(){
    freopen("P6577.in","r",stdin);
    int n,m;
    scanf("%lld%lld",&n,&m);
    KM F;F.init(n);
    for(int i=1;i<=m;i++){
        int x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        F.E[x][y]=z;
    }
    F.km();
    LL ans=0;
    for(int i=1;i<=n;i++)
        ans=ans+F.E[F.py[i]][i];
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)
        printf("%lld ",F.py[i]);
    return 0;
}