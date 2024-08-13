#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    vector<int> Le(n + 1), Ri(n + 1);
    for (int i = 1; i <= n; i++) Le[i] = Ri[i] = i;
    for (int i = 1; i <= n; i++) {
        while (Le[i] > 1 && h[Le[i] - 1] >= h[i]) Le[i] = Le[Le[i] - 1];
    }
    for (int i = n; i >= 1; i--) {
        while (Ri[i] < n && h[Ri[i] + 1] >= h[i]) Ri[i] = Ri[Ri[i] + 1];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, 1ll * h[i] * (Ri[i] - Le[i] + 1));
    }
    cout << ans << endl;
    return 0;
}