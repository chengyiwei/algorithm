#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> b(n + 1); b = a;
    sort(b.begin() + 1, b.end());
    vector<vector<ll> > dp(n + 1, vector<ll>(n + 1, INF)), pre_min(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) pre_min[0][i] = 0; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = pre_min[i - 1][j] + abs(a[i] - b[j]);
            pre_min[i][j] = min(pre_min[i][j - 1], dp[i][j]);
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
    return 0;
}