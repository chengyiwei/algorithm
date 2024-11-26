#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-10;

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point& operator  = (const Point &it){
        x = it.x;
        y = it.y;
        return *this;
    }
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

struct Line {
    Point P;
    Vector v;
    Line() {}
    Line(const Point &P, const Vector &v) : P(P), v(v) {}
    Line(const Point &A, const Point &B) { P = A; v = A - B; }
    Line& operator = (const Line &it){
        P = it.P;
        v = it.v;
        return *this; 
    }
};


bool diff_line(const Line &L1, const Line &L2) { // 判断两条直线是否相同
    if (dcmp(L1.P.x, L2.P.x) != 0 || dcmp(L1.P.y, L2.P.y) != 0) return 0;
    if (dcmp(L1.v.x * L2.v.y, L1.v.y * L2.v.x) != 0) return 0;
}

bool calc(vector<Point> p) {
    int n = 5;
    vector<pair<Line, set<int>>> all;
    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 5; j++) {
            set<int> st; st.insert(i); st.insert(j);
            Line L(p[i], p[j]);
            all.emplace_back(Line(p[i], p[j]), st);
        }

    for(int i = 0; i < all.size(); i ++){
        Line L = all[i].first; auto st = all[i].second;
        
    }
    
}

void solve() {
    int n; cin >> n;
    
    for (int i = 1; i <= n; i++) {

    }
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}