#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 2e5 + 10;

int n, q;

LL c1[maxn], c2[maxn];
void add (int pos, LL data) {
    for (int i = pos; i <= n + 2; i += i & -i) 
        c1[i] += data, c2[i] += data * pos;
}
LL query (int pos) {
    LL ret = 0;
    for (int i = pos; i; i -= i & -i) 
        ret += c1[i] * (pos + 1) - c2[i];
    return ret;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    vector<LL> a(n + 1, 0), cf1(n + 1, 0), cf2(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; cf1[i] = a[i] - a[i - 1]; cf2[i] = cf1[i] - cf1[i - 1];
        add(i, cf2[i]);
    }

    while (q--) {
        int opt; cin >> opt;
        if (opt == 1) {
            int l, r; LL K, D; cin >> l >> r >> K >> D;
            add(l, K); add(l + 1, D - K); add(r + 1, - (r - l + 1) * D - K); add(r + 2, (r - l) * D + K);
        }
        if (opt == 2) {
            int x; cin >> x;
            cout << query(x) << '\n';
        }
    }
    return 0;
}