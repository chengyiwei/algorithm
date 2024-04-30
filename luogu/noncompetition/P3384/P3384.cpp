#include<bits/stdc++.h>
using namespace std;

struct  node{
    int son,w,id,dep,siz,top,fa;
    vector<int> G;
};
vector<node> c;
int tot;

vector<int> rk;

void dfs_1(int u,int f,int dp){
    c[u].dep=dp;c[u].fa=f;c[u].siz=1;
    int max_son=-1;
    for(auto& v:G){
        if(v==fa) continue;
        dfs_1(v,u,dp+1);
        c[u].siz+=c[v].siz;
        if(siz[v]>max_son){max_son=siz[v],c[u].son=v;}
    }
}

void dfs_2(int u,int tp){
    c[u].id=++tot;rk[tot]=x;c[u].top=tp;
    if(c[u].son) dfs_2(c[u].son,tp);
    for(auto& v:c[u].E){
        if(v==c[u].fa||v==c[u].son) continue;
        dfs_2(v,v);
    }
}

int main(){
    freopen("P3384.in","r",stdin);
    
}