#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 5, MAXM = 1e7 + 5;

int sg[MAXN], prime[MAXM];
bool vis[MAXN];

void init_() {
    int cnt = 0;
    for (int i = 2; i < MAXN; i++) {
        if (!vis[i]) prime[++cnt] = i, sg[i] = cnt;
        for (int j = 1; j <= cnt && i * prime[j] < MAXN; j++) {
            vis[i * prime[j]] = 1;
            if (i * prime[j] % 2 == 1) sg[i * prime[j]] = sg[prime[j]];
            if (i % prime[j] == 0) break;
        }
    }
    sg[1] = 1; sg[0] = 0; sg[2] = 0;
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(0);
    init_();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            ans ^= sg[x];
        }
        if (ans) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}