#include <bits/stdc++.h>
using namespace std;
int brand() {
    return (rand() << 15) | rand();
}
int main() {
    freopen ("G.in", "w", stdout);
    srand(time(0));
    int t = 1000;
    printf("%d\n", t);
    while (t--) {
        int n = 20, m = 1;
        printf("%d %d\n", n, m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i != 19)
                    printf("%d ", 720720);
                else 
                    printf("%d ", 1);
            }
            printf("\n");
        }
    }
    return 0;
}