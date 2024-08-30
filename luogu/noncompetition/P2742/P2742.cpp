#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x * p, A.y * p); }
Vector operator / (Vector A, double p) { return Vector(A.x / p, A.y / p); }

int dcmp(double x, double y = 0.0) { // 比较两个浮点数的大小
    if (fabs(x - y) < eps) return 0;
    return x < y ? -1 : 1;
}

bool operator == (const Point &a, const Point &b) {
    return dcmp(a.x, b.x) == 0 && dcmp(a.y, b.y) == 0;
}

double cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; } 
double dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
double length(Vector A) { return sqrt(dot(A, A)); }

vector<Point> convexhull(vector<Point> p) {
    int n = p.size();
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
    vector<Point> res(m);
    for (int i = 0; i < m; i++) res[i] = p[ch[i]];
    return res;
}

int main() {
    int n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    vector<Point> ch = convexhull(p);
    double ans = 0;
    int m = ch.size();
    for (int i = 0; i < m; i++) ans += length(ch[i] - ch[(i + 1) % m]);
    printf("%.2lf\n", ans);
    return 0;
}