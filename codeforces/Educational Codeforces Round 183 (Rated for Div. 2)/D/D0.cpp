#include <bits/stdc++.h>
using namespace std;

int n, k;
deque<int> res;
const int INF = 1e9;


void solve() {
    cin >> n >> k;
    vector<pair<int, int>> a;
    for (int i = 2; i <= n; i++) {
        int val = (i - 1) * i / 2;
        a.emplace_back(val, i);
    }

    int total = n * (n - 1) / 2 - k;
    vector<int> f(total+ 1, INF);
    vector<int> pre(total + 1, -1);
    f[0] = 0;
    pre[0] = 0;

    for (int j = 0; j <= total; j++) {
        for (auto [val, c] : a) {
            if (j >= val) {
                if (f[j] > f[j - val] + c) {
                    f[j] = f[j - val] + c;
                    pre[j] = c;
                }
            }
        }
    }
    if (f[total] > n) {
        cout << 0 << '\n';
    }
    else {
        deque<int> res;
        vector<int> ans;
        for (int j = total; j > 0;) {
            int c = pre[j];
            res.push_back(c);
            j -= (c - 1) * c / 2;
        }
        int now = 0;
        for (auto c : res) {
            for (int j = c + now; j > now; j--) {
                ans.push_back(j);
            }
            now += c;
        }
        for (int j = now + 1; j <= n; j++) {
            ans.push_back(j);
        }
        reverse(ans.begin(), ans.end());
        for (auto x : ans) cout << x << ' ';
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}