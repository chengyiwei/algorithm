#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, id;
    bool operator < (const Node &B) const{
        return val < B.val;
    }
};

bool is_ok(vector<Node> &a) {
    for (auto v : a) {
        if (v.id == 1) return true;
    }
    return false;
}

void solve() {
    vector<Node> a(33);
    for (int i = 1; i <= 32; i++) cin >> a[i].val, a[i].id = i;
    sort(a.begin() + 1, a.end());
    int cnt = 0;
    for (int i = 1; i <= 32; i++) {
        if (a[i].id == 1) {
            cnt = i - 1;
        }
    }
    if (cnt >= 31) cout << 1;
    else if (cnt >= 27) cout << 2;
    else if (cnt >= 13) cout << 4;
    else if (cnt >= 6) cout << 8;
    else if (cnt >= 2) cout << 16;
    else cout << 32;
    cout << '\n';
}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}