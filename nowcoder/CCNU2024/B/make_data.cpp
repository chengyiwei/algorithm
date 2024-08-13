#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return (rand() << 15) | rand();
}
int main() {
    freopen ("B.in" ,"w", stdout);
    srand(GetTickCount());
    int n = 100, x = brand() % 10000, y = brand() % 10000, z = brand() % 10000;
    printf("%d %d %d %d\n", n, x, y, z);
    for (int i = 1; i <= n; i++) {
        printf("%d ", brand() % 100000);
    }
    return 0;
}