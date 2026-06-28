#include<bits/stdc++.h>
#define int __int128
using namespace std;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
void solve(){
    int n,f,a,b; n=read();f=read();a=read();b=read();
    vector<int> v(n+1);
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);
    for(int i=1;i<=n;i++){
        int val = min((v[i]-v[i-1])*a,b);
        f-=val;
        if(f<=0){printf("NO\n");return ;}
    }
    printf("YES\n");
}
signed main(){
    freopen("C.in","r",stdin);
    int T;T=read();
    while(T--) solve();
}