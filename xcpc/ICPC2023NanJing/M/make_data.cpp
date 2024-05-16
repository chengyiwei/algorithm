#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return (rand() << 15) | rand();
}
int main() {
    freopen ("M.in", "w", stdout);
    srand(GetTickCount());
    int n = 5;
    printf ("%d\n", n);
    for (int i = 0; i < n; i++)
        printf ("%d %d\n", brand() % 5, brand() % 5);
    return 0;
}