#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[10005],dp[10005][505],t[505][5505];

void update(int x,int y,int data){
    for(int i=x;i<=k+1;i+=i&-i)
        for(int j=y;j<=5500;j+=j&-j)
            t[i][j] = max(t[i][j],data);
}

int query(int x,int y){
    int ans = 0;
    for(int i=x;i;i-=i&-i)
        for(int j=y;j;j-=j&-j)
            ans = max(ans,t[i][j]);
    return ans;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++){
            dp[i][j] = query(j+1,a[i]+j)+1;
            update(j+1,a[i]+j,dp[i][j]);
        }
    int ans = query(k+1,5500);
    printf("%d\n",ans);
    return 0;
}