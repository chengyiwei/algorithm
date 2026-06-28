#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;
const ll inf = 1e9;
ll read() {
    ll x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}
    Point operator + (const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator - (const Point &b) const { return Point(x - b.x, y - b.y); }
};

typedef Point Vector;
ll cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
ll dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }

bool onSegment(Point p, Point a, Point b) {
    return cross(a - p, b - p) == 0 && dot(a - p, b - p) <= 0;
}
bool check(Point a, Point b, Point c, Point d) {
    return cross(b - a, c - a) * cross(b - a, d - a) < 0 && cross(d - c, a - c) * cross(d - c, b - c) < 0;
}

int solve() {
    Point S; S.x = read(); S.y = read();
    ll r, vx, vy; r = read(), vx = read(), vy = read();
    ll lx, ly, rx, ry; lx = read(); ly = read(); rx = read(); ry = read();
    lx -= S.x; ly -= S.y; rx -= S.x; ry -= S.y; S.x = 0; S.y = 0;
    ll vvx = vx, vvy = vy;
    if (vvx < 0) vvx = -vvx; if (vvy < 0) vvy = -vvy;
    ll g = inf / max(vvx, vvy);
    vx *= g, vy *= g;
    if (rx - lx < 2 * r || ry - ly < 2 * r)  return 0;
    vector<Point> p;
    p.push_back(Point(lx + r, ly + r)); p.push_back(Point(rx - r, ly + r));
    p.push_back(Point(rx - r, ry - r)); p.push_back(Point(lx + r, ry - r));
    for (int i = 0; i < 4; i++) {
        Point a = p[i], b = p[(i + 1) % 4];
        if (onSegment({0, 0}, a, b)) return 1;
        if (onSegment(a, {0, 0}, {vx, vy})) return 1;
        if (check (a, b, {0, 0}, {vx, vy})) return 1;
    }
    return 0;
}

int main() {
    freopen ("F.in", "r", stdin);
    int T; cin >> T;
    while (T--) 
        cout << (solve() ? "Yes" : "No") << '\n';
    return 0;
}