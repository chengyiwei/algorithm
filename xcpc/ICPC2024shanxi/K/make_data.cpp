#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return (rand() << 16) + (rand() << 1) + (rand() & 1);
}
int main() {
    freopen ("K.in", "w", stdout);
    srand(GetTickCount());
    int n = 2, m = 100, k = 3;
    cout << n << " " << m << " " << k << endl;
    for (int i = 1; i <= m; i++) {
        int t = brand() % 10 + 1, x = brand() % n + 1, y = brand() % 10 + 1;
        cout << t << " " << x << " " << y << endl;
    }
    return 0;
}