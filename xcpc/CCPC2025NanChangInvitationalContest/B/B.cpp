#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 5005;

int dis[MAXN][MAXN];
int vis[MAXN];
int mp[MAXN][MAXN];
int nxt[MAXN], pre[MAXN];
int que[MAXN];

void erase(int x) {
    nxt[pre[x]] = nxt[x];
    pre[nxt[x]] = pre[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            char x; cin >> x;
            if (x == '1') mp[i][j] = 1;
            mp[j][i] = !mp[i][j];
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int i = 1; i <= n; i++) { pre[i] = i - 1; nxt[i] = i + 1; vis[i] = 0;}
        pre[n + 1] = n; nxt[0] = 1; erase(i); vis[i] = 1;
        int head = 0, tail = 0, cnt = 1;

        que[tail++] = i;
        while (head < tail) {
            int u = que[head++];
            for (int v = nxt[0]; v <= n; v = nxt[v]) {
                if (mp[u][v] && !vis[v]) {
                    vis[v] = 1;
                    dis[i][v] = dis[i][u] + 1;
                    erase(v);
                    if (dis[i][v] <= 100)
                        que[tail++] = v;
                    if (++cnt == n) break;
                }
            }
            if (cnt == n) break;
        }
    }

    while (q--) {
        int u, v; cin >> u >> v;
        cout << (dis[u][v] ? dis[u][v] - 1 : -1) << '\n';
    }

    return 0;
}

/*

4 1
110
11
1
1 4

4 12
110
11
1
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
*/