#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n;cin>>n;
    int ans=0,lst=0;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=0;j<=20;j++){
        int now=0;
        for(int i=1;i<=n;i++){
            now+=a[i]%10;
            a[i]/=10;
        }
        now+=lst;
        lst=now/10;
        ans+=lst;
    }
    cout<<ans<<endl;
}
signed main(){
    int T;cin>>T;
    while(T--) solve();
}