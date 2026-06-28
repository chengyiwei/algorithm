#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxm = 405;

int a[maxn];
int tag[maxm][maxm];
int main() {
    int n, q; cin >> n >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, m; cin >> x >> m;
            if (m > 400)
                for (int i = x; i <= n; i += m)
                    a[i] += 1;
            else
                tag[m][x] += 1;
        }
        else {
            int x; cin >> x;
            int ans = a[x];
            for (int i = 1; i <= 400; i++)
                ans += tag[i][x % i];
            cout << ans << '\n';
        }
    }
    return 0;
}