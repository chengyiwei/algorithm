#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pll;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int main() {
    freopen ("F.in", "r", stdin);
    int n; cin >> n;
    vector<vector<LL> > P(n + 1, vector<LL>(n + 1)), D(n + 1, vector<LL>(n + 1)), R(n + 1, vector<LL>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> P[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < n; j++)
            cin >> R[i][j];
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= n; j++)
            cin >> D[i][j];
    
    auto get_dis = [&](int x, int y) {
        vector<vector<LL> > dis(n + 1, vector<LL>(n + 1, INF));
        dis[x][y] = 0;
        for (int px = n; px >= 1; px--)
            for (int py = n; py >= 1; py--) {
                if (px < x) 
                    dis[px][py] = min(dis[px][py], dis[px + 1][py] + D[px][py]);
                if (py < y)
                    dis[px][py] = min(dis[px][py], dis[px][py + 1] + R[px][py]);
            }
        return dis;
    };

    vector<vector<pll> > dp(n + 1, vector<pll>(n + 1, {INF,INF}));
    dp[1][1] = {0,0};
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++) {
            auto dis = get_dis(x,y);
            for (int px = 1; px <= x; px++)
                for (int py = 1; py <= y; py++){
                    auto [p_step, p_money] = dp[px][py];
                    LL ex_step = (dis[px][py] - p_money + P[px][py] - 1) / P[px][py]; ex_step = max(ex_step, 0LL);
                    LL now_step = p_step + ex_step + (x - px) + (y - py);
                    LL now_money = p_money + ex_step * P[px][py] - dis[px][py];
                    if (now_step < dp[x][y].first || (now_step == dp[x][y].first && now_money > dp[x][y].second))
                        dp[x][y] = {now_step, now_money};
                }
        }
    cout << dp[n][n].first << endl;
    return 0;
}