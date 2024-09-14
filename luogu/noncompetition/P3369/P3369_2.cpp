// splay
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

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

    void push_up (int x) {
        t[x].siz = t[t[x].ch[0]].siz + t[t[x].ch[1]].siz + 1;
    }

    void rotate (int x) {
        int f = t[x].fa, g = t[f].fa, k = ident(x, f);
        connect(x, g, ident(f, g));
        connect(t[x].ch[k ^ 1], f, k);
        connect(f, x, k ^ 1);
        push_up(f); push_up(x);
    }

    void splay (int x, int top) { //代表把x转到top的儿子，top为0则转到根结点
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

    void new_node (int &x, int f, int val) {
        x = ++tot;
        t[x].fa = f;
        t[x].val = val;
        t[x].siz = 1;
        t[x].ch[0] = t[x].ch[1] = 0;
    }

    void insert (int val, int &x, int f) {
        if (!x) new_node(x, f, val), splay(x, 0);
        else {
            if (val < t[x].val) insert(val, t[x].ch[0], x);
            else insert(val, t[x].ch[1], x);
        }
    }

    void del_node(int x) { // 注意这里可能存在内存浪费
        splay(x, 0);
        if (t[x].ch[1]) { // 存在右节点
            int p = t[x].ch[1]; // 找 x 的后继节点
            while (t[p].ch[0]) p = t[p].ch[0]; 
            splay(p, x);
            connect(t[x].ch[0], p, 0);
            root = p; t[root].fa = 0;
            push_up(p);
        }
        else {
            root = t[x].ch[0];
            t[root].fa = 0;
        }
    }

    void del(int val, int x) {
        if (val == t[x].val) del_node(x);
        else {
            if (val < t[x].val) del(val, t[x].ch[0]);
            else del(val, t[x].ch[1]);
        }
    }

    int get_rank(int val) {
        int x = root, res = 1, pre = 0;
        while (x) {
            if (val <= t[x].val) x = t[x].ch[0], pre = x;
            else res += t[t[x].ch[0]].siz + 1, x = t[x].ch[1];
        }
        if (pre) splay(pre, 0);
        return res;
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

    int pre(int val, int x) {
        if (!x) return -INF;
        if (val <= t[x].val) return pre(val, t[x].ch[0]);
        else return max(t[x].val, pre(val, t[x].ch[1]));
    }

    int nxt(int val, int x) {
        if (!x) return INF;
        if (val >= t[x].val) return nxt(val, t[x].ch[1]);
        else return min(t[x].val, nxt(val, t[x].ch[0]));
    }
};

Splay t(100005);

int main() {
    freopen ("P3369_2.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        int op, x; cin >> op >> x;
        if (op == 1) t.insert(x, t.root, 0);
        else if (op == 2) t.del(x, t.root);
        else if (op == 3) cout << t.get_rank(x)<< endl;
        else if (op == 4) cout << t.kth(x) << endl;
        else if (op == 5) cout << t.pre(x, t.root) << endl;
        else if (op == 6) cout << t.nxt(x, t.root) << endl;
    }
    return 0;
}