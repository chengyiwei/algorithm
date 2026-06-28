#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int N,M,a[maxn],b[maxn];
vector<int> E[maxn];
int vis[maxn];

void dfs(int x,int val){
    vis[x]=val;
    int len=E[x].size();
    for(int j=0;j<len;j++){
        int son=E[x].at(j);
        if(vis[son]==val) {printf("No\n");exit(0);}
        if(!vis[son])dfs(son,-val);
    }
}
int main(){
    freopen("D.in","r",stdin);
    cin>>N>>M;
    for(int i=1;i<=M;i++)cin>>a[i];
    for(int i=1;i<=M;i++)cin>>b[i];
    for(int i=1;i<=M;i++){
        E[a[i]].push_back(b[i]);
        E[b[i]].push_back(a[i]);
    }
    for(int i=1;i<=N;i++)if(!vis[i]){
        dfs(i,1);
    }
    printf("Yes\n");
    return 0;
}