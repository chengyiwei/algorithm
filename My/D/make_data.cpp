#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return rand() << 15 | rand();
}

int main() {
    freopen("C.in","w",stdout);
    srand(GetTickCount());
    int T = 1000;
    printf("%d\n", T);
    while (T--) {
        int n = brand() % 10 + 1;
        printf("%d\n", n);
        for (int i = 1; i <= n; i++)
            printf("%d ",brand() % 10000 + 1);
        putchar('\n');
    }
}