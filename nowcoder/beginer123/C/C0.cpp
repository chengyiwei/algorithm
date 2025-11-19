#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex = 1, n, m, a[MAXN], b[MAXN];
bool check(ll x) {
    ll cnt = 0;
    for (int i = 1; i <= n; i ++) {
        b[i] = a[i];
    }
    for (int i = 2; i <= n; i ++) {
        if (b[i] <= b[i - 1]) {
            cnt += (b[i - 1] - b[i]) / x + 1;
        }
    }
    return cnt <= m;
}
void AC() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int flg = 0;
    for (int i = 1; i + 1 <= n; i++) {
        if (a[i + 1] <= a[i]) flg = 1;
    }
    if (flg == 0) {cout << 0 << '\n'; return ;}
    ll L = 0, R = *max_element(a + 1, a + n + 1) + 1;
    while (L + 1 < R) {
        ll mid = (L + R) >> 1;
        if (check(mid)) R = mid;
        else L = mid;
    }
    if (!check(R)) cout << -1 << "\n";
    else cout << R << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> Tex;
    while (Tex --) AC();
    return 0;
}