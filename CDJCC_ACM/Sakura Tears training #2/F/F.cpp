#include <bits/stdc++.h>
using namespace std;

const int MAXM = 2e6 + 5;

struct Node {
    int l, r;
    int left, right, sum;
    Node() {l = r = left = right = sum = 0;}
    Node(int l, int r, int left, int right, int sum) : l(l), r(r), left(left), right(right), sum(sum) {}
};

Node merge(const Node &a, const Node &b) {
    return Node(a.l, b.r, (a.left == a.r - a.l + 1) ? a.left + b.left : a.left, (b.right == b.r - b.l + 1) ? b.right + a.right : b.right, max({a.sum, b.sum, a.right + b.left}));
}

struct Segment_Tree {
    vector<Node> tr;
    Segment_Tree(int n) : tr(4 * n) {}

    void build (int u, int l, int r) {
        if (l == r) {tr[u] = Node(l, r, 1, 1, 1); return;}
        int mid = (l + r) >> 1;
        build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
        tr[u] = merge(tr[u << 1], tr[u << 1 | 1]);
    }

    void update(int u, int pos, int val) {
        if (tr[u].l == tr[u].r) {
            tr[u] = Node(tr[u].l, tr[u].r, val, val, val);
            return;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (pos <= mid) update(u << 1, pos, val);
        else update(u << 1 | 1, pos, val);
        tr[u] = merge(tr[u << 1], tr[u << 1 | 1]);
    }

    int query(int u, int k) {
        if (tr[u].l == tr[u].r) return tr[u].l;
        if (tr[u << 1].sum >= k) return query(u << 1, k);
        if (tr[u << 1].right + tr[u << 1 | 1].left >= k) return tr[u << 1].r - tr[u << 1].right + 1;
        return query(u << 1 | 1, k);
    }
};

int main() {
    freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    set<int> s;
    Segment_Tree tr(MAXM);
    tr.build(1, 1, MAXM);

    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            s.insert(x);
            tr.update(1, x, 0);
        }
        int m; cin >> m;
        while (m--) {
            char op; cin >> op;
            if (op == '+') {
                int x; cin >> x;
                s.insert(x); tr.update(1, x, 0);
            }
            else if (op == '-') {
                int x; cin >> x;
                s.erase(x); tr.update(1, x, 1);
            }
            else if (op == '?') {
                int k; cin >> k;
                if (k > tr.tr[1].sum) cout << MAXM - tr.tr[1].right + 1 << ' ';
                else cout << tr.query(1, k) << ' ';
            } 
        }
        cout << '\n';

        for (auto x : s) tr.update(1, x, 1);
    }
    return 0;
}