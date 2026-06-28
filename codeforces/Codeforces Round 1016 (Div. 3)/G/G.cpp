#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    struct Node {
        int x, max_son;
        int ch[2];
        Node() : x(0), max_son(0) {
            ch[0] = ch[1] = -1;
        }
    };
    
    int cnt = 0;
    vector<Node> tree(n * 61);
    
    auto insert = [&] (int x, int id) {
        int cur = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (tree[cur].ch[bit] == -1) {
                tree[cur].ch[bit] = ++cnt;
                tree[cnt] = Node();
            }
            cur = tree[cur].ch[bit];
            tree[cur].max_son = max(tree[cur].max_son, id);
        }
        tree[cur].x = id;
    };

    auto query = [&] (int x) {
        int cur = 0, ret = 0;
        for (int i = 30; i >= 0; i--) {
            int bit_k = (k >> i) & 1, bit_x = (x >> i) & 1;
            if (bit_k == 1) {
                cur = tree[cur].ch[bit_x ^ 1];
            }
            else {
                if (tree[cur].ch[bit_x ^ 1] != -1)
                    ret = max(ret, tree[tree[cur].ch[bit_x ^ 1]].max_son);
                cur = tree[cur].ch[bit_x];
            }
            if (cur == -1) break;
        }
        if (cur != -1)
            ret = max(ret, tree[cur].max_son);
        // ret = max(ret, tree[cur].max_son);
        return ret;
    };

    int ans = INF;
    for (int i = 1; i <= n; i++) {
        insert(a[i], i);
        int ret = query(a[i]);
        if (ret > 0) {
            ans = min(ans, i - ret + 1);
        }
    }
    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    freopen ("G.in", "r", stdin);
    freopen ("G.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
    return 0;
}