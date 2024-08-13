#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main() {
    freopen ("H.in", "w", stdout);
    srand(GetTickCount());
    int n = 5, m = 6;
    printf ("%d %d\n", n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf ("%c", rand() & 1 ? '.' : '*');
        printf ("\n");
    }
}