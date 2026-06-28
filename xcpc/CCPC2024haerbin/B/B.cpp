#include <bits/stdc++.h>

using i128 = __int128_t;
constexpr i128 INF = 2e18;

struct Point {
    i128 x, y;
    Point(){x = 0, y = 0;}
    Point(i128 x, i128 y) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator - (Point A, Point B) {return Vector(A.x - B.x, A.y - B.y);}

i128 cross(Vector A, Vector B) {return A.x * B.y - A.y * B.x;}
i128 area2(Point A, Point B, Point C) {return cross(B - A, C - A);}
i128 abs(i128 x) {return (x > 0 ? x : -x);}

std::vector<int> convexhull(std::vector<Point> &p) {
    int n = p.size();
    sort(p.begin(), p.end(), [] (Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    std::vector<int> ch(n * 2); int m = 0;
    for (int i = 0; i < n; i++) {
        while (m > 1 && cross(p[ch[m - 1]] - p[ch[m - 2]], p[i] - p[ch[m - 2]]) <= 0) m--;
        ch[m++] = i;
    }
    for (int i = n - 2, t = m; i >= 0; i--) {
        while (m > t && cross(p[ch[m - 1]] - p[ch[m - 2]], p[i] - p[ch[m - 2]]) <= 0) m--;
        ch[m++] = i;
    }
    if (n > 1) m--;
    ch.resize(m);
    return ch;
}

i128 convex_polygon_area2(std::vector<Point> &p) {
    int n = p.size();
    i128 area = 0;
    for (int i = 1; i < n - 1; i++) area += area2(p[0], p[i], p[i + 1]);
    return area;
}

void print(i128 x) {
    if (x  < 10) {
        putchar(x + '0');
        return ;
    }
    print(x / 10);
    putchar((x % 10) + '0');
}

void solve() {
    int n; std::cin >> n;
    std::vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        int x, y; std::cin >> x >> y;
        p[i] = Point(x, y);
    }    

    std::vector<int> vis(n, 0);
    auto ch1 = convexhull(p);
    std::vector<Point> p2, res1;
    for (int i = 0; i < ch1.size(); i++) vis[ch1[i]] = 1, res1.push_back(p[ch1[i]]);
    for (int i = 0; i < n; i++)
        if (vis[i] == 0) p2.push_back(p[i]);

    i128 ans = convex_polygon_area2(res1);

    if (p2.size() < 3) {
        if (p2.size() == 0) {
            std::cout << "-1\n"; 
        }
        if (p2.size() == 1) {
            i128 min_area = INF;
            for (int i = 0; i < res1.size(); i++) {
                min_area = std::min(min_area, area2(res1[i], res1[(i + 1) % res1.size()], p2[0]));
            }
            print(ans - min_area);
            putchar('\n');
        }
        if (p2.size() == 2) {
            i128 min_area = INF;
            for (int i = 0; i < res1.size(); i++) {
                min_area = std::min(min_area, area2(res1[i], res1[(i + 1) % res1.size()], p2[0]));
                min_area = std::min(min_area, area2(res1[i], res1[(i + 1) % res1.size()], p2[1]));
            }
            print(ans - min_area);
            putchar('\n');
        }
        return ;
    }
    std::vector<int> ch2 = convexhull(p2);
    std::vector<Point> res2;
    for (int i = 0; i < ch2.size(); i++)
        res2.push_back(p2[ch2[i]]);
    i128 min_area = INF;

    int st = -1; i128 min_ = INF;
    for (int i = 0; i < res2.size(); i++) {
        i128 now_area = area2(res1[0], res1[1], res2[i]);
        if (st == -1 || min_ > now_area)
            st = i, min_ = now_area;
    }

    for (int i = 0, j = st; i < res1.size(); i++) {
        int nxt1 = (i + 1) % res1.size(), nxt2 = (j + 1) % res2.size();
        while (area2(res1[i], res1[nxt1], res2[j]) > area2(res1[i], res1[nxt1], res2[nxt2]))
            j = nxt2, nxt2 = (j + 1) % res2.size();
        
        min_area = std::min(min_area, area2(res1[i], res1[nxt1], res2[j]));
    }

    print(ans - min_area);
    putchar('\n');
}

int main() {
    freopen ("B.in", "r", stdin);
    
    int T; std::cin >> T;
    while (T--) solve();
    return 0;
}