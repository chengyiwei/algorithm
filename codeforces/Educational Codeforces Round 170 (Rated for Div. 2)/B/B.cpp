#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll TT = 1e9 + 7;
const int MAXN = 1e5 + 1;

ll F[MAXN];

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    F[0] = 1;
    for (int i = 1; i < MAXN; i++)
        F[i] = F[i - 1] * 2 % TT;

    int n; cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        cout << F[b[i]] << '\n';
    }

    return 0;
}