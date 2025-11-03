#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex, n, d[MAXN], b[MAXN], L[MAXN], R[MAXN];
void AC() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> d[i];
    }
    ll m = 1e6, sumL = 0, sumR = 0;
    for (int i = 1; i <= n; i ++) {
        L[i] = max(0ll, m * (d[i] - 1) + m / 2);
        R[i] = m * d[i] + m / 2 - 1;
        sumL += L[i];
        sumR += R[i];
    }
    if (sumL <= 1e8 && 1e8 <= sumR) {
        cout << "Yes\n";
        if (1e8 <= sumR) {
            ll ned = sumR - 1e8;
            for (int i = 1; i <= n; i ++) {
                ll mx = min(ned, R[i] - L[i]);
                ned -= mx;
                b[i] = R[i] - mx;
            }
        }
        else {
            ll ned = 1e8 - sumL;
            for (int i = 1; i <= n; i ++) {
                ll mx = min(ned, R[i] - L[i]);
                ned -= mx;
                b[i] = L[i] + mx;
            }
        }
        for (int i = 1; i <= n; i ++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    else cout << "No\n";

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> Tex;
    while (Tex --) AC();
    return 0;
}