#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    vector<int> id(n + 1);
    vector<vector<int> > a(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
        cin >> id[i];
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[id[i]].push_back(x);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].size() <= 1) continue;
        sort(a[i].begin(), a[i].end());
        for (int j = 0; j + 1 < a[i].size(); j++)
            ans += a[i][j];
    }
    cout << ans << endl;
    return 0;
}