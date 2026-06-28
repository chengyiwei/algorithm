#include <bits/stdc++.h>
using namespace std;
int brand() {
    return (rand() << 15) + rand();
}
int main() {
    freopen ("D.in", "w", stdout);
    srand(time(0));
    cout << 1 << '\n';
    int n = brand() % 20 + 1;
    printf ("%d\n", n);
    for (int i = 1; i <= n; i++) {
        printf ("%d ", brand() + 1);
    }
    printf ("\n");
    for (int i = 1; i < n; i++) {
        printf ("%d %d\n", i + 1, brand() % i + 1);
    }
    return 0;
}