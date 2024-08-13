#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > E;
struct Tarjan{
    int n;
    vector<int> dfn,low;int dfn_cnt;
    vector<int> cut;//存储所有割点

    void init(int n){
        this->n=n;
        dfn.resize(n+1);low.resize(n+1);
        dfn_cnt=0;cut.clear();
    }

    void tarjan(int u,bool root=1,int fa=-1){
        int tot=0;
        dfn[u]=low[u]=++dfn_cnt;
        for(int& v:E[u]){
            if(!dfn[v]){ //没有遍历过
                tarjan(v,0,u);
                low[u]=min(low[u],low[v]);
                tot+=(low[v]>=dfn[u]); 
            }
            else if(v!=fa)
                low[u]=min(low[u],dfn[v]);
        }
        if(tot>root) // 如果是根，tot需要大于1；否则只需大于0
            cut.push_back(u);
        return ;
    }
};
int main(){
    freopen("P3388.in","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    E.resize(n+1,vector<int>());
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        E[x].push_back(y);E[y].push_back(x);
    }
    Tarjan F;F.init(n);
    for(int i=1;i<=n;i++)if(!F.dfn[i]){
        F.dfn_cnt=0;
        F.tarjan(i);
    }
    printf("%d\n",F.cut.size());
    sort(F.cut.begin(),F.cut.end());
    for(auto& x:F.cut)
        printf("%d ",x);
    return 0;
}