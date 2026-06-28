#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;scanf("%d",&n);
    int ans=0,lst=0;
    vector<int> a(n+1),f(n+1);
    for(int i=1;i<=n;i++) {
        char c;scanf(" %c",&c);
        a[i]=c-'0';
    }
    for(int i=1;i<=n;i++) {
        char c;scanf(" %c",&c);
        f[i]=c-'0';
    }
    for(int i=1;i<=n;i++){
        if(a[i]==f[i])  continue;
        if(a[i]>f[i]){
            if(lst < 0) ans++,lst++;
            else lst++;
        }
        else{
            if(lst > 0) ans++,lst--;
            else lst--;
        }
    }
    ans+=abs(lst);
    printf("%d\n",ans);
}
int main(){
    freopen("B.in","r",stdin);
    int T;scanf("%d",&T);
    while(T--){
        solve();
    }
}