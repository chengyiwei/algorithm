#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

int cmp (double A, double B) {
    if (fabs(A - B) < eps) return 0;
    if (A < B) return -1;
    else return 1;
}

struct Node {
    double x, y;
    Node() {x = 0; y = 0;}
    bool operator <(const Node B) const {
        return x < B.x || (x == B.x && y < B.y);
    }
};

struct Line {
    double k, b;
    Line() {k = 0; b = 0;}
    Line(Node A, Node B) {
        if (A.x == B.x) {
            k = inf; b = A.x;
        }
        else {
            k = (A.y - B.y) / (A.x - B.x);
            b = A.y - k * A.x;
        }
    }
    bool operator <(const Line B) const {
        return k < B.k || (k == B.k && b < B.b);
    }
};

int main() {
    freopen ("I.in", "r", stdin);
    int n; cin >> n;
    vector<Node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort (a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        if (cmp(a[i].x, a[i - 1].x) == 0 && cmp (a[i].y, a[i - 1].y) == 0) {
            cout << "inf" << endl;
            return 0;
        }
    }
    vector<Line> p;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            p.push_back(Line(a[i], a[j]));
        }
    int cnt = 0;
    sort (p.begin(), p.end());
    for (int i = 1; i < p.size(); i++) {
        if (cmp(p[i].k, p[i - 1].k) == 0 && cmp(p[i].b, p[i - 1].b) == 0)
            cnt ++;
    }
    cout << p.size() - cnt << endl;
    return 0;
}