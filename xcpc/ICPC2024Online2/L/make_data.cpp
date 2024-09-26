#include <bits/stdc++.h>
using namespace std;

int brand() {
    return (rand() << 16) + (rand() << 1) + (rand() & 1);
}

int main() {
    freopen ("L.in", "w", stdout);
    srand(time(0));
    int n = 1e6;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        int x = brand() % 1000000000 + 1;
        cout << x << '\n';
    }
    return 0;
}