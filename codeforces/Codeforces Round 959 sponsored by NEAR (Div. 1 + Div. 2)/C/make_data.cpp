#include <bits/stdc++.h>
using namespace std;
int brand() {
    return (rand() << 15) + rand();
}

int main() {
    freopen ("C.in", "w", stdout);
    srand(time(0));
    int T = 1;
    printf("%d\n", T);
    int n = brand() % 6 + 1, x = brand() % 5 + 1;
    printf("%d %d\n", n, x);
    for (int i = 0; i < n; i++) {
        printf("%d ", brand() % 7 + 1);
    }
    printf("\n");
}