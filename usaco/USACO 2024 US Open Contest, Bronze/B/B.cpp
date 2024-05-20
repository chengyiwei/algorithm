#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
typedef long long ll;
int id[maxn][maxn];
int main() {
    freopen("B.in", "r", stdin);
    int N, P; cin >> N >> P;
    vector<pair<int, int> > v(P);
    for (int i = 0; i < P; i++) {
        cin >> v[i].first >> v[i].second;
    }
    int cnt = 0;
    for (int i = 0; i < P; i++) {
        auto [x1, y1] = v[i];
        auto [x2, y2] = v[(i + 1) % P];
        if (x1 == x2) {
            if (y1 < y2) 
                for (int j = y1; j < y2; j++)
                    id[x1][j] = ++cnt;
            else 
                for (int j = y1; j > y2; j--)
                    id[x1][j] = ++cnt;
        }
        else {
            if (x1 < x2) 
                for (int j = x1; j < x2; j++)
                    id[j][y1] = ++cnt;
            else 
                for (int j = x1; j > x2; j--)
                    id[j][y1] = ++cnt;
        }
    }
    for (int i = 1; i <= N; i++) {
        int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
        int now = abs(id[sx][sy] - id[ex][ey]);
        int ans = min(now, cnt - now);
        cout << ans << endl;
    }
    return 0;
}