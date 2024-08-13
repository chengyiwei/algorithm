#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    freopen ("D.in", "r", stdin);
    string T; cin >> T; T = " " + T;
    int n; cin >> n;
    vector<vector<string> > a(n + 1);
    for (int i = 1; i <= n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            string s; cin >> s;
            a[i].push_back(s);
        }
    }
    vector<vector<int> > dp(n + 1, vector<int>(T.size(), INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < T.size(); j++) {
            for (int k = 0; k < a[i].size(); k++) {
                if (j + a[i][k].size() - 1 >= T.size()) continue;
                if (T.substr(j, a[i][k].size()) == a[i][k])
                    dp[i][j + a[i][k].size() - 1] = min(dp[i][j + a[i][k].size() - 1], dp[i - 1][j - 1] + 1);
            }
        }

        for (int j = 0; j < T.size(); j++)
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
    }
    int ans = INF;
    for (int i = 1; i <= n; i++)
        ans = min(ans, dp[i][T.size() - 1]);
    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}