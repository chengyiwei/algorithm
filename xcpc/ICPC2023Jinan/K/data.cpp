#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("K.in", "w", stdout);
    int T = 1;
    printf ("%d\n",T);
    while (T--) {
        int n = 5e5, k = 10;
        printf ("%d %d\n", n, k);
        for (int i = 1; i <= n; i++) {
            int x = rand() % int(1e9) + 1;
            printf ("%d ", x);
        }
    }
}