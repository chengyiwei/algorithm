#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int brand() {
    return (rand() << 16) + (rand() << 1) + (rand() & 1);
}

int main() {
    freopen ("C.in","w", stdout);
    srand(GetTickCount());
    int T = 1;
    printf ("%d\n", T);
    while (T--) {
        int n = brand() % 10 + 1, q = brand() % 20 + 1;
        printf ("%d %d\n", n, q);
        for (int i = 2; i <= n; i++) 
            printf("%d ", i / 2);
        puts("");
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        random_shuffle(a.begin(), a.end());
        for (int i = 0; i < n; i++) cout << a[i] << ' '; puts("");
        while (q--) {
            int x = brand() % n + 1, y = brand() % n + 1;
            cout << x << " " << y << '\n';
        }
    }
    return 0;
}