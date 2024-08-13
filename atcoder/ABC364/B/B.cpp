#include <bits/stdc++.h>
using namespace std;

int flg[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
map<char, int> p = {{'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

int main() {
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y;
    vector<vector<char>> mp(n + 1, vector<char>(m + 1, 0));
    string s; 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    cin >> s;
    for (auto c : s) {
        int nx = x + flg[p[c]][0], ny = y + flg[p[c]][1];
        if (nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] == '#') continue;
        x = nx, y = ny;
    }
    cout << x << " " << y << endl;
    return 0;
}