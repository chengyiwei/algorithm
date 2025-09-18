//
// Created by martian148 on 2025/9/18.
//
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> f(8);
    for (int i = 1; i < 8; i++) cin >> f[i];

    auto check = [&] (int mid) -> bool {
        for (int t = 1; t < 8; t++) {
            int sum = 0;
            for (int s = 1; s < 8; s++) {
                if ((s & t) > 0)
                    sum += f[s];
            }
            if (mid * __builtin_popcount(t) > sum) return false;
        }
        return true;
    };

    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}