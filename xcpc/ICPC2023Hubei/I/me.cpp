#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e6+5;
const ll INF = 1e7+5;
ll n, LCM = 1, p, tot, mn=4e18+5;
bool flag[INF];
ll cnt[MAXN];
ll f[MAXN];
vector<ll> zs;
vector<ll> fj;
void get(){
    for(int i = 2; i < INF - 2; i ++){
        if(!flag[i]){
            for(ll j = i * 2; j < INF - 2; j += i){
                flag[j] = 1;
            }
            zs.push_back(i);
        }
    }
}
ll fastPow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
void exgcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    ll tmp = x;
    x = y;
    y = tmp + a / b * y;
}
int main(){
    ios::sync_with_stdio(false);
    get();
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> p;
        LCM = LCM / __gcd(LCM, p) * p;
    }
    ll L = LCM * 2, tmp = L;
    for(int i = 0; i < zs.size(); i ++){
        if(tmp % zs[i] == 0) tot ++, fj.push_back(zs[i]);
        while(tmp % zs[i] == 0){
            tmp /= zs[i];
            cnt[tot - 1] ++;
        }
        if(zs[i] > tmp) break;
    }
    for(int i = 0; i < tot; i ++){
        f[i] = fastPow(fj[i], cnt[i]);    }
    for(int S = 0; S < (1 << tot); S ++){
        ll A = 1;
        ll B = 1;
        for(int j = 0; j < tot; j ++){
            if((S & (1 << j))) A *= f[j];
            else B *= f[j];
        }
        ll x, y;
        exgcd(A, B, x, y);
        if(x > 0 && y > 0){
            mn = min(min(A * x, B * y), mn);
        }
    }
    cout << mn << endl;
    return 0;
}
