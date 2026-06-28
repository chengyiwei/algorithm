#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int brand() {
    return (rand() << 16) + (rand() << 1) + (rand() & 1);
}

int main() {
    freopen ("G.in", "w", stdout);
    srand(GetTickCount());
    int n = 5, q = 5;
    printf ("%d %d\n", n, q);
    for (int i = 1; i <= n; i++) {
        int x = brand() % 10 + 1;
        printf ("%d%c", x, " \n"[i == n]);
    }
    while (q--) {
        int a, b; a = brand() % 10 + 1; b = brand() % 10 + 1;
        printf ("%d %d\n", a, b);
    }
    return 0;
}