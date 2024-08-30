#include <bits/stdc++.h>
using namespace std;
struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }

int dcmp(double x, double y = 0.0) {
    if (fabs(x - y) < 1e-10) return 0;
    return x < y ? -1 : 1;
}

double cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
double dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
double dist(Point A, Point B) { return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)); }
bool cmp(Point A, Point B) { return A.x < B.x || (A.x == B.x && A.y < B.y); }

vector<Point> convexhull(vector<Point> p) {
    int n = p.size();
    sort(p.begin(), p.end(), cmp);
    vector<int> ch(n * 2); int m = 0;
    for (int i = 0; i < n; i++) {
        while (m > 1 && cross(p[ch[m - 1]] - p[ch[m - 2]], p[i] - p[ch[m - 2]]) <= 0) m--;
        ch[m++] = i;
    }
    for (int i = n - 2, t = m; i >= 0; i--) {
        while (m > t && cross(p[ch[m - 1]] - p[ch[m - 2]], p[i] - p[ch[m - 2]]) <= 0) m--;
        ch[m++] = i;
    }
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
    for (int i = 0, j = 1; i < m; i++) {
        while (dist(ch[i], ch[(j + 1) % m]) > dist(ch[i], ch[j])) j = (j + 1) % m;
        ans = max({ans, dist(ch[i], ch[j]), dist(ch[i], ch[(j + 1) % m])});
    }
    ans = ans * ans;
    printf("%.0lf\n", ans);
    return 0;
}