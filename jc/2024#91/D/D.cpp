#include <bits/stdc++.h>
using namespace std;

bool cmp (string x, string y) {
    if (x.size() != y.size()) return x.size() < y.size();
    return x < y;
}

int main() {
    // freopen ("D.in", "r", stdin);
    int n; cin >> n;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end(), cmp);
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] == a[i].substr(0, a[j].size())) {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += 1;
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}