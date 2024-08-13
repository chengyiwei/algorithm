#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,ans=0;cin>>n;
    string s;cin>>s;s=" "+s;
    vector<int> a(30);
    for(int i=1;i<=n;i++) a[s[i]-'A'+1]++;
    for(int i=1;i<=26;i++){
        if(a[i]>=i) ans++;
    }
    printf("%d\n",ans);
}
int main(){
    freopen("A.in","r",stdin);
    int T;cin>>T;
    while(T--) solve(); 
}