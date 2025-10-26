#include <bits/stdc++.h>
using namespace std;

struct Node {
    int sum, pre_min; // sum of the segment, mini
    Node (int sum = 0, int pre_min = 0) : sum(sum), pre_min(pre_min) {}
};

struct Segment_Tree {
    int n;
    vector<Node> t;
    Segment_Tree(int n = 0) {
        t.assign(4 * n, {0, 0});
        this->n = n;
    }

    Node merge(const Node &a, const Node &b) {
        Node res;
        res.sum = a.sum + b.sum;
        res.pre_min = min(a.pre_min, a.sum + b.pre_min);
        return res;
    }

    void build(const vector<int> &arr, int u, int l, int r) {
        if (l == r) {
            t[u] = Node(arr[l], arr[l]);
            return ;
        }
        int mid = (l + r) >> 1;
        build(arr, u << 1, l, mid); build(arr, u << 1 | 1, mid + 1, r);
        t[u] = merge(t[u << 1], t[u << 1 | 1]);
    }

    void update(int u, int l, int r, int pos, int val) {
        if (l == r) {
            t[u].sum += val; t[u].pre_min += val;
            return ;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(u << 1, l, mid, pos, val);
        else update(u << 1 | 1, mid + 1, r, pos, val);
        t[u] = merge(t[u << 1], t[u << 1 | 1]);
    }

    int query(int u, int l, int r, int need) {
        if (t[u].pre_min >= need) return -1;
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (t[u << 1].pre_min < need) 
            return query(u << 1, l, mid, need);
        else 
            return query(u << 1 | 1, mid + 1, r, need - t[u << 1].sum);
    }

    Node get(int u, int l, int r, int pos) {
        if (l == r) return t[u];
        int mid = (l + r) >> 1;
        if (pos <= mid) return get(u << 1, l, mid, pos);
        else return get(u << 1 | 1, mid + 1, r, pos);
    }
};

void solve() {
    int ac, dr; cin >> ac >> dr;
    int n; cin >> n;
    vector<int> a(n + 1, 0), d(n + 1, 0);   
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    int m; cin >> m;
    int cnt = n;
    vector<int> c(cnt + 1, 0);
    vector<int> nd(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        nd[i] = max(0, a[i] - ac) + max(0, d[i] - dr);
        if (nd[i] <= cnt) c[nd[i]] += 1;
    }
    vector<int> arr(cnt + 1, 0);
    for (int i = 0; i <= cnt; i++) arr[i] = c[i] - 1;

    Segment_Tree seg(cnt + 1);
    seg.build(arr, 1, 0, cnt);
    
    while (m--) {
        int k, na, nb; cin >> k >> na >> nb;
        if (nd[k] <= cnt && c[nd[k]] - 1 >= 0) {
            seg.update(1, 0, cnt, nd[k], -1);
        }
        a[k] = na; d[k] = nb;
        nd[k] = max(0, a[k] - ac) + max(0, d[k] - dr);
        if (nd[k] <= cnt) {
            c[nd[k]] += 1;
            seg.update(1, 0, cnt, nd[k], 1);
        }
        auto res_pos = seg.query(1, 0, cnt, 0);
        if (res_pos == -1) { cout << "0\n"; }
        int res = seg.get(1, 0, cnt, res_pos).sum + res_pos + 1;
        cout << res << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}