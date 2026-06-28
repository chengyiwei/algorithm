#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;cin>>n>>k;k++;
    vector<int> ans;
    for(int i=n-k+1;i<=n;i++){
        ans.push_back(i);
    }
    for(int i=n-k;i;i--)
        ans.push_back(i);
    for(int i=0;i<ans.size();i++) 
        printf("%d ",ans[i]);
    printf("\n");
}
int main(){
    freopen("B.in","r",stdin);
    int t;cin>>t;
    while(t--) solve();
}