#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int flg[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main() {
    freopen ("H.in", "r", stdin);
    freopen ("H0.out", "w", stdout);
    int n, X, Y; cin >> n >> X >> Y;
    vector<int> a(n + 1);
    vector<pii> pos(n + 1);
    map<pii, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        char ch; cin >> ch;
        if (ch == 'w') a[i] = 0;
        if (ch == 'D') a[i] = 1;
        if (ch == 'S') a[i] = 2;
        if (ch == 'A') a[i] = 3;
    }
    ll ans = 0;

    auto check = [&] (int L, int R) {
        int x = 0, y = 0;
        if (X == 0 && Y == 0) return true;
        for (int i = L; i <= R; i++) {
            x += flg[a[i]][0]; y += flg[a[i]][1];
            if (X == x && Y == y) return true;
        }
        return false;
    };

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) 
            if (check(i, j)) ans++;
    }

    cout << ans << endl;
    return 0;
}
