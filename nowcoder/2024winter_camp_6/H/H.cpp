#include <bits/stdc++.h>
using namespace std;
typedef __int128 LL;

inline LL read() {
    LL x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

void print (LL x) {
    if (x < 0) { putchar ('-'); x = -x; }
    if (x > 9) print (x / 10);
    putchar (x % 10 + '0');
}

LL absLL (LL x) {
    return x < 0 ? -x : x;
}

struct Point {
    LL x, y;
};

Point operator - (Point a, Point b) {
    return {a.x - b.x, a.y - b.y};
}

LL dist (Point a, Point b = {0,0}) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

LL dot (Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

LL cross (Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

LL calc (Point a, Point b, LL r) {
    LL da = dist (a), db = dist (b), dab = dist (a, b);
    LL s2 = absLL (cross (a, b));
    if (da < r * r && db < r * r)
        return 0;
    if ( (da > r * r && db < r * r) || (da < r * r && db > r * r)) 
        return 1;
    if (da == r * r && db == r * r)  // 两个点都在圆上
        return 2;
    if (da == r * r || db == r * r) {  // 有一个点在圆上
        if (da < r * r || db < r * r) 
            return 1;
        LL angle1 = dot (a - b, a), angle2 = dot (b - a, b);
        if (angle1 > 0 && angle2 > 0) {
            return 2;
        }
        return 1;
    }
    if (da > r * r && db > r * r) {  // 两个点都在圆外
        LL angle1 = dot (a - b, a), angle2 = dot (b - a, b);
        if (s2 * s2 > dab * r * r)  // 相离
            return 0;
        if (s2 * s2 == dab * r * r) { 
            if (angle1 > 0 && angle2 > 0) 
                return 1;
            else 
                return 0;
        }
        if (s2 * s2 < dab * r * r) { 
            if (angle1 > 0 && angle2 > 0) 
                return 2;
            else 
                return 0;
        }
    }
    return 0;
}

int main() {
    freopen ("H.in", "r", stdin);
    freopen ("H.out", "w", stdout);
    LL xc = read(), yc = read(), r = read();
    LL n = read();
    vector<Point> p(n);
    LL res = 0;
    for (int i = 0; i < n; i += 1) {
        LL x = read(), y = read(); x -= xc; y -= yc;
        p[i] = {x, y};
        if (dist (p[i]) == r * r)
            res -= (n - 1) * (n - 2) / 2;
    }
    for (int i = 0; i < n; i += 1) {
        for (int j = i + 1; j < n; j += 1) {
            LL now = calc (p[i], p[j], r);
            
            print(now); putchar('\n');
            res += now * (n - 2);
        }
    }
    LL pr = n * (n - 1) * (n - 2) / 6;
    double ans = (double) res / pr;
    printf ("%.10lf\n", ans);
}