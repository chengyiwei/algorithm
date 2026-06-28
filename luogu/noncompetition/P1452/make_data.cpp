#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main() {
    srand(GetTickCount());
    freopen ("in.in", "w", stdout);
    int n = rand() % 10 + 2;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        cout << rand() % 10 << ' ' << rand() % 10 << '\n';
    }
}