#include <bits/stdc++.h>
using namespace std;

struct Node {
    int nxt, cnt_a, cnt_b;
    Node(int nxt = 0, int cnt_a = 0, int cnt_b = 0) : nxt(nxt), cnt_a(cnt_a), cnt_b(cnt_b) {}
};

int main() {
    freopen ("J.in", "r", stdin);
    freopen ("J.out", "w", stdout);
    ios::sync_with_stdio(false);
    int n, A, B; cin >> n >> A >> B;
    string s; cin >> s;
    vector<array<Node, 20>> f(n), g(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') f[i][0] = Node((i + 1) % n, 1, 0);
        else f[i][0] = Node((i + 1) % n, 0, 1);
    }
    for (int j = 1; j < 20; j++)
        for (int i = 0; i < n; i++) {
            f[i][j].nxt = f[f[i][j - 1].nxt][j - 1].nxt;
            f[i][j].cnt_a = f[i][j - 1].cnt_a + f[f[i][j - 1].nxt][j - 1].cnt_a;
            f[i][j].cnt_b = f[i][j - 1].cnt_b + f[f[i][j - 1].nxt][j - 1].cnt_b;
        }
    vector<int> bo1(n), bo2(n);
    for (int i = 0; i < n; i++) {
        int cur = i, cnt_a = 0, cnt_b = 0;
        for (int j = 19; j >= 0; j--) {
            if (f[cur][j].cnt_a + cnt_a < A && f[cur][j].cnt_b + cnt_b < A) {
                cnt_a += f[cur][j].cnt_a;
                cnt_b += f[cur][j].cnt_b;
                cur = f[cur][j].nxt;
            }
        }
        if (s[cur] == '0') bo1[i] = 0, g[i][0] = Node((cur + 1) % n, 1, 0);
        else bo1[i] = 1, g[i][0] = Node((cur + 1) % n, 0, 1);
    }

    for (int j = 1; j < 20; j++)
        for (int i = 0; i < n; i++) {
            g[i][j].nxt = g[g[i][j - 1].nxt][j - 1].nxt;
            g[i][j].cnt_a = g[i][j - 1].cnt_a + g[g[i][j - 1].nxt][j - 1].cnt_a;
            g[i][j].cnt_b = g[i][j - 1].cnt_b + g[g[i][j - 1].nxt][j - 1].cnt_b;
        }
    for (int i = 0; i < n; i++) {
        int cur = i, cnt_a = 0, cnt_b = 0;
        for (int j = 19; j >= 0; j--) {
            if (g[cur][j].cnt_a + cnt_a < B && g[cur][j].cnt_b + cnt_b < B) {
                cnt_a += g[cur][j].cnt_a;
                cnt_b += g[cur][j].cnt_b;
                cur = g[cur][j].nxt;
            }
        }
        if (bo1[cur] == 0) bo2[i] = 0;
        else bo2[i] = 1;
    }
    for (int i = 0; i < n; i++) cout << bo2[i];
    return 0;
}