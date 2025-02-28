#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve1(int n) {
        string s; cin >> s;
        vector<int> emp;
        vector<int> a(s.size());
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0' || s[i] == '1') {
                a[i] = s[i] - '0';
            } else {
                emp.push_back(i);
            }
        }

        ll ans = 0;

        for (int S = 0; S < (1 << emp.size()); S++) {
            vector<int> b = a;
            for (int i = 0; i < emp.size(); i++) {
                if (S & (1 << i)) b[emp[i]] = 1;
                else b[emp[i]] = 0;
            }
            for (int i = 0; i < b.size(); i++) {
                b[i] = !b[i];
                if (b.front() == b.back()) 
                    ans++;
                b[i] = !b[i];
            }
        }

        cout << ans << '\n';
}

int main() {
    int T; cin >> T;
    while (T--) {

        int n; cin >> n;
        
        if (n == 1) {
            solve1(n);
            continue;
        }

        ll ans = 0;
        
        vector<int> emp_in, emp_out;
        vector<int> a(n);
        string s; cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' || s[i] == '1') {
                a[i] = s[i] - '0';
            } else {
                if (i == 0 || i == n - 1) {
                    emp_out.push_back(i);
                } else {
                    emp_in.push_back(i);
                }
            }
        }

        ll cnt0 = qpow(2, emp_in.size()), cnt1 = qpow(2, emp_in.size()) * (n - 2) % mod;

        for (int S = 0; S < (1 << emp_out.size()); S++) {
            vector<int> b = a;
            for (int i = 0; i < emp_out.size(); i++) {
                if (S & (1 << i)) b[emp_out[i]] = 1;
                else b[emp_out[i]] = 0;
            }
            if (b.front() == b.back()) {
                ans = (ans + cnt1) % mod;
            } else {
                ans = (ans + cnt0 * 2) % mod;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}