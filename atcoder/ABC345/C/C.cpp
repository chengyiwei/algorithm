#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string s; cin >> s;
    ll n = s.size(); s = " " + s;
    vector<ll> num(26,0);
    ll ans = 0, flg = 0;
    for (int i = 1; i <= n; i++) {
        if (num[s[i] - 'a'] > 0) flg = 1;
        num[s[i] - 'a']++;
        ans += i - num[s[i] - 'a'];
    }
    cout << ans + flg << '\n';
}