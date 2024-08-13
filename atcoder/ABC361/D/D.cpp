#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    string A, B; cin >> A >> B;
    int A_ = 0, B_ = 0;
    for (int i = 0; i < n; i++) {
        A_ |= (A[i] == 'W') << i;
        B_ |= (B[i] == 'W') << i;
    }

    map<pii, int> dis;
    queue<pii> q; q.push({A_, n}); dis[{A_, n}] = 0;
    while (!q.empty()) {
        auto [S, pos] = q.front(); q.pop();
        if (S == B_ && pos == n) {
            cout << dis[{S, pos}] << endl;
            return 0;
        }
        for (int i = 0; i + 1 < n + 2; i++) {
            if (i + 1 == pos || i == pos || i == pos + 1) continue;
            int nxt = S;
            if (S >> i & 1) nxt |= 1 << pos;
            else nxt &= ~(1 << pos);
            if (S >> (i + 1) & 1) nxt |= 1 << (pos + 1);
            else nxt &= ~(1 << (pos + 1));

            nxt &= ~(1 << i); nxt &= ~(1 << (i + 1));
            if (!dis.count({nxt, i})) {
                dis[{nxt, i}] = dis[{S, pos}] + 1;
                q.push({nxt, i});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}