#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Hash {
    ll p, mod;
    vector<ll> h, pw;
    Hash (string s, ll p, ll mod) {
        this->p = p; this->mod = mod;
        h.resize(s.size() + 1); pw.resize(s.size() + 1);
        pw[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            pw[i] = pw[i - 1] * p % mod;
            h[i] = (h[i - 1] * p + s[i - 1]) % mod;
        }
    }

    ll get (int l, int r) {
        return (h[r] - h[l] * pw[r - l] % mod + mod) % mod;
    }
};

int main() {
    string s;
    while (true) {
        cin >> s;
        if (s == ".") break;
        Hash h(s, 31, 1e9 + 7);
        for (int r = 1; r <= s.size(); r ++) {
            if (s.size() % r != 0) continue;
            string t = s.substr(0, r);
            Hash h2(t, 31, 1e9 + 7);
            bool ok = true;
            for (int i = 0; i < s.size(); i += r) {
                if (h.get(i, i + r) != h2.get(0, r)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << s.size() / r << endl;
                break;
            }
        }
    }
    return 0;
}