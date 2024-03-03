#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return rand() << 15 | rand();
}

int main() {
    freopen("A.in","w",stdout);
    srand(GetTickCount());
    int n = 1000, m = 500;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = brand() % 10;
            if (x == 0) putchar('#');
            else if (x == 1) putchar('.');
            else putchar('.');
        }
        putchar('\n');
    }
}