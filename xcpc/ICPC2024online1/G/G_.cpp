#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;

struct Node {
    int fa, ch[2], siz, val;
};

struct Splay {
    vector<Node> t;
    int root, tot;
    Splay(int n) {
        root = tot = 0;
        t.resize(n);
    }
    bool ident(int x, int f) {return t[f].ch[1] == x;}
    void connect (int x, int f, int s) {
        t[f].ch[s] = x;
        t[x].fa = f;
    }
    void push_up(int x) {
        t[x].siz = t[t[x].ch[0]].siz + t[t[x].ch[1]].siz + 1;
    }

    void rotate(int x) {
        int f = t[x].fa, g = t[f].fa, k = ident(x, f);
        connect(x, g, ident(f, g));
        connect(t[x].ch[k ^ 1], f, k);
        connect(f, x, k ^ 1);
        push_up(f), push_up(x);
    }

    void splay(int x, int top) {
        if (top == 0) root = x;
        while (t[x].fa != top) {
            int f = t[x].fa, g = t[f].fa;
            if (g != top) {
                if (ident(x, f) == ident(f, g)) rotate(f);
                else rotate(x);
            }
            rotate(x);
        }
    }

    void new_node(int &x, int f, int val) {
        x = ++ tot;
        t[x].fa = f;
        t[x].val = val;
        t[x].siz = 1;
        t[x].ch[0] = t[x].ch[1] = 0;
    }

    void insert(int val, int &x, int f) {
        if (!x) new_node(x, f, val), splay(x, 0);
        else {
            if (val < t[x].val) insert(val, t[x].ch[0], x);
            else insert(val, t[x].ch[1], x);
        }
    }

    int kth(int k) {
        int x = root;
        while (x) {
            if (k == t[t[x].ch[0]].siz + 1) {
                splay(x, 0); break;
            }
            else {
                if (k <= t[t[x].ch[0]].siz) x = t[x].ch[0];
                else k -= t[t[x].ch[0]].siz + 1, x = t[x].ch[1];
            }
        }
        return t[x].val;
    }
};

int main() {
    freopen("G.in", "r", stdin);
    // freopen("G.out", "w", stdout);
    int n; cin >> n;
    vector<int> a(n + 1);
    Splay T(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<vector<int>> b(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        T = Splay(n + 1);
        for (int j = i; j <= n; j++) {
            T.insert(a[j], T.root, 0);
            int len = j - i + 1;
            b[i][j] = T.kth(len + 1 >> 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << b[i][j] << ' ';
        }
        cout << '\n';
    }

    vector<vector<int>> c(n + 1, vector<int>(n + 1, 0)), sum(n + 1, vector<int>(n + 1, 0));

    auto check = [&](int mid) -> bool {
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) {
                if (b[i][j] >= mid) c[i][j] = 1;
                else c[i][j] = -1;
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + c[i][j];
            }

        auto get = [&](int x1, int y1, int x2, int y2) -> int {
            return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
        };

        int num = 0, s = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++) {
                num += (get(i, 1, n, j) >= 0);
                s += 1;
            }
        return num >= (s + 1) / 2;
    };

    check(0);

    int l = 0, r = 1e9;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << '\n';
    return 0;
}