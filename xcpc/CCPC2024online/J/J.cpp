#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 30;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    vector<int> c(N + 1);

    auto insert = [&](int x) -> void{
        for (int i = N; i >= 0; i--) {
            if (x >> i & 1) {
                if (!c[i]) {
                    c[i] = x;
                    return;
                }
                x ^= c[i];
            }
        }
    };

    int A = 0, B = 0;
    for (int i = 1; i <= n; i++) {
        A ^= a[i]; B ^= b[i];
        insert(a[i] ^ b[i]);
    }

    for (int i = 30; i >= 0; i--) {
        int A_ = A ^ c[i], B_ = B ^ c[i];
        if (max(A_, B_) < max(A, B)) {
            A = A_; B = B_;
        }
    }
    cout << max(A, B) << '\n';
}

int main() {
    freopen ("J.in", "r", stdin);
    freopen ("J.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}