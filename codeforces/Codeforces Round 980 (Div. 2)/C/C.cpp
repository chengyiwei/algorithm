#include <bits/stdc++.h>
using namespace std;


int calc(vector<int> &a) {
    int n = a.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (a[j] > a[i]) ret++;
    }
    return ret;
}

bool cmp(array<int, 2> a, array<int, 2> b) {
    int cnt1 = 0, cnt2 = 0;
    vector<int> a1 = {a[0], a[1], b[0], b[1]};
    vector<int> a2 = {b[0], b[1], a[0], a[1]};
    cnt1 = calc(a1); cnt2 = calc(a2);
    return cnt1 < cnt2;
}

struct node {
    int x, y, z;
    bool operator < (const node &a) const {
        return x < a.x || (x == a.x && y < a.y);
    }
};

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    vector<node> b(n);
    for (int i = 0; i < n; i++) {
        b[i].x = a[i][0];
        b[i].y = a[i][1];
        b[i].z = 0;
        if (b[i].x > b[i].y) swap(b[i].x, b[i].y), b[i].z = 1;
    }
    sort(b.begin(), b.end());
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (b[i].z == 0) ans.push_back(b[i].x), ans.push_back(b[i].y);
        else ans.push_back(b[i].y), ans.push_back(b[i].x);
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << '\n';
    // int ret = calc(ans);
    // cout << ret << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}