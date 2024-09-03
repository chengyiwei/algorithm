#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct Node {
    int val;
    pair<int, int> pos;
    bool operator < (const Node &rhs) const {
        return val < rhs.val;
    }
};

Node merge (Node a, Node b) {
    return a.val < b.val ? b : a;
}

struct Segment_Tree {
    vector<Node> tr;
    Segment_Tree(int n) : tr(n << 2) {}

    void push_up (int x) {
        tr[x] = merge(tr[x << 1], tr[x << 1 | 1]);
    }

    void update (int x, int l, int r, int pos, Node val) {
        if (l == r) {
            if (tr[x] < val) tr[x] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(x << 1, l, mid, pos, val);
        else update(x << 1 | 1, mid + 1, r, pos, val);
        push_up(x);
    }

    Node query (int x, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return Node({0, {0, 0}});
        if (ql <= l && r <= qr) return tr[x];
        int mid = (l + r) / 2;
        return merge(query(x << 1, l, mid, ql, qr), query(x << 1 | 1, mid + 1, r, ql, qr));
    }
};

int main() {
    freopen ("F.in", "r", stdin);
    int N, M, K; cin >> N >> M >> K;
    vector<pii> pos(K + 1);
    map<pii, pii> pre;
    for (int i = 1; i <= K; i++) cin >> pos[i].first >> pos[i].second;

    Segment_Tree seg(M + 1);

    sort(pos.begin() + 1, pos.end());
    for (int i = 1; i <= K; i++) {
        auto [x, y] = pos[i];
        Node tmp = seg.query(1, 1, M, 1, y);
        if (tmp.val) pre[{x, y}] = tmp.pos;
        seg.update(1, 1, M, y, {tmp.val + 1, {x, y}});
    }

    Node ans = seg.query(1, 1, M, 1, M);
    cout << ans.val << '\n';
    vector<pii> res;
    for (auto [x, y] = ans.pos;;) {
        res.push_back({x, y});
        if (pre.find({x, y}) == pre.end()) break;
        auto [nx, ny] = pre[{x, y}];
        x = nx, y = ny;
    }
    res.push_back({1, 1});
    reverse(res.begin(), res.end());
    res.push_back({N, M});
    // for (auto [x, y] : res) cout << x << ' ' << y << '\n'; 
    string ans_;
    for (int i = 0; i + 1 < res.size(); i++) {
        int dx = res[i + 1].first - res[i].first;
        int dy = res[i + 1].second - res[i].second;
        for (int j = 0; j < dx; j++) ans_.push_back('D');
        for (int j = 0; j < dy; j++) ans_.push_back('R');
    }
    cout << ans_ << '\n';
    return 0;
}