#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
const LL TT = 1e9 + 7, INF = 1e18;

LL Fac[maxn],inv[maxn];

LL qpow(LL a,LL b,LL mod = TT){
    LL res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

LL C(LL n,LL m){
    return Fac[n] * inv[m] % TT * inv[n-m] % TT;
}
int main(){
    freopen("F.in","r",stdin);
    LL n,m;
    cin>> n >> m;
    if(n < m) { cout<< 0 << endl; return 0;}
    Fac[0] = inv[0] = 1;
    for(int i=1;i<=n;i++)
        Fac[i] = Fac[i-1] * i % TT, inv[i] = qpow(Fac[i],TT-2,TT);
    LL ans = 0;
    for(int i=0;i<=m;i++){
        ans += (m-i&1?-1:1) * qpow(i,n,TT) % TT * inv[i] % TT * inv[m-i]% TT;
        ans = (ans % TT + TT) % TT;
    }
    cout<< ans << endl;
    return 0;
}