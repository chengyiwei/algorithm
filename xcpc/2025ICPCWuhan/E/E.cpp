#include <bits/stdc++.h>
using namespace std; 

struct Node {
    array<int, 2> p1; // mod 0, mod 1
    int p2;
    Node() : p1{0, 0}, p2(0) {}
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);

    auto calc = [&](vector<int> &arr) -> Node {
        array<int, 2> p1 = {0, 0};
        int p2 = 0;

        map<int, int> cnt;
        for (int i = 1; i <= n; i++) cnt[arr[i]] += 1;
        for (auto [i, _] : cnt) { 
            while (cnt[i] > 0 && cnt[i + 1] > 0) {
                cnt[i] -= 1; cnt[i + 1] -= 1;
                p2 += 1;
            }
            while (cnt[i] > 0 && (cnt.count(i + 1) == 0 || cnt[i + 1] == 0)) {
                cnt[i] -= 1;
                p1[i % 2] += 1;
            }
        };

        if (p2 > 0) {
            int m = min(p1[0], p1[1]);
            p1[0] -= m; p1[1] -= m;
        }

        Node res;
        res.p1 = p1; res.p2 = p2;
        return res;
    };

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    auto res_a = calc(a);
    auto res_b = calc(b);

    if (res_a.p2 == 0 || res_b.p2 == 0) {
        sort(a.begin(), a.end()); sort(b.begin(), b.end());
        if (a == b) cout << "Yes\n";
        else cout << "No\n";
        return;
    }

    if (res_a.p1 == res_b.p1) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    // freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}