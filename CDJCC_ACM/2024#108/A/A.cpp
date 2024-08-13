#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen ("A.in", "r", stdin);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    ll ans = 0;

    auto cdq = [&] (auto cdq, int L, int R) {
        if (L == R) return;
        int mid = (L + R) / 2;
        cdq(cdq, L, mid); cdq(cdq, mid + 1, R);
        int l = L, r = mid + 1;
        vector<int> tmp;
        while (l <= mid || r <= R) {
            if (r > R || (l <= mid && a[l] <= a[r])) {
                tmp.push_back(a[l]); l++;
            } else {
                tmp.push_back(a[r]); r++;
                ans += mid - l + 1;
            }
        }
        for (int i = L; i <= R; i++) a[i] = tmp[i - L];
    };

    cdq(cdq, 1, n);
    cout << ans << endl;
    return 0;
}