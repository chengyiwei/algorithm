#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int maxx = 1e2;
int brand() {
    return (rand() << 15) | rand();
}
int main() {
    freopen ("E.in", "w", stdout);
    srand(GetTickCount());
    int n = 5;
    printf("%d\n", n);
    set<int> s;
    for (int i = 1; i <= n; i++) {
        int x;
        do {
            x = brand() % maxx + 1;
        } while (s.count(x));
        s.insert(x);
        printf("%d ", x);
    }
    printf("\n");
    int q = brand() % 10 + 1;
    printf("%d\n", q);
    while (q--) {
        int opt;
        if (s.size() <= 1) opt = 1;
        else opt = brand() % 2 + 1;
        printf("%d ", opt);
        if (opt == 1) {
            int x, y;
            x = *next(s.begin(), brand() % s.size());
            do {
                y = brand() % maxx + 1;
            } while (s.count(y));
            s.insert(y); s.erase(x);
            printf("%d %d\n", x, y);
        }
        if (opt == 2) {
            int x;
            x = *next(s.begin(), brand() % s.size());
            s.erase(x);
            printf("%d\n", x);
        }
    }
    return 0;
}