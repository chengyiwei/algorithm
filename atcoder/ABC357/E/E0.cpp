
#include <bits/stdc++.h>
using namespace std;

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

int main() {
    int n, m;   cin >> n >> m;
    E.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;   cin >> u >> v;
        E[u].push_back(v);
    }
    Tarjan tarjan;
    tarjan.init(n);
    for (int i = 1; i <= n; i++) {
        if (!tarjan.dfn[i]) {
            tarjan.tarjan(i);
        }
    }
    cout << tarjan.sc << endl;
}