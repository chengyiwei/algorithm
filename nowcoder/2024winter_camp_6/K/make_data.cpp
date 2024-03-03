#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return rand() << 15 | rand();
}
string p = "red";
int xbrand() {
    if (rand() & 1) return brand();
    return -brand();
}
int main() {
    freopen("K.in", "w", stdout);
    srand(GetTickCount());
    int n = brand() % 5 + 1, m = brand() % 5 + 1, q = brand() % 10;
    printf("%d %d %d\n", n, m, q);
    for (int i = 1; i <= n; i += 1){
        for (int j = 1; j <= m; j += 1)
            cout << p[rand() % 3];
        cout << endl;
    }
    for (int i = 1; i <= q; i += 1) {
        int x1 = rand() % n + 1, y1 = rand() % m + 1, x2 = rand() % n + 1, y2 = rand() % m + 1;
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        printf("%d %d %d %d\n", x1, y1, x2, y2);
    }
}
