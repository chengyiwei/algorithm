#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
typedef i64 ll;
using i128 = __int128;

constexpr int flg[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Point {
    i128 x, y;
    Point(i128 x = 0, i128 y = 0) : x(x), y(y) {}
    bool operator == (Point &ohs) {
        return (x == ohs.x && y == ohs.y);
    }
};

typedef Point Vector;
Vector operator + (Vector A, Vector B) {return Vector(A.x + B.x, A.y + B.y);}
Vector operator - (Vector A, Vector B) {return Vector(A.x - B.x, A.y - B.y);}

i128 cross(Vector A, Vector B) {return A.x * B.y - A.y * B.x;}
i128 area2(Point A, Point B, Point C) {return cross(B - A, C - A);}

i128 exgcd(i128 a, i128 b, i128 &x, i128 &y) {
    if (!b) {x = 1, y = 0; return a;}
    i128 d = exgcd(b, a % b, x, y), x0 = x, y0 = y;
    x = y0, y = x0 - a / b * y0;
    return d;
}

void solve() {
    i64 x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    Point A(x1, y1), B(x2, y2);
    
    Vector V1 = B - A;
    i64 V1x = V1.x, V1y = V1.y;
    // cout << V1x << " " << V1y << '\n';
    Vector V2;
    exgcd(V1.y, -V1.x, V2.x, V2.y);
    i64 V2x = V2.x, V2y = V2.y;
    // cout << V2x << " " << V2y << '\n';
    Point C = V2 + A;

    i64 Cx = C.x, Cy = C.y;
    cout << Cx << " " << Cy << '\n';
    // i64 ar = area2(A, B, C);
    // cout << ar << '\n';
}

int main() {
    // freopen ("E.in", "r", stdin);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}