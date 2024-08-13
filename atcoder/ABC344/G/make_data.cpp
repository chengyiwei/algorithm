#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return (rand()<<15) + rand();
}
int main() {
    freopen ("G.in", "w", stdout);
    srand(GetTickCount());
    int n = 100;
    int Q = 10000;
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", brand() % 10, brand() % 10);
    }
    printf("%d\n", Q);
    printf("%d %d %d\n", brand() % 10, brand() % 10, brand() % 10);
}