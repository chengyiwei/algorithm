#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
const int maxn=2e5+5;
const double eps=1e-9;
int a[maxn];
double F[maxn];
void solve(){
    int N=read(),ans=0;
    for(int i=1;i<=N;i++){
        a[i]=read();F[i]=(double)a[i]*log(2)-log(a[i]);
    }
    sort(F+1,F+1+N);
    for(int i=1;i<=N;){
        int R=i;
        while(R+1<=N&&abs(F[i]-F[R+1])<eps) R++;
        int num=R-i+1;
        ans+=(num)*(num-1)/2;
        i=R+1;
    }
    printf("%lld\n",ans);
}
signed main(){
    // freopen("D.in","r",stdin);
    int T=read();
    while(T--)solve();
    return 0;
}