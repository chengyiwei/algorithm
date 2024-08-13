#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 998244353;
ll qpow (ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return res;
}
int main() {
    ll n; cin >> n;
    int siz = log10(n) + 1;
    ll ret = 0;
    ll pow10 = qpow(10, siz);
    for (int i = 1; i <= n; i++)
        ret = (ret * pow10 + n) % TT;
    cout << ret << endl;
}