#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
const int INF=1ll<<60;
struct KM_BFS{
    int n;
    vector<vector<int> > E;
    vector<int> lx,ly,slack,py,px,pre;
    vector<bool> vx,vy;

    void init(int n){
        this->n=n;
        E.resize(n+1);
        for(auto& e:E) e.assign(n+1,-INF);
        lx.assign(n+1,-INF);ly.assign(n+1,0);
        px.assign(n+1,0);py.assign(n+1,0);
    }

    void aug(int v){  //回去找匹配
        int t;
        while(v){
            t=px[pre[v]];
            px[pre[v]]=v;
            py[v]=pre[v];
            v=t;
        }
    }

    void BFS(int st){
        pre.assign(n+1,0);slack.assign(n+1,INF);
        vx.assign(n+1,0);vy.assign(n+1,0);
        queue<int> Q;
        Q.push(st);
        while(1){
            while(!Q.empty()){
                int u=Q.front();Q.pop();
                vx[u]=1;
                for(int i=1;i<=n;i++) if(!vy[i]){
                    if(lx[u]+ly[i]-E[u][i]<slack[i]){
                        slack[i]=lx[u]+ly[i]-E[u][i];
                        pre[i]=u;
                        if(slack[i]==0){  //在相等子图内
                            vy[i]=1;
                            if(!py[i]){aug(i);return ;} //有空的没匹配，那就匹配
                            else Q.push(py[i]); //把 i 的匹配的那个放到队列中，看能不能匹配上
                        }
                    }
                }
            }
            int d=INF;
            for(int i=1;i<=n;i++) 
                if(!vy[i]) d=min(d,slack[i]);
            for(int i=1;i<=n;i++){ //扩大子图
                if(vx[i]) lx[i]-=d;
                if(vy[i]) ly[i]+=d;else slack[i]-=d;
            }
            for(int i=1;i<=n;i++) if(!vy[i]){
                if(slack[i]==0){ //vy=0 且 slack[i]=0 表示新加进来的哪些 点
                    vy[i]=1;
                    if(!py[i]) {aug(i);return ;}//有空的没匹配，那就匹配
                    else Q.push(py[i]); //把 i 的匹配的那个放到队列中，看能不能匹配上
                }
            }
        }
    }

    void km(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                lx[i]=max(lx[i],E[i][j]);
        }

        for(int i=1;i<=n;i++){
            BFS(i);
        }
    }
};
signed main(){
    freopen("P6577.in","r",stdin);
    int n,m;
    scanf("%lld%lld",&n,&m);
    KM_BFS F;F.init(n);
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