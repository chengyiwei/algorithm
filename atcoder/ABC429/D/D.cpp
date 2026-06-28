#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int n, m, c; cin >> n >> m >> c;
    map<int, int> b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b[x] += 1, b[x + m] += 1;
    }
    int sum = 0;
    long long ans = 0;
    map<int, int> :: iterator it = b.begin(), jt = b.begin();
    for (; it != b.end(); it ++) {
        if (it->first >= m) break;
        while (jt != b.end() && sum < c + it->second) {
            sum += jt->second;
            jt++;
        }
        auto next_it = it; next_it++;
        sum -= it->second;
        ans += 1ll * (next_it->first - it->first) * sum;
    }
    cout << ans << "\n";
    return 0;
}