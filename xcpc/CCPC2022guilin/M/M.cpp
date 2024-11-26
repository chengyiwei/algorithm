#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(x) (x) & (-x)
const ll MAXN = 3e5 + 5;
ll n, k, a[MAXN], tr[MAXN << 2], f[MAXN];
string s;
void add(ll x, ll k){
    while(x <= MAXN * 2){
        tr[x] += k;
        x += lowbit(x);
    }
}
ll sum(ll x){
    ll ret = 0;
    while(x > 0){
        ret += tr[x];
        x -= lowbit(x);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    ll ans = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        add(a[i], 1);
        ans += i - sum(a[i]);
    }
    cout << ans << "\n";
    f[1] = ans;
    for(int i = 2; i <= n; i ++){
        add(a[i - 1], -1);
        ans -= sum(a[i - 1]);
        add(a[i - 1], 1);
        ans += (n - sum(a[i - 1]));
        f[i] = ans;
    }
    cin >> s;
    ll p = 1, idx = 1, sum = (n - 1) * n / 2;
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == 'S') idx += p;
        else p *= -1;
        idx = idx % n;
        idx == 0 ? idx = n : idx = idx;
        if(p == 1) cout << f[idx] % 10;
        else cout << (sum - f[idx]) % 10;
    }
    cout << "\n";
    return 0;
}