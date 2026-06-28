#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        vector<pair<int, int>> ans;
        int n; cin >> n;
        auto string_n = to_string(n);
        int siz = string_n.size();
        for (int a = 1; a <= 10000; a++) {
            for (int b = max(a * siz - 5, 1); b <= min({a * siz - 1, a * n, 10000}); b++) {
                int now = 0;
                for (int i = 0; i < siz * a - b; i++)
                    now = now * 10 + string_n[i % siz] - '0';
                if (now == a * n - b) {
                    ans.push_back({a, b});
                }
            }
        }
        cout << ans.size() << endl;
        for (auto [a, b] : ans) {
            cout << a << " " << b << endl;
        }
    }
    return 0;
}