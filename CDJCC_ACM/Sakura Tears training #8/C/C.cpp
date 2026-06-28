#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> prime;
void init() {
    const int N = 1e4 + 5;
    vector<bool> is_prime(N, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = i * i; j < N; j += i) is_prime[j] = 0;
        }
    }
}

void solve() {
    map<int, int> mp;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int hsh = 1;
        int x; cin >> x;
        for (auto p : prime) {
            int cnt = 0;
            if (p * p > x) break;
            while (x % p == 0) { x /= p; cnt++;}
            if (cnt & 1) hsh *= p;
        }
        if (x > 1) hsh *= x;
        mp[hsh] += 1;
    }

    int ans1 = 0;
    for (auto [_, cnt] : mp) ans1 = max(ans1, cnt);
    for (auto [_, cnt] : mp) {
        if (_ == 1) continue;
        if (!(cnt & 1)) mp[1] += cnt, mp[_] = 0;
    }
    int ans2 = ans1;
    for (auto [_, cnt] : mp) ans2 = max(ans2, cnt);
    int q; cin >> q;
    while (q--) {
        ll x; cin >> x;
        if (x == 0) cout << ans1 << "\n";
        else cout << ans2 << "\n";
    }
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    int T; cin >> T;
    while (T--) solve();
    return 0;
}