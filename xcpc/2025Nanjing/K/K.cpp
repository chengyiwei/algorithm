#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Tex, x, y, xx, yy;
ll dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
ll dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};
ll px[4] = {0, 1, 0, -1};
ll py[4] = {1, 0, -1, 0};
void AC() {
    cin >> x >> y >> xx >> yy;
    ll win = 0;
    for (int i = 0; i < 8; i ++) {
        ll dqx = x + dx[i];
        ll dqy = y + dy[i];
        ll pxx = x + px[i / 2];
        ll pyy = y + py[i / 2];
        if (xx == pxx && yy == pyy) continue;
        if (dqx < 1 || dqx > 9 || dqy < 1 || dqy > 10) continue;
        if (dqx == xx && dqy == yy) win = 1;
        if (dqx != xx && dqy != yy) win = 1;
    }
    if (win) cout << "NO\n";
    else cout << "YES\n";
}
/*
2
1 5 2 5
1 1 2 3
*/
int main() {
    ios::sync_with_stdio (false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> Tex;
    while (Tex --) AC();
    return 0;
}