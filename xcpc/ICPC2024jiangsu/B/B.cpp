#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
double r = 10;
const double eps = 1e-8;

int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    return x < 0 ? -1 : 1;
}

typedef struct Point {
    double x, y;
    Point(double x = 0, double y = 0): x(x), y(y) {}
}Vector;

struct Line {
    Point p1, p2;
    Line(Point p1 = Point(), Point p2 = Point()): p1(p1), p2(p2) {}
};

Point line_intersection (Line l1, Line l2) {
    double a1 = l1.p2.y - l1.p1.y; double b1 = l1.p1.x - l1.p2.x; double c1 = a1 * l1.p1.x + b1 * l1.p1.y;
    double a2 = l2.p2.y - l2.p1.y; double b2 = l2.p1.x - l2.p2.x; double c2 = a2 * l2.p1.x + b2 * l2.p1.y;
    double det = a1 * b2 - a2 * b1;
    return Point((c1 * b2 - c2 * b1) / det, (a1 * c2 - a2 * c1) / det);
}
Vector operator - (Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
double cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
double area2(Point A, Point B, Point C) { return cross(B - A, C - A); }

array<double, 5> Rad_L, Rad_R;
array<Point, 5> L, R;

array<Point, 5> P;

void calc(int i) {
    int now = i, nxt1 = (i + 1) % 5, nxt2 = (i + 2) % 5, pre1 = (i + 4) % 5, pre2 = (i + 3) % 5;
    Line l1 = Line(L[now], R[pre2]), l2 = Line(R[pre1], L[nxt1]);
    Point p = line_intersection(l1, l2);
    P[now] = p;
}

void solve() {
    cin >> r;
    for (int i = 0; i < 5; i++) {
        cin >> Rad_L[i]; Rad_L[i] = Rad_L[i] / 180 * PI;
        L[i] = Point(r * cos(Rad_L[i]), r * sin(Rad_L[i]));
    }
    for (int i = 0; i < 5; i++) {
        cin >> Rad_R[i]; Rad_R[i] = Rad_R[i] / 180 * PI;
        R[i] = Point(r * cos(Rad_R[i]), r * sin(Rad_R[i]));
    }
    double res = 0;
    for (int i = 0; i < 5; i++) calc(i);
    for (int i = 0; i < 5; i++) {
        
        res += (Rad_R[i] - Rad_L[i]) * r * r / 2;
        int nxt2 = (i + 2) % 5, nxt1 = (i + 1) % 5;
        res += area2(Point(0, 0), R[i], L[nxt2]) / 2;
        res -= area2(Point(0, 0), P[i], P[nxt1]) / 2;
    }
    cout << fixed << setprecision(10) << res << endl;
}

int main() {
    freopen ("B.in", "r", stdin);
    freopen ("B.out", "w", stdout);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}