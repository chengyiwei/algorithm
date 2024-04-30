#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pll;

const LL mod = (1ll << 31) - 1;

struct Line {
    LL up, dn;
    int pre, nxt; // 两者的编号
    Line(LL _up, LL _dn, int _pre, int _nxt) : up(_up), dn(_dn), pre(_pre), nxt(_nxt) {}
    bool operator < (const Line &rhs) const {
        if (dn == 0 && rhs.dn == 0) return up < rhs.up;
        if (dn == 0) return 1;
        if (rhs.dn == 0) return 0;
        return up * rhs.dn < dn * rhs.up;
    }
    bool operator == (const Line &rhs) const {
        return up == rhs.up && dn == rhs.dn && pre == rhs.pre && nxt == rhs.nxt;
    }
};

int main() {
    freopen ("G.in", "r", stdin);
    freopen ("G0.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<pll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        auto & [k, b] = a[i];
        cin >> k >> b;
    }
    sort (a.begin() + 1, a.end());
    
    int Q; cin >> Q;
    int G0, Ra, Rb; cin >> G0 >> Ra >> Rb;
    vector<pll> q(Q + 1); vector<LL> G(3 * Q + 1); G[0] = G0;
    for (int i = 1; i <= 3 * Q; i++) 
        G[i] = (48271 * G[i - 1]) % mod;
    for (int i = 1; i <= Q; i++) {
        auto &[A, B] = q[i];
        A = -Ra + (G[3 * i - 2] % (2 * Ra + 1));
        B = -Rb + ((G[3 * i - 1] * mod + G[3 * i]) % (2 * Rb + 1));
    }
    sort (q.begin() + 1, q.end());
    // for (int i = 1; i <= Q; i++) {
    //     auto [A, B] = q[i];
    //     cout << A << " " << B << endl;
    // }
    LL ans = 0;
    for (int i = 1; i <= Q; i++) {
        auto [k, b] = q[i];
            LL now = 0;
        for (int j = 1; j <= n; j++) {
            auto [X, Y] = a[j];
            if (k * X + b <= Y) {
                now ++;
            }
        }
        ans += now;
        // cout << now << '\n';
    }
    cout << ans << endl;
    return 0;
}