#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3+ 5;

int cnt = 1;
struct Node {
    int siz, ch[2];
    Node () {siz = 0, ch[0] = ch[1] = 0;}
}t[MAXN * 2];

void insert(string s) {
    int u = 1;
    for (auto c : s) {
        if (!t[u].ch[c - '0']) t[u].ch[c - '0'] = ++cnt;
        u = t[u].ch[c - '0'];
        t[u].siz += 1;
    }
}


int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    double P; int n, m; cin >> n >> m >> P;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        insert(s);
    }
    vector dp(MAXN + 1, vector<double>(MAXN + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[0][i] = dp[0][i - 1] * P;
    for (int x = 1; x <= MAXN; x++)
        for (int y = 1; y <= MAXN; y++) {
            dp[x][y] = max(P * dp[x - 1][y] + (1 - P) * dp[x][y - 1], P * dp[x][y - 1] + (1 - P) * dp[x - 1][y]);
        }

    double res = 1;
    for (int i = 1; i <= cnt; i++)
        res *= dp[t[t[i].ch[0]].siz][t[t[i].ch[1]].siz];
    cout << fixed << setprecision(10) << res << '\n';
    return 0;
}