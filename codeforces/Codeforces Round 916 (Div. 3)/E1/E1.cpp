#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const int maxn=2e5+10;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
vector<int> a,b;
int p[maxn];
LL check(){
    LL ret=0;
    for(int i=1;i<=n;i++){
        if(i&1){
            ret+=a[p[i]]-1-0;
        }
        else{
            ret+=0-(b[p[i]]-1);
        }
    }
    return ret;
}
bool cmp(int x,int y){
    return a[x]+b[x]>a[y]+b[y];
}
void solve(){
    n=read();LL ans=-INF;
    a.resize(n+1);b.resize(n+1);
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++) b[i]=read();
    for(int i=1;i<=n;i++) p[i]=i;
    sort(p+1,p+1+n,cmp);
    ans=check();
    printf("%lld\n",ans);
}
int main(){
    freopen("E1.in","r",stdin);
    int T=read();
    while(T--) solve();
}