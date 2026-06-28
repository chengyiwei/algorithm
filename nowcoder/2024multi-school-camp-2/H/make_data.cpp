#include <bits/stdc++.h>
#include <windows.h>

using namespace std;
int brand() {
    return (rand() << 15) | rand();
}
int main() {
    freopen ("H.in", "w", stdout);
    srand(GetTickCount());
    int n = 100;
    int x = brand() % 1, y = brand() % 3;
    printf ("%d %d %d\n", n, x, y);
    for (int i = 1; i <= n; i++) {
        int t = brand() % 2;
        if (t == 0) printf ("W");
        if (t == 1) printf ("D");
        if (t == 2) printf ("S");
        if (t == 3) printf ("A");
    }
    return 0;
}