#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex = 1, n, m, a[MAXN], b[MAXN];
void AC() {
    cin >> n >> m;
    ll cnt = 0, ans = 0;
    a[0] = -1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (a[i] <= a[i - 1]) {
            cnt ++;
            ans = max(ans, a[i - 1] - a[i] + 1);
        }
    }
    if (cnt > m) cout << "-1\n";
    else cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> Tex;
    while (Tex --) AC();
    return 0;
}