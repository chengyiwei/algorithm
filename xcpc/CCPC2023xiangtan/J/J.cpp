#include <bits/stdc++.h>
using namespace std;


int check (string a, string b) { // b in a
    int lena = a.size(), lenb = b.size();
    int ret = 0;
    a = " " + a, b = " " + b;
    vector<vector<int> > dp (lena + 1, vector<int> (lenb + 1, 0));
    for (int i = 1; i <= lena; i ++)
        for (int j = 1; j <= lenb; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                ret = max(ret, dp[i][j]);
            }
        }
    return ret;
}

void solve() {
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    } 
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++) {
            ans = max (ans, check(a[i],a[j]));
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen ("J.in","r",stdin);
    int t; cin >> t;
    while (t--) solve();
}