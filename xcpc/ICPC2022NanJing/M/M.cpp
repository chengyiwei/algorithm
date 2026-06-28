#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;

int ans = 0;

struct Point {
    ll x, y;
};
typedef Point Vector;
Vector operator - (Point A, Point B) {return {A.x - B.x, A.y - B.y};}
ll cross(Vector A, Vector B) {return A.x * B.y - A.y * B.x;}

signed main() {
    // freopen ("M.in", "r", stdin);
    // freopen ("M.out", "w", stdout);
    int n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    for (int i = 0; i < n; i++) {
        int nxt = (i + 1) % n;
        while (p[nxt].y == p[i].y) nxt = (nxt + 1) % n;
        int pre = (i - 1 + n) % n;
        Vector v1 = p[i] - p[pre], v2 = p[nxt] - p[i];
        if (v1.y < 0 && v2.y > 0) {
            if (p[i].y == p[(i + 1) % n].y) {
                if (p[i].x < p[(i + 1) % n].x) ans += 1;
            }
            else {
                if (cross(v1, v2) > 0) ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}