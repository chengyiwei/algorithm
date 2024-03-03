#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, x, y), x0 = x, y0 = y;
    x = y0, y = x0 - a / b * y0;
    return d;
}

LL inv(LL a, LL mod) {
    LL x, y;
    exgcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}


int main () {    
    LL a, mod; cin >> a >> mod;
    cout << inv(a, mod) << endl;
    return 0;
}