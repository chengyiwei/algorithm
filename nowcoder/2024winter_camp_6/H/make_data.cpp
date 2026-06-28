#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return rand() << 15 | rand();
}

int xbrand() {
    if (rand() & 1) return brand();
    return -brand();
}
int main() {
    freopen("H.in", "w", stdout);
    srand(GetTickCount());
    int n = 5;
    printf("%d %d %d\n", xbrand() % 5, xbrand() % 5, brand() % 5);
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", xbrand() % 5, xbrand() % 5);
    }

}
