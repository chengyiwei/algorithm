#include <bits/stdc++.h>
using namespace std;

struct Hash {
    vector<int> h, p;
    const int mod = 1e9 + 7;
    const int base = 31;
    Hash(string s) {
        h.resize(s.size() + 1);
        p.resize(s.size() + 1);
        p[0] = 1;
        for (int i = 0; i < s.size(); i++) {
            p[i + 1] = (1LL * p[i] * base) % mod;
            h[i + 1] = (1LL * h[i] * base + s[i]) % mod;
        }
    }
    int get(int l, int r) {
        return (h[r + 1] - 1LL * h[l] * p[r - l + 1] % mod + mod) % mod;
    }

};

int main() {
    // freopen ("A.in" , "r" , stdin);
    ios::sync_with_stdio(0);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    Hash h(s);
    while (q--) {
        int l, r; cin >> l >> r; 
        if ((r - l + 1) % 2 == 1) {
            cout << "NO\n";
        }
        else {
            int m = (l + r) / 2;
            if (h.get(l - 1, m - 1) == h.get(m , r - 1)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}