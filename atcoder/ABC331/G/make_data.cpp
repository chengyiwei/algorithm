#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return rand() << 15 | rand();
}
int main() {
    freopen("G.in", "w", stdout);
    srand(GetTickCount());
    int n;
    n = 100000;
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", brand() % 1000);
    }
    return 0;
}