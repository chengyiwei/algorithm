#include<bits/stdc++.h>
#define int long long
using namespace std;
const int TT=998244353;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

void solve(){
    int n=read();
    vector<int> a(n+1,0),F(n+1,0),sum(n+1,0);
    stack<int> st;
    for(int i=1;i<=n;i++) a[i]=read();
    int ans=0;
    for(int i=1;i<=n;i++){
        while(!st.empty()&&a[i]<a[st.top()]) ans=(ans-F[st.top()])%TT,st.pop();
        if(st.empty()) F[i]=(sum[i-1]+1)%TT;
        else F[i]=(sum[i-1]-sum[st.top()]+ans)%TT;
        sum[i]=(sum[i-1]+F[i])%TT;
        ans=(ans+F[i])%TT;
        st.push(i);
    }
    printf("%lld\n",(ans+TT)%TT);
}

signed main(){
    freopen("D.in","r",stdin);
    int T=read();
    while(T--) solve();
    return 0;
}