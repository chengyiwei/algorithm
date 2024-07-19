#include <bits/stdc++.h>
using namespace std;
struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
};
typedef Point Vector;

int main() {
    Point A[3];
    for (int i = 0; i < 3; i++) cin >> A[i].x >> A[i].y;
    for (int i = 0; i < 3; i++) {
        int j = (i + 1) % 3, k = (i + 2) % 3;
        Vector v1 = Vector(A[j].x - A[i].x, A[j].y - A[i].y), v2 = Vector(A[k].x - A[j].x, A[k].y - A[j].y);
        if (v1.x * v2.x + v1.y * v2.y == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}