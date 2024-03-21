#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100009;
LL dp[maxn];

int main() {
    int c[4],d[4];
    for (int i = 0; i < 4; i++)
        cin >> c[i];
    dp[0] = 1;
    for (int i = 0; i < 4; i++)
        for (int j = c[i]; j < maxn; j ++)
            dp[j] += dp[j - c[i]];    
    int q; cin >> q;
    while (q--) {
        for (int i = 0; i < 4; i++)
            cin >> d[i];
        int s; cin >> s;
        LL ans = dp[s];
        for (int i = 1; i < 16; i ++) {
            int tmp = i, num = 0;
            int now = s;
            for (int j = 0; j < 4; j++)
                if (tmp >> j & 1) now -= c[j] * (d[j]  + 1), num++;
            if (now < 0) continue;
            if (num & 1) ans -= dp[now];
            else ans += dp[now];
        }
        cout << ans << '\n';
    }
    return 0;
}