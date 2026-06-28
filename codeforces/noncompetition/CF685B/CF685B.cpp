#include<bits/stdc++.h>
using namespace std;
int N,Q;
vector<int> fa;
vector<vector<int> > E;
vector<int> siz,ans,weight; //siz是子树大小，ans是以i为根的子树重心，weight是结点重量

void DFS(int u,int f=-1){
    siz[u]=1,ans[u]=u;
    for(int& v:E[u]){
        if(v==f) continue;
        DFS(v,u);
        siz[u]+=siz[v];
        weight[u]=max(weight[u],weight[v]);
    }
    for(int& v:E[u]){  //树的重心肯定存在于所有儿子的重心到 u 的连线上
        int p=ans[v];  
        while(p!=u){
            if(max(weight[p],siz[u]-siz[p])<=siz[u]/2){  //满足重心的条件了
                ans[u]=p;
                break;
            }
            else
                p=fa[p]; //不满足，就向上跳
        }
    }
}

int main(){
    freopen("CF685B.in","r",stdin);
    cin>>N>>Q;
    fa.resize(N+1);E.resize(N+1,vector<int>());
    siz.resize(N+1,0),ans.resize(N+1,0),weight.resize(N+1,0);
    for(int i=2;i<=N;i++){
        cin>>fa[i];
        E[fa[i]].push_back(i);
    }
    DFS(1);
    while(Q--){
        int x;
        cin>>x;
        cout<<ans[x]<<'\n';
    }
    return 0;
}