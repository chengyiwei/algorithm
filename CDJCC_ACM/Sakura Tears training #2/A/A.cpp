#include <bits/stdc++.h>
using namespace std;

struct Hash {
    int n, p, mod;
    vector<int> h, pw;

    void init(string s, int p_, int mod_) {
        n = s.size(); p = p_; mod = mod_;
        h.resize(n); pw.resize(n);
        h[0] = s[0] - 'a' + 1; pw[0] = 1;
        for (int i = 1; i < n; i++) {
            h[i] = (1LL * h[i - 1] * p + s[i] - 'a' + 1) % mod;
            pw[i] = 1LL * pw[i - 1] * p % mod;
        }
    }

    int get(int l, int r) {
        if (l == 0) return h[r];
        return (h[r] - 1LL * h[l - 1] * pw[r - l + 1] % mod + mod) % mod;
    }
};

int main() {
    freopen ("A.in", "r", stdin);
    string s; cin >> s;
    Hash h1, h2;
    h1.init(s, 31, 1e9 + 7); h2.init(s, 37, 1e9 + 9);
    for (int len = s.size() / 2 + 1; len < s.size(); len ++) {
        if (h1.get(0, len - 1) == h1.get(s.size() - len, s.size() - 1) && h2.get(0, len - 1) == h2.get(s.size() - len, s.size() - 1)) {
            cout << "YES\n" << s.substr(0, len) << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}