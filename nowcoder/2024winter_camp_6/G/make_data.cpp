#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return (rand() << 15) + rand();
}
int main() {
    freopen ("G.in", "w", stdout);
    srand(GetTickCount());
    int T = 100;
    printf("%d\n", T);
    while (T--) {
        int n = brand() % 100 + 1, S = brand() % 1000000000 + 1, k = brand() % n;
        printf("%d %d %d\n", n, S, k);
    }
    return 0;
}