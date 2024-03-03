#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; scanf("%d",&n);
    vector<int> a(n+1); a[0]=-1;
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1])
            pre[i] = pre[i-1];
        else 
            pre[i] = i-1;
    }
    for(int i=n;i;){
        if(pre[i] <= 0){
            ans += i;
            break;
        }
        else{
            ans ++;
            i = pre[i] - 1;
        }
    }
    printf("%d\n",ans);
}

int main(){
    freopen("E.in","r",stdin);
    int T = 1;
    while(T--) solve();
    return 0;
}