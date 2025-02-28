#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum != 1ll * n * (n + 1) / 2) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> b(n);
    iota(b.begin(), b.end(), 1);
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(a[i] - b[i]);
    }
    cout << ans / 2 << '\n';
    return 0;
}