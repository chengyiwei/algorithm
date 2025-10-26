#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 200005;
const int INF = 0x3f3f3f3f;

int N;
char grid[3][MAXN];

struct SegNode {
    int l, r;
    int mat[3][3];
};

SegNode tree[4 * MAXN];

void initLeaf(SegNode &node, int col) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int low = min(i, j);
            int high = max(i, j);
            if (low == high) {
                if (grid[i][col] == '.') {
                    node.mat[i][j] = 0;
                } else {
                    node.mat[i][j] = INF;
                }
            } else {
                bool connected = true;
                for (int r = low; r < high; r++) {
                    if (grid[r][col] == '#' || grid[r+1][col] == '#') {
                        connected = false;
                        break;
                    }
                }
                if (connected) {
                    node.mat[i][j] = high - low;
                } else {
                    node.mat[i][j] = INF;
                }
            }
        }
    }
    node.l = col;
    node.r = col;
}

void merge(SegNode &res, const SegNode &left, const SegNode &right) {
    int mid = left.r;
    int T_mat[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            T_mat[i][j] = INF;
            if (i == j) {
                if (grid[i][mid] == '.' && grid[i][mid+1] == '.') {
                    T_mat[i][j] = 1;
                }
            }
            for (int m = 0; m < 3; m++) {
                if (grid[m][mid] != '.' || grid[m][mid+1] != '.') {
                    continue;
                }
                int low1 = min(i, m);
                int high1 = max(i, m);
                bool connected1 = true;
                for (int r = low1; r < high1; r++) {
                    if (grid[r][mid] == '#' || grid[r+1][mid] == '#') {
                        connected1 = false;
                        break;
                    }
                }
                if (!connected1) continue;

                int low2 = min(m, j);
                int high2 = max(m, j);
                bool connected2 = true;
                for (int r = low2; r < high2; r++) {
                    if (grid[r][mid+1] == '#' || grid[r+1][mid+1] == '#') {
                        connected2 = false;
                        break;
                    }
                }
                if (!connected2) continue;

                int steps = llabs(i - m) + 1 + llabs(m - j);
                if (steps < T_mat[i][j]) {
                    T_mat[i][j] = steps;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            res.mat[i][j] = INF;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (left.mat[i][k] < INF && T_mat[k][l] < INF && right.mat[l][j] < INF) {
                        int total = left.mat[i][k] + T_mat[k][l] + right.mat[l][j];
                        if (total < res.mat[i][j]) {
                            res.mat[i][j] = total;
                        }
                    }
                }
            }
        }
    }
    res.l = left.l;
    res.r = right.r;
}

void build(int o, int l, int r) {
    if (l == r) {
        initLeaf(tree[o], l);
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    merge(tree[o], tree[o << 1], tree[o << 1 | 1]);
}

void update(int o, int l, int r, int col) {
    if (l == r) {
        initLeaf(tree[o], col);
        return;
    }
    int mid = (l + r) >> 1;
    if (col <= mid) {
        update(o << 1, l, mid, col);
    } else {
        update(o << 1 | 1, mid + 1, r, col);
    }
    merge(tree[o], tree[o << 1], tree[o << 1 | 1]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < 3; i++) {
        cin >> grid[i];
    }

    build(1, 0, N - 1);

    int Q;
    cin >> Q;
    while (Q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (grid[r][c] == '.') {
            grid[r][c] = '#';
        } else {
            grid[r][c] = '.';
        }

        update(1, 0, N - 1, c);

        int ans = tree[1].mat[0][2];
        if (ans >= INF) {
            cout << "-1\n";
        } else {
            cout << ans << '\n';
        }
    }

    return 0;
}