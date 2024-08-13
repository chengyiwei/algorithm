#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    vector<ll> c(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    
    vector<vector<ll> > pre(n + 2 , vector<ll>(2, 0)); auto lst = pre;
    for (int i = 1; i <= n; i++) {
        pre[i][0] = pre[i - 1][1] + c[i] * (s[i] != '0');
        pre[i][1] = pre[i - 1][0] + c[i] * (s[i] != '1');
    }
    for (int i = n; i > 0; i--) {
        lst[i][0] = lst[i + 1][1] + c[i] * (s[i] != '0');
        lst[i][1] = lst[i + 1][0] + c[i] * (s[i] != '1');
    }

    ll ans = INF;

    //00
    for (int i = 1; i < n; i++) {
        ll now = c[i] * (s[i] != '0') + c[i + 1] * (s[i + 1] != '0');
        now += pre[i - 1][1] + lst[i + 2][1];
        ans = min(ans, now);
    }
    //11
    for (int i = 1; i < n; i++) {
        ll now = c[i] * (s[i] != '1') + c[i + 1] * (s[i + 1] != '1');
        now += pre[i - 1][0] + lst[i + 2][0];
        ans = min(ans, now);
    }
    cout << ans << '\n';
    return 0;
}