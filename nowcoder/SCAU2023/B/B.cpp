#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> dfn_in,dfn_out;
int dfn_cnt;

void dfs(int u,int fa){
    dfn_in[u]=++dfn_cnt;
    for(int i=0;i<G[u].size();i++){
        int& v=G[u][i];
        if(v==fa) continue;
        dfs(v,u);
    }
    dfn_out[u]=dfn_cnt;
}

struct tree{
    int n;
    vector<int> c;
    tree(int x){this->n=x+1;c.assign(this->n+1,0);}
    void add(int x,int v){
        for(;x<=n;x+=x&-x) c[x]+=v;
    }
    int query(int x){
        int ans=0;
        for(;x;x-=x&-x) ans+=c[x];
        return ans;
    }
};

int main(){
    freopen("B.in","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    vector<tree> t(61,tree(n));
    vector<int> a(n+1);
    G.assign(n+1,vector<int>());
    dfn_in.assign(n+1,0); dfn_out.assign(n+1,0);

    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(int i=1;i<n;i++){
        int u,v;scanf("%d%d",&u,&v);
        G[v].push_back(u);
        G[u].push_back(v);
    }
    

    dfs(1,-1);

    for(int i=1;i<=n;i++)
        t[a[i]].add(dfn_in[i],1);

    while(m--){
        int op;scanf("%d",&op);
        if(op==1){
            int x,y;scanf("%d%d",&x,&y);int c=a[x];
            t[c].add(dfn_in[x],-1);
            t[y].add(dfn_in[x],1);
            a[x]=y;
        }
        else{
            int x,L,R;scanf("%d%d%d",&x,&L,&R);
            int ans=0;
            for(int i=L;i<=R;i++){
                ans+=t[i].query(dfn_out[x])-t[i].query(dfn_in[x]-1);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}