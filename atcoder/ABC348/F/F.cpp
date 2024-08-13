#include <bits/stdc++.h>
using namespace std;

int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

int main() {
    freopen ("F.in", "r", stdin);
    int n, m;  n = read(); m = read();
    vector<vector<int> > a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    vector<bitset<2001> > p(n + 1);
    vector<vector<int> > vc(1000 , vector<int>());
    for (int i = 1; i <= m; i++) {
        for (auto &x : vc) x.clear();
        for (int j = 1; j <= n; j++)
            vc[a[j][i]].push_back(j);
        for (auto &x : vc) if (x.size() > 0) {
            bitset<2001> now(0);
            for (auto &k : x) now[k] = 1;
            for (auto &k : x) p[k] ^= now;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) 
            ans += p[i][j];
    cout << ans << '\n';
    return 0;
}