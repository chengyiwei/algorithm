#include <bits/stdc++.h>
using namespace std;

const int flg [4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
    freopen ("temp.in", "r", stdin);
    int n, m; cin >> n >> m;
    vector<vector<char>> mp(n + 1, vector<char> (m + 1, 0));
    auto vis = mp;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cin >> mp[i][j];
    
    priority_queue <pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> q;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == 'r') q.push({0,{i, j}}), vis[i][j] = 1;
        }

    while (!q.empty()) {
        auto [dis, pos] = q.top(); q.pop();
        auto [x, y] = pos;
        if (mp[x][y] == 'a') {cout << dis << "\n"; return 0;}
        for (int k = 0; k < 4; k++) {
            int x_ = x + flg[k][0], y_ = y + flg[k][1];
            if (!(1 <= x_ && x_ <= n && 1 <= y_ && y_ <= m)) continue;
            if (vis[x_][y_] == 1 || mp[x_][y_] == '#') continue;
            int dis_ = dis + 1 + (mp[x_][y_] == 'x');
            vis[x_][y_] = 1;
            q.push({dis_, {x_, y_}});
        }
    }

    cout << "No way!" << "\n";
    return 0;
}