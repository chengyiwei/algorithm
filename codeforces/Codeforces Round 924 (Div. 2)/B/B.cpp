#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
void solve(){
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int L = 0, R = 0, ans = 0;
    for (;L < a.size(); L++){
        while(R < a.size() && a[R] - a[L] <= n - 1)
            R++;
        ans = max(ans, R - L);
    }
    cout << ans << '\n';
}

int main(){
    freopen("B.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}