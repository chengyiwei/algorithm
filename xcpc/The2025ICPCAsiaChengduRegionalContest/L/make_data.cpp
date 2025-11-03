#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(0));
    freopen ("L.in", "w", stdout);
    cout << 1 << '\n';
    int n = 200; cout << n << '\n';
    for (int i = 0; i < n; i++) {
        if (rand() % 2 == 0) cout << '0' << ' ';
        else cout << rand() % n + 1 << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        if (rand() % 2 == 0) cout << '0' << ' ';
        else cout << rand() % n + 1 << ' ';
    }
    cout << '\n';
    for (int i = 1; i < n; i++) {
        cout << i << ' ' << i + 1 << '\n';
    }
}