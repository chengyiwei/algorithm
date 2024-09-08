#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> split(string s) {
    vector<int> res;
    for (int i = 0; i < s.size();) {
        int j = i;
        while (j < s.size() && s[j] != ',') j++;
        string now = s.substr(i, j - i);
        int flg = 1, x = 0;
        if (now[0] == '-') flg = -1, now = now.substr(1);
        for (auto c : now)
            x = x * 10 + c - '0';
        res.push_back(flg * x);
        i = j + 1;
    }
    return res;
}

const double eps = 1e-10;

struct Point {
    int x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Point A, Point B) { return Vector(A.x - B.x, A.y - B.y); }
int cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }

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

signed main() {
    freopen("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    string s; cin >> s;
    auto a = split(s);
    if (a.size() % 2 == 1) {cout << "ERROR" << '\n';return 0;}
    int n = a.size() / 2;
    vector<Point> P(n);
    for (int i = 0; i < n; i++) {
        P[i].x = a[i * 2]; P[i].y = a[i * 2 + 1];
    }
    auto ch_P = convexhull(P);
    if (ch_P.size() != n || ch_P.size() <= 2) {cout << "ERROR" << '\n'; return 0;}
    reverse(ch_P.begin(), ch_P.end());
    int fst_mn = INF, fst_id = 0;
    for (int i = 0; i < ch_P.size(); i++) {
        if (fst_mn > ch_P[i].x * ch_P[i].x + ch_P[i].y * ch_P[i].y) {
            fst_mn = ch_P[i].x * ch_P[i].x + ch_P[i].y * ch_P[i].y;
            fst_id = i;
        }
    }
    string ans;
    for (int i = fst_id; ;) {
        ans += (to_string(ch_P[i].x));
        ans.push_back(',');
        ans += (to_string(ch_P[i].y));
        i = (i + 1) % ch_P.size();
        if (i == fst_id) break;
        ans.push_back(',');
    }
    cout << ans;
    return 0;
}