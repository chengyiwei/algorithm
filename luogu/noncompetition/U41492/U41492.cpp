#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;

int n;
vector<int> G[maxn];

int siz[maxn],big_son[maxn],col[maxn],dfn_in[maxn],dfn_ou[maxn],rk[maxn],cnt_dfn;
int ans[maxn],cnt[maxn],totcolor;

void add(int u){
    if(cnt[col[u]]==0) ++totcolor;
    cnt[col[u]]++;
}

void del(int u){
    cnt[col[u]]--;
    if(cnt[col[u]]==0) --totcolor;
}

void dfs_1(int u,int fa){
    dfn_in[u]=++cnt_dfn; rk[cnt_dfn]=u;
    siz[u]=1;
    for(int& v:G[u]){
        if(v!=fa){
            dfs_1(v,u);
            siz[u]+=siz[v];
            if(!big_son[u]||siz[big_son[u]]<siz[v]) big_son[u]=v;
        }
    }
    dfn_ou[u]=cnt_dfn;
}

void dfs_2(int u,int fa,bool keep){
    for(int& v:G[u])
        if(v!=fa&&v!=big_son[u])
            dfs_2(v,u,false);
    if(big_son[u])
        dfs_2(big_son[u],u,true);
    for(int& v:G[u])
        if(v!=fa&&v!=big_son[u]){
            for(int i=dfn_in[v];i<=dfn_ou[v];i++)
                add(rk[i]);
        }
    add(u);
    ans[u]=totcolor;
    if(keep==false){
        for(int i=dfn_in[u];i<=dfn_ou[u];i++){
            del(rk[i]);
        }
    }
}

int main(){
    freopen("U41492.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&col[i]);
    dfs_1(1,0);
    dfs_2(1,0,false);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}