#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

void solve(){
    int n=read(),m=read();
    vector<int> a(n+1),b(m+1);
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=m;i++) b[i]=read();
    LL ans=0;
    sort(a.begin()+1,a.end());  //从小到大排序
    sort(b.begin()+1,b.end(),greater<int>()); //从大到小排序
    for(int i=1;i<=n;i++)
        ans+=abs(a[i]-b[i]);
    int pos=n;
    LL now_ans=ans;
    for(int i=n;i>=1;i--){
        now_ans-=abs(a[i]-b[pos]);pos--;
        now_ans+=abs(a[i]-b[i+(m-n)]);
        ans=max(ans,now_ans);
    }
    printf("%lld\n",ans);
}

int main(){
    freopen("D.in","r",stdin);
    int T=read();
    while(T--) solve();
}