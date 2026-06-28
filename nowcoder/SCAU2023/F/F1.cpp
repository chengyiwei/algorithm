#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;

struct Point {
    double x, y;
};

double crossProduct(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double distance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

bool pointInsideCircle(Point p, Point center, double radius) {
    return distance(p, center) <= radius;
}

pair<Point, double> minEnclosingCircleHelper(vector<Point>& points, vector<Point> circle, size_t start) {
    if (start == points.size() || circle.size() == 3) {
        if (circle.size() == 0) {
            return { {0, 0}, 0 };
        } else if (circle.size() == 1) {
            return { circle[0], 0 };
        } else if (circle.size() == 2) {
            Point center = { (circle[0].x + circle[1].x) / 2, (circle[0].y + circle[1].y) / 2 };
            double radius = distance(circle[0], center);
            return { center, radius };
        } else {
            double centerX = (circle[0].x + circle[1].x + circle[2].x) / 3;
            double centerY = (circle[0].y + circle[1].y + circle[2].y) / 3;
            Point center = { centerX, centerY };
            double radius = max({ distance(circle[0], center), distance(circle[1], center), distance(circle[2], center) });
            return { center, radius };
        }
    }

    Point p = points[start];

    auto result = minEnclosingCircleHelper(points, circle, start + 1);
    if (pointInsideCircle(p, result.first, result.second)) {
        return result;
    }

    circle.push_back(p);
    return minEnclosingCircleHelper(points, circle, start + 1);
}

pair<Point, double> minEnclosingCircle(vector<Point>& points) {
    // random_shuffle(points.begin(), points.end());  // 随机打乱点的顺序
    return minEnclosingCircleHelper(points, {}, 0);
}

double convexHullArea(vector<Point>& points) {
    size_t n = points.size();
    if (n < 3) {
        return 0.0;  // 不能构成凸包
    }

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    });

    vector<Point> upperHull, lowerHull;

    for (size_t i = 0; i < n; ++i) {
        while (upperHull.size() >= 2 && crossProduct(upperHull[upperHull.size() - 2], upperHull.back(), points[i]) <= 0) {
            upperHull.pop_back();
        }
        upperHull.push_back(points[i]);
    }

    for (size_t i = n; i-- > 0;) {
        while (lowerHull.size() >= 2 && crossProduct(lowerHull[lowerHull.size() - 2], lowerHull.back(), points[i]) <= 0) {
            lowerHull.pop_back();
        }
        lowerHull.push_back(points[i]);
    }

    // 合并上下凸壳
    upperHull.pop_back();
    lowerHull.pop_back();
    upperHull.insert(upperHull.end(), lowerHull.begin(), lowerHull.end());

    // 计算凸包面积
    double area = 0.0;
    for (size_t i = 1; i < upperHull.size() - 1; ++i) {
        area += crossProduct(upperHull[0], upperHull[i], upperHull[i + 1]);
    }

    return 0.5 * abs(area);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    auto result = minEnclosingCircle(points);
    printf("%.4lf %.4lf\n", result.first.x, result.first.y);

    double area = convexHullArea(points);
    printf("%.4lf\n",  area /(PI * result.second * result.second));
    printf("Humanity will prevail, and the civilization of Earth will endure!\n");
    return 0;
}
