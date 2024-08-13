#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > E;
struct Tarjan{
    int n;
    vector<int> dfn,low;int dfn_cnt;
    vector<pair<int,int> > cnt_bridge;//存储所有割点

    void init(int n){
        this->n=n;
        dfn.resize(n+1);low.resize(n+1);
        dfn_cnt=0;cnt_bridge.clear();
    }

    void tarjan(int u,int fa=-1){
        dfn[u]=low[u]=++dfn_cnt;
        for(int& v:E[u]){
            if(!dfn[v]){ //没有遍历过
                tarjan(v,u);
                low[u]=min(low[u],low[v]);
                if(low[v]>dfn[u]){ //割边为 u-v
                    cnt_bridge.push_back(make_pair(u,v));
                }
            }
            else if(v!=fa)
                low[u]=min(low[u],dfn[v]);
        }
        return ;
    }
};
int main(){
}