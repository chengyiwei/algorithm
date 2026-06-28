#include <bits/stdc++.h>
using namespace std;

bool check1(vector<vector<char> > &a) {
    int n = a.size() - 1, m = a[0].size() - 1;
    if (a[1][m] != '.') return false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == m) continue;
            if (a[i][j] == '.') return false;
        }
    return true;
} 

bool solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    if (!check1(a)) return false;
    vector<vector<vector<int>>> p(n + 1, vector<vector<int>>(m + 1, vector<int>()));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'L') {
                int i_ = i, j_ = j - 1;
                if (i_ < 1 || i_ > n || j_ < 1 || j_ > m || a[i_][j_] != 'C') return false;
                p[i_][j_].push_back(1);
            }
            if (a[i][j] == 'U') {
                int i_ = i - 1, j_ = j;
                if (i_ < 1 || i_ > n || j_ < 1 || j_ > m || a[i_][j_] != 'C') return false;
                p[i_][j_].push_back(2);
            }
            if (a[i][j] == 'R') {
                int i_ = i, j_ = j + 1;
                if (i_ < 1 || i_ > n || j_ < 1 || j_ > m || a[i_][j_] != 'C') return false;
                p[i_][j_].push_back(3);
            }
            if (a[i][j] == 'D') {
                int i_ = i + 1, j_ = j;
                if (i_ < 1 || i_ > n || j_ < 1 || j_ > m || a[i_][j_] != 'C') return false;
                p[i_][j_].push_back(0);
            }
        }
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'C') {
                if (p[i][j].size() != 2) return false;
                if (abs(p[i][j][0] - p[i][j][1]) == 2 )
                    return false;
            }
        }
    
    return true;
}

int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) 
        cout << (solve() ? "Yes" : "No") << endl;
    return 0;
}