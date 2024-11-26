#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x3f3f3f3f;

struct Segment_Tree {
    int n;
    vector<int> cnt, t;
    void init(int _n) {
        n = _n;
        cnt.assign(n << 2, 0);
        t.assign(n << 2, 0);
    }
    void push_up(int x, int l, int r) {
        if (cnt[x] != 0) t[x] = r + 1 - l;
        else if (l == r) t[x] = 0;
        else t[x] = t[x << 1] + t[x << 1 | 1];
    }
    void update(int x, int l, int r, int ql, int qr, int val) {
        if (ql <= l && r <= qr) {
            cnt[x] += val;
            push_up(x, l, r); return ;
        }
        int mid = (l + r) >> 1;
        if (ql <= mid) update(x << 1, l, mid, ql, qr, val);
        if (mid < qr) update(x << 1 | 1, mid + 1, r, ql, qr, val);
        push_up(x, l, r);
    }
    
};

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> a(n + 1);
    int M = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        M = max(M, max(a[i].first, a[i].second));
    }
    Segment_Tree seg; seg.init(M + 1);
    for (int i = 1; i <= n; i++) {
        auto [l, r] = a[i];
        seg.update(1, 1, M, l + 1, r, 1);
    }
    int ans1 = 0;
    for (int i = 1; i <= n; i++) {
        auto [l, r] = a[i];
        seg.update(1, 1, M, l + 1, r, -1);
        ans1 = max(ans1, seg.t[1] + (r - l));
        seg.update(1, 1, M, l + 1, r, 1);
    }
    cout << ans1 << '\n';


    int ans2 = INF;
    int max_len_x = 0, max_len_i = 0;
    for (int i = 1; i <= n; i++) {
        int len = a[i].second - a[i].first;
        if (len > max_len_x) {
            max_len_x = len;
            max_len_i = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == max_len_i) continue;
        auto [l, r] = a[i];
        seg.update(1, 1, M, l + 1, r, -1);
        ans2 = min(ans2, seg.t[1]);
        seg.update(1, 1, M, l + 1, r, 1);
    }
    
    vector<int> cf(M + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (i == max_len_i) continue;
        auto [l, r] = a[i];
        cf[l]++; cf[r]--;
    }
    int now = 0;
    for (int i = 1; i <= M; i++) cf[i] += cf[i - 1];
    for (int i = 1; i <= M; i++) {
        cf[i] = cf[i - 1] + (cf[i] != 0);
    }
    now = cf[M];
    for (int l = 1; l + max_len_x - 1 <= M; l++) {
        int r = l + max_len_x - 1;
        int now_ = now + max_len_x - (cf[r] - cf[l - 1]);
        ans2 = min(ans2, now_);
    }
    cout << ans2 << '\n';
    return 0;
}