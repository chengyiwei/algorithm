#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 998244353;
int main() {
    // freopen ("J.in", "r", stdin);
    ios::sync_with_stdio(0);
    ll N, A; cin >> N >> A;
    ll gn, gn1 , gn_1 = A, gn_2 = 1, n = N % TT, i;
    for (i = 1; i + 1 < n; i += 2) {
        gn1 = ((A * A + i + 1) % TT * gn_1 + A * i % TT * gn_2) % TT;
        gn = (A * gn_1 + i * gn_2) % TT;
        gn_2 = gn, gn_1 = gn1;
    }
    gn1 = gn_1; gn = gn_2;
    for (; i < n; i++) {
        gn1 = (A * gn1 + i * gn) % TT;
    }
    while (N > n) {
        gn1 = gn1 * A % TT; N -= TT;
    }
    cout << gn1;
    return 0;
}