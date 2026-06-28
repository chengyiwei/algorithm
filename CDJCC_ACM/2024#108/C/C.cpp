#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Frac {
    ll p, q; // p / q
    Frac(ll p = 0, ll q = 1) : p(p), q(q) {}
    bool operator < (const Frac &f) const { return p * f.q < q * f.p; }
    bool operator <= (const Frac &f) const { return p * f.q <= q * f.p; }
};

int main() {
    int N; cin >> N;
    vector<ll> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    vector<pair<Frac, Frac>> que(N);
    for (int i = 0; i < N; i++) que[i] = make_pair(Frac(y[i], x[i] - 1), Frac(y[i] - 1, x[i]));
    sort(que.begin(), que.end());
    int cnt = 0;
    Frac R_max = Frac(0, 1);
    for (auto cur : que) {
        if (R_max <= cur.second) { // cur.second 是左端点
            cnt += 1;
            R_max = cur.first; // 更新右端点
        }
    }
    cout << cnt << endl;
    return 0;
}