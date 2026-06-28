#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e4 + 5;
int n;
LL a[maxn];
bool zero;

void Gauss() {
    int i, k = 1;
    LL j = 1ll << 62;
    for (; j; j >>= 1) {
        for (i = k; i <= n; i ++)
            if (a[i] & j) break;
        if (i > n) continue;
        swap(a[i], a[k]);
        for (i = 1; i <= n; i++)
            if (i != k && a[i] & j) a[i] ^= a[k];
        k += 1;
    }
    k -= 1;
    zero = k < n;
    n = k;
}

LL query(LL k) {
    LL ans = 0;
    if (zero) k -= 1;
    if(k == 0) return 0;
    for (int i = n; i; i --) {
        if (k & 1) ans ^= a[i];
        k >>= 1;
    }
    if (k) return -1;
    return ans;
}

int main() {
    freopen ("3949.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cnt = 0;
    int T; cin >> T;
    while (T--) {
        cout << "Case #" << ++cnt << ":\n";
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        Gauss();
        int q; cin >> q;
        while(q --) {
            LL k; cin >> k;
            cout << query(k) << '\n';
        }
    }
}