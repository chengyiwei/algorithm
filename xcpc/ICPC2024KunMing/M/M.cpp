#include <bits/stdc++.h>
#define double long double
using namespace std;

const double eps = 1e-9;

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator - (Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator + (Point A, Point B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x * p, A.y * p); }

int dcmp(double x, double y) {
    if (fabs(x - y) < eps) return 0;
    return x < y ? -1 : 1;
}

double cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }

double area2(Point A, Point B, Point C) { return cross(B - A, C - A); }

double length(Vector A) { return sqrt(A.x * A.x + A.y * A.y); }

Vector normal (Vector A) { // 左转 90 度， 单位法向量
    double L = length(A);
    return Vector(-A.y / L, A.x / L);
}

struct Line {
    Point P;
    Vector v;
    Line() {}
    Line(Point P, Vector v) : P(P), v(v) {}
    Point point(double t) { return P + v * t; }
};


Point get_line_intersection(Point P, Vector v, Point Q, Vector w) {
    Vector u = P - Q;
    double t = cross(w, u) / cross(v, w);
    return P + v * t;
}

double distance_to_line(Point P, Line l) {
    Vector v1 = l.v, v2 = P - l.P;
    return fabs(cross(v1, v2) / length(v1));
}

double distance_to_line (Point P, Point A, Point B) {
    Vector v1 = B - A, v2 = P - A;
    return fabs(cross(v1, v2) / length(v1));
}

void solve() {
    int n; cin >> n;
    vector<Point> p(n);
    Point C; double  R;
    auto calc = [&] () {
        int nxt = 1;
        double now_area = 0;
        double ans = 0;
        for (int i = 0; i < p.size(); i++) {
            while (true) {
                int nnxt = (nxt + 1) % p.size();
                if (cross(p[nnxt] - p[i], C - p[i]) <= 0) break;
                if (dcmp(distance_to_line(C, p[i], p[nnxt]), R) == -1) break;
                now_area += fabs(area2(p[i], p[nxt], p[nnxt]));
                nxt = nnxt;
            }
            ans = max(ans, now_area);
            now_area -= fabs(area2(p[i], p[(i + 1) % p.size()], p[nxt]));
        }
        return ans;
    };

    cin >> C.x >> C.y >> R;
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    double ans1 = calc();
    for (int i = 0; i < n; i++) swap (p[i].x, p[i].y);
    swap (C.x, C.y);
    reverse(p.begin(), p.end());
    double ans2 = calc();
    auto ans = max(ans1, ans2);
    printf("%.0Lf\n", ans);
}

int main() {
    freopen ("M.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}