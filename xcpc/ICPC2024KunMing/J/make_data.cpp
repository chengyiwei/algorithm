#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return (rand() << 15) | rand();
}

int main() {
    freopen ("J.in", "w", stdout);
    srand(GetTickCount());
    int t; t = 1; cout << t << endl;
    while (t--) {
        int n = 5, m = 5, k = 3;
        cout << n << " " << m << " " << k << endl;
        for (int i = 1; i <= m; i++) {
            int u = rand() % n + 1, v = rand() % n + 1, c = rand() % m + 1, l = rand() % 10 + 1;
            cout << u << " " << v << " " << c << " " << l << endl;
        }
        for (int i = 1; i <= k; i++) {
            int C = rand() % m + 1, L = rand() % 20 + 1;
            cout << C << " " << L << endl;
        }
    }
}