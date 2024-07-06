#include <bits/stdc++.h>
using namespace std;
#define int __int128
typedef pair<int, int> pii;
const int INF = 1e18 + 1000;

struct Node {
    int tim, pos;
    Node (int t, int p) {tim = t, pos = p;}
    bool operator < (const Node B) const {return tim < B.tim;}
};

int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

void write(int x) {
    if (x < 0) {putchar('-'); x = -x;}
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
    freopen ("K.in", "r", stdin);
    // ios::sync_with_stdio(0);
    int n, m, k; n = read(), m = read(), k = read();
    vector<vector<Node>> a(n + 1,vector<Node>());
    for (int i = 1; i <= m; i++) {
        int t, x, y; t = read(), x = read(), y = read();
        a[x].push_back(Node(t, y));
    }
    for (int i = 1; i <= n; i++)
        sort(a[i].begin(), a[i].end());
    
    auto check = [&] (int T) {
        vector<pii> cost;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            int siz = a[i].size();
            for (int j = siz - 1; j >= 0; j--) {
                if (a[i][j].tim > T) continue;
                if ((T - a[i][j].tim - cnt) * k > a[i][j].pos) {
                    int now = (((T - a[i][j].tim - cnt) * k) - a[i][j].pos + k) / k;
                    cnt += now;
                    cost.push_back({a[i][j].tim, now});
                }
            }
        }
        sort(cost.begin(), cost.end());
        int sum = 0;
        int siz = cost.size();
        for (int i = siz - 1; i >= 0; i--) {
            sum += cost[i].second;
            if (sum > T - cost[i].first)
                return false;
        }
        return true;
    };

    int L = 1, R = INF;
    while (L + 1 < R) {
        int mid = (R + L) / 2;
        if (check (mid))
            L = mid;
        else 
            R = mid;
    }
    if (L == INF - 1)   
        puts("-1");
    else
        write(L - 1);
    return 0;
}