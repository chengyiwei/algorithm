#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m = *max_element(a.begin() + 1, a.end());
    vector<int> cnt(m + 1, 0);
    for (auto x : a) cnt[x]++;
    int num = 0;
    for (int i = m; i >= 1; i--) {
        int g = 0;
        for (int j = i; j <= m; j += i) {
            if (cnt[j])
                g = __gcd(g, j);
        }
        if (g == i) {
            if (cnt[i] == 0) {
                num += 1;
                cnt[i] = 1;
            }
        }
    }
    cout << num << endl;
    return 0;
}