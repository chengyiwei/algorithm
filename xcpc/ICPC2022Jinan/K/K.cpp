#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int> a(n+1);
    vector<int> vis(n+2,0);
    int ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];   
    for(int i=1;i<=n;i++){
        if(vis[a[i]+1]) vis[a[i]+1]=0,vis[a[i]]=1;
        else ans++,vis[a[i]]=1;
    }
    cout<<ans<<endl;
}
int main(){
    int T;cin>>T;
    while(T--) solve();
}