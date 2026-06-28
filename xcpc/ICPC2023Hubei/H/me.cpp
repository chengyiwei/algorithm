#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const ll MAXN = 5e6+5;
const ll MOD = 998244353;
ll read(){
    ll ret = 0; char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch <= '9' && ch >= '0') {ret = ret * 10 + ch - '0', ch = getchar();}
    return ret ;
}

void print(ll x) {
    if (x == 0) return ;
    print(x / 10);
    putchar(x % 10 + '0');
}

ll n, m, du[MAXN], flag[MAXN], cnt[MAXN], sum;
vector<ll> pp;
ll M(ll x){
    return (x % MOD + MOD) % MOD;
}

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b){
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    n = read(); m = read();
    for(int i = 1; i <= m; i ++){
        ll x, y;
        x = read(); y = read();
        du[x] ++; du[y] ++;
    }
    for(int i = 1; i <= n; i ++){
        if(!flag[du[i]]){
            pp.push_back(du[i]);
            flag[du[i]] = 1;
        }
        cnt[du[i]] ++;
    }
    for(int i = 0; i < pp.size(); i ++){
        for(int j = 0; j < pp.size(); j ++){
            ll dq = 0;
            dq = M(cnt[pp[i]] * cnt[pp[j]]);
            dq = M(dq * (pp[i] ^ pp[j]));
            dq = M(dq * (pp[i] | pp[j]));
            dq = M(dq * (pp[i] & pp[j]));
            sum = M(sum + dq);
        }
    }
    sum = sum * qpow(2, MOD - 2);
    if (M (sum) == 0) putchar('0');
    else print( M(sum) );
    return 0;
}