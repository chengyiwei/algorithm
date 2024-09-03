#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    // freopen ("C.in", "r", stdin);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0;
    for (int i = 1; i <= n;) {
        int j = i + 1; 
        if (j > n) break;
        int d = a[j] - a[i];
        while (j <= n && a[j] - a[j - 1] == d) j += 1;
        j -= 1;
        int len = j - i + 1;
        ans += 1LL * len * (len - 1) / 2;
        i = j;
    }
    ans += n;
    cout << ans << '\n';
    return 0;
}