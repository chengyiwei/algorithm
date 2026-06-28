#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen ("M.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<int> fa(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    function<int(int)> find = [&] (int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    };

    function<void(int, int)> merge = [&] (int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            fa[x] = y;
        }
    };

    function<bool(int, int)> same = [&] (int x, int y) {
        return find(x) == find(y);
    };

    int cnt = 0;
    for (int i = 0 ; i < m; i++) {
        int x, y; cin >> x >> y;
        if (same(x, y)) {
            cnt += 1;
        }
        else {
            merge(x, y);
        }
    }

    cout << n - 1 - m + 2 * cnt << "\n";
    return 0;
}