#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pll;

const LL mod = (1ll << 31) - 1;

struct Line {
    LL up, dn;
    int pre, nxt; // 两者的编号
    Line(LL _up, LL _dn, int _pre, int _nxt) {
        if (dn < 0) up = -up, dn = -dn;
        up = _up, dn = _dn, pre = _pre, nxt = _nxt;
    }
    bool operator < (const Line &rhs) const {
        return up * rhs.dn > dn * rhs.up;
    }
    bool operator == (const Line &rhs) const {
        return up == rhs.up && dn == rhs.dn && pre == rhs.pre && nxt == rhs.nxt;
    }
};

signed main() {
    freopen ("G.in", "r", stdin);
    freopen ("G.out", "w", stdout);
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

    auto make_line = [&] (int i, int j) {
        return Line(a[j].second - a[i].second, a[j].first - a[i].first, i, j);
    };

    priority_queue<Line> s;
    for (int i = 1; i < n; i++)
        if (a[i].first < a[i + 1].first)
            s.push (make_line(i, i + 1));

    LL ans = 0;
    for (int i = 1; i <= Q; i++) {
        auto [k, b] = q[i];
        while (s.size() > 0) {   
            auto it = s.top();
            int dn = it.dn, up = it.up, pre = it.pre, nxt = it.nxt;
            if (!(make_line(pre, nxt) == it)) {s.pop(); continue;} // 说明这个线段已经被更新过了
            if (k * dn < up) break;  // 当 k > 两点的斜率时，交换
            s.pop(); swap(a[pre], a[nxt]);
            if (pre > 1 && a[pre - 1].first < a[pre].first) s.push(make_line(pre - 1, pre));
            if (nxt < n && a[nxt].first < a[nxt + 1].first) s.push(make_line(nxt, nxt + 1));
        }

        int l = 1, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            auto [X, Y] = a[mid];
            if ( -k * X + Y >= b) r = mid - 1;
            else l = mid + 1;
        }
        ans += n - r;
    }
    cout << ans << endl;
    return 0;
}