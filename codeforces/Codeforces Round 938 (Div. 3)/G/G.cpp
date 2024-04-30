#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const int flg[2][2] = {{1, 0}, {0, 1}};


inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

void print (int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

const int maxn = 104;
int dp[maxn][maxn];

void solve() {
    int n, m;
    n = read(), m = read();
    vector<vector<int> > a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            a[i][j] = read();
        }
    
    auto check = [&] (int g) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = 0;
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (a[i][j] % g) dp[i][j] = 0;
                if (dp[i][j]) 
                    dp[i + 1][j] = dp[i][j + 1] = 1;
            }
        if (dp[n][m] == 1) return true;
        else return false;
    };

    int ans = 1;

    auto get_fac = [&] (int x) {
        vector<int> res;
        for (int i = 1; i <= sqrt(x); i++) {
            if (x % i == 0) {
                res.push_back(i);
                if (i * i != x) res.push_back(x / i);
            }
        }
        return res;
    };

    auto g = __gcd(a[1][1], a[n][m]);

    auto fac = get_fac(g);

    sort (fac.begin(), fac.end(), greater<int>());

    for (auto &x : fac) {
        if (check(x) == 1) {
            print(x);
            putchar('\n');
            return;
        }
    }
}

int main() {
    freopen ("G.in", "r", stdin);
    freopen ("G.out", "w", stdout);
    int t; t = read();
    while (t--) solve();
}