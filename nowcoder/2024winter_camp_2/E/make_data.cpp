#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return rand() << 15 | rand();
}

int main() {
    freopen("E.in","w",stdout);
    srand(GetTickCount());
    int n = 200000;
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", brand() % 2 + 1);
    }
    putchar('\n');
}