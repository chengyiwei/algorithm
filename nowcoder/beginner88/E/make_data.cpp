#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return (rand()<<15) + rand();
}
int main() {
    freopen ("E.in", "w", stdout);
    srand(GetTickCount());
    int T = 1; printf("%d\n", T);
    while (T--) {
        int n = brand() % 1000 + 1, m = brand() % 1000 + 1;
        printf("%d %d\n", n, m);
        for (int i = 1; i <= n; i++) {
            int x = brand() % 100 + 1;
            printf("%d%c", x, " \n"[i == n]);
        }
        for (int i = 1; i <= m; i++) {
            int x = brand() % 100 + 1, y = brand() % 100 + 1;
            printf("%d %d\n", x, y);
        }
    }
}