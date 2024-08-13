#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll s1 = 0, s2 = 1;
    int n; cin >> n;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        s1 += a[2 * i - 1] * a[2 * i];
    }
    s2 = a[1] * a[2 * n];
    for (int i = 2; i <= n; i++) {
        s2 *= (a[2 * i - 2] + a[2 * i - 1]);
    }
    cout << s1 << ' ' << s2 << endl;
    return 0;
}