#include <bits/stdc++.h>
using namespace std;

struct Rectangle{
    int x1, y1, x2, y2;
    Rectangle(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {};
};

int check (Rectangle &A, Rectangle &B) {
    if (A.x1 >= B.x2 || A.x2 <= B.x1 || A.y1 >= B.y2 || A.y2 <= B.y1) return 0;
    return 1;
}

void solve() {
    vector<int> X, Y;
    X.push_back(0); Y.push_back(0);
    int H, W, n; cin >> n >> W >> H;
    vector<Rectangle> res;
    for (int i = 1; i <= n; i++) {
        int ans_x = -1, ans_y = -1;
        int h, w; cin >> w >> h;
        for (auto x : X) {
            for (auto y : Y) {
                Rectangle r(x, y, x + w, y + h);
                if (r.x2 > W || r.y2 > H) continue;
                int flg = 1;
                for (auto c : res) 
                    if (check(c, r) || check(r, c)) {
                        flg = 0; break;
                    }
                if (!flg) continue;
                if (ans_x == -1) {ans_x = x; ans_y = y;}
                else if (ans_x > x || (ans_x == x && ans_y > y)) { ans_x = x; ans_y = y; }
            }
        }
        if (ans_x == -1) cout << -1 << endl;
        else {
            cout << ans_x << " " << ans_y << endl;
            res.push_back(Rectangle(ans_x, ans_y, ans_x + w, ans_y + h));
            X.push_back(ans_x + w); Y.push_back(ans_y + h);
        }
    }
}

int main() {
    freopen ("I.in", "r", stdin);
    solve();
    return 0;
}