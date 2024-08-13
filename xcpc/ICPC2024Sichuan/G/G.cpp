#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int inf = 0x3f3f3f3f;
const int tp = 30;
struct Node {
    int val, siz, max, min;
    Node () {
        siz = 0; max = -inf; min = inf; val = -1;
    }
};

int cnt = 0;
Node t[maxn * tp];
int nxt[maxn * tp][2];
int siz, max_, min_, same;

void push_up (int x) {
    t[x].siz += t[nxt[x][0]].siz + t[nxt[x][1]].siz;
    t[x].max = max(t[x].max, max(t[nxt[x][0]].max, t[nxt[x][1]].max));
    t[x].min = min(t[x].min, min(t[nxt[x][0]].min, t[nxt[x][1]].min));
}

void insert (int x, int id) {
    int p = 0;
    for (int i = tp; i >= 0; i--) {
        int now = (x >> i) & 1;
        if (!nxt[p][now]) {
            cnt += 1;
            nxt[p][now] = cnt;
        }
        p = nxt[p][now];
    }
    t[p].siz += 1; t[p].val = id; t[p].max = max(t[p].max, id); t[p].min = min(t[p].min, id);
}

void find_same (int a, int b) {
    int p = 0;
    for (int i = tp; i >= 0; i--) {
        int now_a = (a >> i) & 1, now_b = (b >> i) & 1;
        p = nxt[p][now_a ^ now_b];
        if (!p) return ;
    }
    if (t[p].val != -1) same = t[p].val;
}

void find_big (int a, int b) {
    int p = 0;
    for (int i = tp; i >= 0; i--) {
        int now_a = (a >> i) & 1, now_b = (b >> i) & 1;
        if (now_b == 0) {
            int p_ = nxt[p][now_a ^ now_b ^ 1];
            if (p_) {
                siz += t[p_].siz; max_ = max(max_, t[p_].max); min_ = min(min_, t[p_].min);
            }
        }
        p = nxt[p][now_a ^ now_b];
        if (!p) break;
    }
}

void find_small (int a, int b) {
    int p = 0;
    for (int i = tp; i >= 0; i--) {
        int now_a = (a >> i) & 1, now_b = (b >> i) & 1;
        if (now_b == 1) {
            int p_ = nxt[p][now_a ^ now_b ^ 1];
            if (p_) {
                siz += t[p_].siz; max_ = max(max_, t[p_].max); min_ = min(min_, t[p_].min);
            }
        }
        p = nxt[p][now_a ^ now_b];
        if (!p) break;
    }
}

void dfs (int x) {
    for (int i = 0; i < 2; i++)
        if (nxt[x][i]) dfs(nxt[x][i]);
    push_up(x);
}

int main() {
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        insert(x, i);
    }
    
    dfs(0);

    while (q--) {
        int a, b; cin >> a >> b;
        same = -1; find_same(a, b);
        if (same != -1) {
            if (same + 1 <= n) {cout << same << '\n'; continue;}
            if (same - 1 >= 1) {cout << same - 1 << '\n'; continue;}
        }

        siz = 0; max_ = -inf; min_ = inf; find_big(a, b);
        if (siz != 0 && siz != n) {
            if (max_ + 1 <= n) {cout << max_ << '\n'; continue;}
            if (min_ - 1 >= 1) {cout << min_ - 1 << '\n'; continue;}
        }

        siz = 0; max_ = -inf; min_ = inf; find_small(a, b);
        if (siz != 0 && siz != n) {
            if (max_ + 1 <= n) {cout << max_ << '\n'; continue;}
            if (min_ - 1 >= 1) {cout << min_ - 1 << '\n'; continue;}
        }

        cout << -1 << '\n';
    }
    return 0;
}