#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;
int N, X, Y,Q;
int P[maxn],T[maxn];
LL dis[845];
inline int read(){
    int ret = 0, f = 1;char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch=getchar();}
    while(ch>='0'&&ch<='9')ret=ret*10+ch-48,ch=getchar();
    return ret;
}
void solve(){
    for(int k=0;k<840;k++){
        LL now=k;
        for(int i=1;i<N;i++){
            LL wait=(P[i]-now%P[i])%P[i];
            now+=wait+T[i];
        }
        dis[k]=now-k;
    }
}
int main(){
    freopen("E.in", "r", stdin);
    freopen("E.out", "w", stdout);
    N = read();X=read();Y=read();
    for (int i=1;i<N;i++) P[i]=read(),T[i]=read();
    solve();
    Q=read();
    while(Q--){
        int t=read();
        printf("%lld\n",0ll+t+X+dis[(t+X)%840]+Y);
    }
    return 0;
}