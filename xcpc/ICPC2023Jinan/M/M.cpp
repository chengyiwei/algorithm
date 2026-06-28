#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
struct Point {
    double x, y;
    Point() {};
    Point(double x, double y) : x(x), y(y) {};
};
typedef Point Vector;
Vector operator - (Point A, Point B) { return Vector{A.x - B.x, A.y - B.y}; }
bool operator == (Point A, Point B) { return A.x == B.x && A.y == B.y; }
int dcmp(double x, double y) {
    if (fabs(x - y) < eps) return 0;
    return x < y ? -1 : 1;
}
double cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }

double rad (Point A, Point B) { 
    return atan2(A.y - B.y, A.x - B.x);
}

vector<int> convex_hull (vector<Point> &p, vector<int> &vis) {
    sort(p.begin(), p.end(), [](Point a, Point b) {
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    });
    vector<int> ch;
    for (int i = 0; i < p.size(); i++) {
        while (ch.size() >= 2 && dcmp(cross(p[ch[ch.size() - 1]] - p[ch[ch.size() - 2]], p[i] - p[ch[ch.size() - 2]]), 0.0) <= 0)
            ch.pop_back();
        ch.push_back(i);
    }
    for (int i = p.size() - 2, t = ch.size() + 1; i >= 0; i--) {
        while (ch.size() >= t && dcmp(cross(p[ch[ch.size() - 1]] - p[ch[ch.size() - 2]], p[i] - p[ch[ch.size() - 2]]), 0.0) <= 0)
            ch.pop_back();
        ch.push_back(i);
    }
    for (int i = 0; i < ch.size(); i++) vis[ch[i]] = 1;
    return ch;
}

int main() {
    freopen ("M.in", "r", stdin);
    // freopen ("M.out", "w", stdout);
    int n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    vector<int> vis(n, 0);
    auto ch = convex_hull(p, vis);

    // for (int i = 0; i < n; i++)
    //     cout << vis[i] << " ";

    int t = ch.size(), cnt = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        vector<pair<double, int>> angle;
        vector<int> idx(n);
        for (int j = 0; j < n; j++) if (j != i)
            angle.push_back({rad(p[j], p[i]), j});
        sort(angle.begin(), angle.end());
        for (int j = 0; j < n - 1; j++)
            idx[angle[j].second] = j;
        
        for (int j = 0; j < t; j++) {
            int a = ch[j], b = ch[(j + 1) % t];
            if ((idx[a] + 1) % (n - 1) == idx[b] || (idx[b] + 1) % (n - 1) == idx[a]) {
                cnt += 1;
            }
        }
    }
    cout << cnt+ 1 << endl;

    return 0;
}