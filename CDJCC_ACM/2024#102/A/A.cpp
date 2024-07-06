#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string ll_to_string(ll x) {
    string res = "";
    while (x) {
        res += (char)(x % 10 + '0');
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

ll string_to_ll(string s) {
    ll res = 0;
    for (char c : s) {
        res = res * 10 + (c - '0');
    }
    return res;
}

int main() {
    ll N; cin >> N;
    int ans = 0;
    for (int i = 1; i <= 1e6; i++) {
        string a = ll_to_string(i), b = a;
        auto s = a + b;
        ll x = string_to_ll(s);
        if (1 <= x && x <= N) {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}