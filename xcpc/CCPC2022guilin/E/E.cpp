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
Vector operator - (Vector A, Vector B) {return Vector(A.x - B.x, A.y - B.y);}

i128 cross(Vector A, Vector B) {return A.x * B.y - A.y * B.x;}
i128 area2(Point A, Point B, Point C) {return cross(B - A, C - A);}

void print(i128 x) {
    if (x < 0) putchar('-'); x = -x;
    stack<int> st;
    do {
        st.push(x % 10);
        x /= 10;
    }while (x);
    while (!st.empty()) putchar(st.top() + '0'), st.pop();
}

void solve() {
    i64 x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    Point A(x1, y1), B(x2, y2);
    
    i128 min_area2 = -1;
    Point C;

    auto calc = [&] (Point P) -> void {
        if (P == A || P == B) return ;
        i128 now_area = area2(A, B, P);
        if (now_area == 0) return ;
        if (now_area < 0) now_area = -now_area;
        if (min_area2 == -1 || now_area < min_area2) {
            min_area2 = now_area;
            C = P;
        }
    };
    
    Point P(Point((A.x + B.x) / 2, (A.y + B.y) / 2));

    for (int x = P.x - 10; x <= P.x + 10; x++)
        for (int y = P.y - 10; y <= P.y + 10; y++) {
            calc(Point(x, y));
        }

    // for (int k = 0; k < 4; k++) {
    //     calc(Point(A.x + flg[k][0], A.y + flg[k][1]));
    //     calc(Point(B.x + flg[k][0], B.y + flg[k][1]));
    // }

    i64 Cx = C.x, Cy = C.y;
    cout << Cx << " " << Cy << '\n';
    // i64 ar = min_area2;
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