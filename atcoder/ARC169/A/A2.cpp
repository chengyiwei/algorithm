#include<bits/stdc++.h>
using namespace std;
const int maxn=24;
typedef long long LL;
LL a[maxn],ans;
vector<int> G[maxn];
LL vis[maxn];
int p[maxn];
int dep[maxn];
void DFS(int x,int dp){
    dep[x]=dp;
    for(auto v:G[x]){
        DFS(v,dp+1);
    }
}
int main(){
    freopen("A.in","r",stdin);
    freopen("A2.out","w",stdout);
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%lld",&a[i]);
    for(int i=2;i<=N;i++){
        scanf("%d",&p[i]);
        G[p[i]].push_back(i);
    }
    DFS(1,0);
    for(int i=2;i<=N;i++)
        vis[dep[i]]+=a[i];
    for(int i=N;i>=1;i--){
        if(vis[i]!=0){
            if(vis[i]>0)
                {printf("+\n");return 0;}
            else 
                {printf("-\n");return 0;}
        }
    }
    if(a[1]>0)
        {printf("+\n");return 0;}
    else if(a[1]<0)
        {printf("-\n");return 0;}
    else 
        {printf("0\n");return 0;}
    return 0;
}