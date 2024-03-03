#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int flg[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<char> > mp(n+1, vector<char>(m+1));
    pii Y, N;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            char ch; cin >> ch;
            mp[i][j] = ch;
            if (ch == 'Y') Y = {i, j};
            if (ch == 'N') N = {i, j};
        }
    
    auto bfs = [&](pii st){
        vector<vector<int> > dis(n+1, vector<int>(m+1, -1));
        queue<pii> q; q.push(st);
        dis[st.first][st.second] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; k ++) {
                int nx = x + flg[k][0], ny = y + flg[k][1];
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if (mp[nx][ny] == '#') continue;
                if (dis[nx][ny] != -1) continue;
                dis[nx][ny] = dis[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return dis;
    };

    auto disY = bfs(Y), disN = bfs(N);
    
    int ans = -1;
    for (int i = 1; i <= n; i ++) 
        for (int j = 1; j <= m; j ++) 
            if (mp[i][j] == 'K') {
                if (disY[i][j] != -1 && disN[i][j] != -1) {
                    int tmp = max(disY[i][j], disN[i][j]);
                    if (ans == -1 || ans > tmp) ans = tmp;
                }
            }
    if (ans == -1)
        cout << "I am broke-hearted." << endl;
    else 
        cout << ans * 3 << endl;
    return 0;
}