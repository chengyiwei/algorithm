#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;


int main() {
    freopen ("D.in", "r", stdin);
    int n; cin >> n;
    int H, W; cin >> H >> W;
    vector<pii> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    auto check = [&]  (vector<int> &id, int S) {
        vector<vector<int> > v(H + 1, vector<int>(W + 1,0));
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                pq.push({i,j});
            }
        }
        for (int i = 1; i <= n; i++) {
            auto &[dx, dy] = a[id[i]];
            if (S >> (i - 1) & 1) 
                swap(dx, dy);
            while (!pq.empty() && v[pq.top().first][pq.top().second]) pq.pop();
            if (pq.empty()) {return 1;}
            auto [x, y] = pq.top(); pq.pop();
            for (int i_ = x; i_ < x + dx; i_++) {
                for (int j_ = y; j_ < y + dy; j_++) {
                    if (i_ > H || j_ > W || v[i_][j_] == 1) return 0;
                    v[i_][j_] = 1;
                }
            }
        }
        while (!pq.empty() && v[pq.top().first][pq.top().second]) pq.pop();
        if (pq.empty()) return 1;
        return 0;
    };

    vector<int> id (n + 1);
    iota(id.begin(), id.end(), 0);
    do {
        for (int S = 0; S < (1<<n); S++) 
            if (check(id, S)) {cout << "Yes\n"; return 0;}  
    } while (next_permutation(id.begin() + 1, id.end()));
    cout << "No\n";
    return 0;
}