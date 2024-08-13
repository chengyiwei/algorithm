#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
const int INF=2e9;
typedef long long LL;
int N;
int ans[maxn],a[maxn][maxn];
int Max[maxn][maxn],Min[maxn][maxn];
void dfs(int pos){
    if(pos==N) {
        for(int i=1;i<=N;i++)
            printf("%d%c",ans[i],i==N?'\n':' ');
        exit(0);
    }
    int now_max=-INF,now_min=INF,flg=1;
    
    ans[pos+1]=ans[pos]+a[pos][pos+1];
    now_max=now_min=ans[pos+1];
    for(int i=pos;i;i--){
        now_max=max(now_max,ans[i]);now_min=min(now_min,ans[i]);
        if(now_max-now_min!=a[i][pos+1]) {flg=0;break;}
    }

    if(flg)dfs(pos+1);
    
    flg=1;
    ans[pos+1]=ans[pos]-a[pos][pos+1];
    now_max=now_min=ans[pos+1];
    for(int i=pos;i;i--){
        now_max=max(now_max,ans[i]);now_min=min(now_min,ans[i]);
        if(now_max-now_min!=a[i][pos+1]) {flg=0;break;}
    }
    if(flg)dfs(pos+1);
}
int main(){
    // freopen("C.in","r",stdin);
    // freopen("C.out","w",stdout);
    cin>>N;
    for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++){
        if(i>j) a[i][j]=0;
        else cin>>a[i][j];
    }
    ans[1]=0;
    dfs(1);
    return 0;
}