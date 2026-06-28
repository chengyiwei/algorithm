#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return (rand() << 15) | rand();
}
int main() {
    freopen ("CF1480A.in", "w", stdout);
    srand(GetTickCount());
    int t = 10;
    printf("%d\n", t);
    while (t--) {
        int n = brand() % 10000 + 1;
        printf("%d\n", n);
        vector<int> a(n);
        for (auto &x : a) x = brand() % 1000000000 + 1;
        if (brand() & 1) {
            sort(a.begin(), a.end());
            reverse(a.begin(), a.end());
        }
        for (auto x : a) printf("%d ", x);
        puts("");
    }
    return 0;
}