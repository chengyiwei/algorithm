#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,q;
vector<vector<int> > G;
vector<int> T,lst;
void DFS(int u,int tim){
    lst[u]=tim+T[u];
    for(int i=0;i<G[u].size();i++){
        int& v=G[u][i];
        DFS(v,lst[u]);
    }
}
int main(){
    freopen("E.in","r",stdin);
    scanf("%d%d",&n,&q);
    G.assign(n+1,vector<int>()); T.assign(n+1,0); lst.assign(n+1,-1);
    for(int i=1;i<=n;i++){
        int x,t;scanf("%d%d",&x,&t);
        G[x].push_back(i);T[i]=t;
    }
    DFS(0,0);
    while(q--){
        int d,x;
        scanf("%d%d",&d,&x);
        if(lst[x]==-1) {printf("Stay\n");continue;}
        if(lst[x]<=d) printf("Holiday\n");
        else printf("Stay\n");
    }
    return 0;
}