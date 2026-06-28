#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int MAXN = 1e7 + 5;
constexpr int p[2] = {121, 53};
constexpr int MOD[2] = {2146644970, 1000000009};

vector<int> p_pow[2];

void solve() {
    int n; cin >> n;
    map<int, bool> cnt;

    auto hsh = [&](const string &s, vector<int>& h, int p, int MOD) {
        int m = s.size();
        h.resize(m + 1);
        h[0] = (s[0] - 'a' + 1) % MOD;
        for (int i = 1; i < m; i++) {
            h[i] = (1LL * h[i - 1] * p + (s[i] - 'a' + 1)) % MOD;
        }
    };

    auto get_hash = [&](vector<int>& h, int l, int r, vector<int>& p_pow, int MOD) -> int{
        if (l == 0) return h[r];
        return (h[r] - 1LL * h[l - 1] * p_pow[r - l + 1] % MOD + MOD) % MOD;
    };

    string s; cin >> s;
    string t;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'o' || c == 'v') {
            t.push_back(c);
            l[i] = t.size() - 1;
            r[i] = t.size() - 1;
        }
        else {
            t.push_back('v');
            l[i] = t.size() - 1;
            t.push_back('v');
            r[i] = t.size() - 1;
        }
    }

    vector<int> H[2], invH[2];

    for (int k = 0; k < 2; k++) hsh(t, H[k], p[k], MOD[k]);
    reverse(t.begin(), t.end());
    for (int k = 0; k < 2; k++) hsh(t, invH[k], p[k], MOD[k]);
    reverse(t.begin(), t.end());

    auto check = [&] (int L, int R) {
        L = l[L], R = r[R];
        for (int k = 0; k < 2; k++) {
            int A = get_hash(H[k], L, R, p_pow[k], MOD[k]);
            int B = get_hash(invH[k], t.size() - 1 - R, t.size() - 1 - L, p_pow[k], MOD[k]);
            if (A != B) return false;
        }
        return true;
    };

    auto check2 = [&] (int mid) {
        if (mid < 0 || mid > n) return cnt[mid] = false;
        if (cnt.find(mid) != cnt.end()) return cnt[mid];
        for (int i = 0; i + mid - 1 < n; i++) {
            if (check(i, i + mid - 1)) return cnt[mid] = true;
        }
        return cnt[mid] = false;
    };
    int L = 1, R = n + 1;
    while (L + 1 < R) {
        int mid = (L + R) >> 1;
        if (check2(mid - 4) || check2(mid - 3) || check2(mid - 2) || check2(mid - 1) || check2(mid) || check2(mid + 1) || check2(mid + 2) || check2(mid + 3) || check2(mid + 4)) L = mid;
        else R = mid;
    }

    auto print = [&] (int len) {
        if (len < 0 || len > n) return false;
        for (int i = 0; i + len - 1 < n; i++) {
            if (check(i, i + len - 1)) {
                for (int _ = i; _ < i + len; _++)
                    cout << s[_];
                cout << '\n';
                return true;
            }
        }
        return false;
    };
    if (print(L + 4)) return ;
    if (print(L + 3)) return ;
    if (print(L + 2)) return ;
    if (print(L + 1)) return ;
    if (print(L)) return ;
    if (print(L - 1)) return ;
    if (print(L - 2)) return ;
    if (print(L - 3)) return ;
    if (print(L - 4)) return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

 
    for (int k = 0; k < 2; k++) {
        p_pow[k].resize(MAXN + 1);
        p_pow[k][0] = 1;
        for (int i = 1; i < MAXN; i++) 
            p_pow[k][i] = 1LL * p_pow[k][i - 1] * p[k] % MOD[k];
    }
    
    int t; cin >> t;
    while (t--) solve();
    return 0;
}