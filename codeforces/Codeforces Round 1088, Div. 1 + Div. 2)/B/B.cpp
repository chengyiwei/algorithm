#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int cnt_pre[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cnt_pre[0] = 1;
    for (int i = 1; i < MAXN; i++)
        for (int j = i; j < MAXN; j += i) cnt_pre[j]++;

    int t; cin >> t;
    while (t--) {
        int x, y; cin >> x >> y;
        int abs_ = abs(x - y);
        cout << cnt_pre[abs_] << "\n";
        for (int i = 1; i <= x; i++) cout << 1 << ' ';
        for (int i = 1; i <= y; i++) cout << -1 << ' ';
        cout << "\n";
    }
    return 0;
}