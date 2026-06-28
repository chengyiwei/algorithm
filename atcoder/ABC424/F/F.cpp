#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
    vector<int> c(n + 1, 0);
    
    auto add = [&] (int x, int val) {
        for (; x <= n; x += x & -x) c[x] ^= val;
    };

    auto get = [&] (int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) res ^= c[x];
        return res;
    };

    vector<int> hsh(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        hsh[i] = (rand() << 15) | rand();
        if (get(x) == get(y)) {
            cout << "Yes\n";
            add(x, hsh[i]);
            add(y, hsh[i]);
        }
        else {
            cout << "No\n";
        }
    }

    return 0;
}