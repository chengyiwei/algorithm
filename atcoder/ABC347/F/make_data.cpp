#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return (rand() << 15) + rand();
}
int main() {
    freopen ("F.in","w",stdout);
    srand(GetTickCount());
    int n = 1000, m = 100;
    printf("%d %d\n", n, m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            printf("%d ", brand() % 1000000000);
        puts("");
    }
}