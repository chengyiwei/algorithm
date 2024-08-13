#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;

const double eps = 1e-8;
int cmp(double x) {
    if (fabs(x) < eps) return 0;
    if (x > 0) return 1;
    return -1;
}

struct point {
    double x, y;
    point() {}
    point(double a, double b) : x(a), y(b) {}
    friend point operator-(const point& a, const point& b) {
        return point(a.x - b.x, a.y - b.y);
    }
    double norm() {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    double operator*(const point& p) const {
        return x * p.y - y * p.x;  // 叉积
    }
} p[maxn];
double dist(const point& a, const point& b) {
    return (a - b).norm();
}

void circle_center(point p0, point p1, point& cp) {
    cp.x = (p0.x + p1.x) / 2;
    cp.y = (p0.y + p1.y) / 2;
}

void circle_center(point p0, point p1, point p2, point& cp) {
    double a1 = p1.x - p0.x, b1 = p1.y - p0.y, c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = p2.x - p0.x, b2 = p2.y - p0.y, c2 = (a2 * a2 + b2 * b2) / 2;
    double d = (a1 * b2 - a2 * b1);
    cp.x = p0.x + (c1 * b2 - c2 * b1) / d;
    cp.y = p0.y + (a1 * c2 - a2 * c1) / d;
}

double radius;
point center;
bool point_in(const point& p) {
    return cmp(dist(p, center) - radius) < 0;
}

void min_circle_cover(point a[], int n) {
    radius = 0;
    center = a[0];
    for (int i = 1; i < n; i++)
        if (!point_in(a[i])) {
            center = a[i], radius = 0;
            for (int j = 0; j < i; j++)
                if (!point_in(a[j])) {
                    circle_center(a[i], a[j], center);
                    radius = dist(a[j], center);
                    for (int k = 0; k < j; k++)
                        if (!point_in(a[k])) {
                            circle_center(a[i], a[j], a[k], center);
                            radius = dist(a[k], center);
                        }
                }
        }
}

// 计算凸包面积
double convexHullArea(point a[], int n) {
    sort(a, a + n, [](const point& p1, const point& p2) {
        return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
    });

    vector<point> upperHull, lowerHull;

    for (int i = 0; i < n; i++) {
        while (upperHull.size() >= 2 &&
               (a[i] - upperHull[upperHull.size() - 2]) * (upperHull[upperHull.size() - 1] - upperHull[upperHull.size() - 2]) <
                   0) {
            upperHull.pop_back();
        }
        upperHull.push_back(a[i]);
    }

    for (int i = n - 1; i >= 0; i--) {
        while (lowerHull.size() >= 2 &&
               (a[i] - lowerHull[lowerHull.size() - 2]) * (lowerHull[lowerHull.size() - 1] - lowerHull[lowerHull.size() - 2]) <
                   0) {
            lowerHull.pop_back();
        }
        lowerHull.push_back(a[i]);
    }

    upperHull.pop_back();
    lowerHull.pop_back();
    upperHull.insert(upperHull.end(), lowerHull.begin(), lowerHull.end());

    double area = 0.0;
    for (int i = 1; i < upperHull.size() - 1; i++) {
        area += (upperHull[i] - upperHull[0]) * (upperHull[i + 1] - upperHull[0]);
    }

    return fabs(area) / 2.0;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        p[i] = point(x, y);
    }
    random_shuffle(p, p + n);

    // 求解最小圆覆盖
    min_circle_cover(p, n);

    // 计算凸包面积
    double area = convexHullArea(p, n);

    printf("%.4lf %.4lf\n", center.x, center.y);
    printf("%.4lf\n",area/(acos(-1)*radius*radius));
    printf("Humanity will prevail, and the civilization of Earth will endure!\n");
    return 0;
}
