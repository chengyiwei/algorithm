
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int brand() {
    return (rand() << 15) + rand();
}

int main() {
    freopen ("E.in", "w", stdout);
    srand(GetTickCount());
    // int T = 1; cout << T << '\n';
    // while (T--) {
    //     int n = rand() % 1000 + 1;
    //     cout << n << '\n';
    // }
    int T = 100; cout << T << '\n';
    while (T--) {
        long long x = 1e12 - T;
        cout << x << '\n';
    }
}