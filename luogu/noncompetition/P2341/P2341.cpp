#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int cnt;
vector<vector<int> > E;
struct Tarjan{
    int n;
    vector<int>dfn,low;int dfn_cnt;
    vector<int> scc;int sc; //节点 i 所在 SCC 的编号
    vector<int> siz; //强连通 i 的大小
    stack<int> st;
    vector<int> in_st;//判断是否在栈内

    void init(int n){
        this->n=n;
        dfn.resize(n+1);low.resize(n+1);dfn_cnt=0;
        scc.assign(n+1,0);sc=0;siz.assign(n+1,0);
        while(!st.empty())st.pop();
        in_st.assign(n+1,0);
    }

    void tarjan(int u){
        low[u]=dfn[u]=++dfn_cnt;st.push(u);in_st[u]=1;
        for(int i=0;i<E[u].size();i++){
            int& v=E[u][i];
            if(!dfn[v]){//没有访问过
                tarjan(v);
                low[u]=min(low[u],low[v]);
            }else if(in_st[v]){
                low[u]=min(low[u],dfn[v]);
            }
        }
        if(dfn[u]==low[u]){ //找到双连通分量了
            ++sc; 
            while(st.top()!=u){ //从栈顶到 u 都是这个强连通分量里面的
                scc[st.top()]=sc;siz[sc]++;
                in_st[st.top()]=0;st.pop();
            }
            scc[st.top()]=sc;siz[sc]++;
            in_st[st.top()]=0;st.pop();
        }
        return ;
    }
};
int main(){
    freopen("P2341.in","r",stdin);
    scanf("%d %d\n",&n,&m);
    E.resize(n+1);
    for(auto& e:E) e.clear();
    for(int i=1;i<=m;i++){
        int x,y;scanf("%d%d",&x,&y);
        E[x].push_back(y);
    }

    Tarjan F;F.init(n);
    for(int i=1;i<=n;i++) if(!F.dfn[i]){
        F.dfn_cnt=0;
        F.tarjan(i);
    }

    vector<int> du(n+1,0);
    for(int u=1;u<=n;u++)
        for(int& v:E[u]){
            if(F.scc[u]!=F.scc[v]){
                du[F.scc[u]]++;
            }
        }
    for(int i=1;i<=F.sc;i++)
        if(du[i]==0){
            cnt++;
            ans+=F.siz[i];
        }
    if(cnt==1) printf("%d\n",ans);
    else printf("0\n");
    return 0;
}