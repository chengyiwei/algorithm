#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("B.in", "r", stdin);
    int n, m; cin >> n >> m;
    double p; cin >> p; p /= 100;
    vector<vector<int>> mp(n + 1, vector<int> (m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];

    vector<double> p_row(n + 1, 0);
    set<int> d; d.insert(3); d.insert(4); d.insert(n - 2); d.insert(n - 3);
    
    p_row[3] += p / 4; p_row[4] += p / 4; p_row[n - 2] += p / 4; p_row[n - 3] += p / 4;

    for (int i = 1; i <= n; i++) {
        if (i == 3 || i == 4 || i == n - 2 || i == n - 3) continue;
        p_row[i] += (1 - p) / (n - d.size());
    }

    vector<int> cnt_row(n + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cnt_row[i] += mp[i][j];
        }

    double min_x = 1e9; int min_i = 1;
    for (int i = 1; i <= n; i++) {
        if (cnt_row[i] == m) continue;
        double now_p = p_row[i] * (1.0 / (cnt_row[i]));
        if (min_x > now_p) {
            min_x = now_p;
            min_i = i;
        }
    }

    cnt_row[min_i] += 1;
    double res = p_row[min_i] / cnt_row[min_i];
    printf("%.2lf\n", res);

    return 0;
}