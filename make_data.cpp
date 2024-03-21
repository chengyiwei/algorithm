#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return (rand()<<15) + rand();
}
int main() {
    freopen ("x.in", "w", stdout);
    srand(GetTickCount());
    int n = 1000000;
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", brand() % 10);
    }
}