#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MOD = 1e9 + 7;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {};
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }

int cross(Vector A, Vector B) {return A.x * B.y - A.y * B.x;}

int area2(Point A, Point B, Point C) {return cross(B - A, C - A);}

int convex_polygon_area2(vector<Point> &p) {
    int n = p.size();
    int area = 0;
    for (int i = 1; i < n - 1; i++) area = ((area + area2(p[0], p[i], p[i + 1])) % MOD + MOD) % MOD;
    return area;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        p[i].x = x, p[i].y = y;
    }

    sort(p.begin(), p.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    vector<int> ch(n * 2); int m = 0;
    for (int i = 0; i < n; i++) {
        while (m > 1 && cross(p[ch[m - 1]] - p[ch[m - 2]], p[i] - p[ch[m - 2]]) <= 0) m--;
        ch[m++] = i;
    }
    for (int i = n - 2, t = m; i >= 0; i--) {
        while (m > t && cross(p[ch[m - 1]] - p[ch[m - 2]], p[i] - p[ch[m - 2]]) <= 0) m--;
        ch[m++] = i;
    }
    if (n > 1) m--;
    // 这里的 p 为重新排序过了，如果返回 ch 数组想得到按顺序的值需要把原序列重新排序或者把 p 改成引用
    vector<int> res(m);
    vector<int> vis(n, 0);
    for (int i = 0; i < m; i++) res[i] = ch[i], vis[ch[i]] = 1;

    int all_area2 = 0;
    for (int i = 1; i + 1 < m; i++) all_area2 = (all_area2 + area2(p[ch[0]], p[ch[i]], p[ch[i + 1]])) % MOD;

    for (int i = 0; i < m; i++)
        cout << ch[i] << ' ';
    cout << '\n';

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        for (int j = 0; j < m; j++) {
            int nxt_j = (j + 1) % m;
            int tmp = area2(p[i], p[ch[j]], p[ch[nxt_j]]);
            ans = ((ans + all_area2 - tmp) % MOD + MOD) % MOD;
        }
    }
    
    cout << ans << "\n";
    return 0;
}