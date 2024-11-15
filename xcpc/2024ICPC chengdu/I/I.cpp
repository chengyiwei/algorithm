#include <bits/stdc++.h>
using namespace std;

struct Segment_Tree {
    vector<int> t;
    void init(int n) {t.assign(n << 2, 0);}
    
    void push_up (int x) { t[x] = __gcd(t[x << 1], t[x << 1 | 1]); }

    void update (int x, int l, int r, int pos, int val) {
        if (l == r) {
            t[x] = val;
            return ;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(x << 1, l, mid, pos ,val);
        else update (x << 1 | 1, mid + 1, r, pos, val);
        push_up(x);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1, 0);
    Segment_Tree T; T.init(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i + 1 <= n; i++) {
        if (a[i] > a[i + 1]) T.update(1, 1, n, i, i);
    }

    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j += i) 
            cnt[j] += 1;
    cnt[0] = n;

    cout << cnt[T.t[1]] << '\n';

    while (q--) {
        int p, v; cin >> p >> v;
        a[p] = v;
        if (p + 1 <= n) {
            if (a[p] > a[p + 1]) T.update(1, 1, n, p, p);
            else T.update(1, 1, n, p, 0);
        }

        if (p - 1 > 0) {
            if (a[p - 1] > a[p]) T.update(1, 1, n, p - 1, p - 1);
            else T.update(1, 1, n, p - 1, 0);
        }

        cout << cnt[T.t[1]] << '\n';
    }
}

int main() {
    // freopen ("I.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}