#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main() {
    freopen ("C.in", "w", stdout);
    srand(GetTickCount());
    int T = 1;
    cout << T << '\n';
    int n = rand() % 5 + 1;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        int x = rand() % 10 + 1;
        cout << x << ' ';
    }
    cout << '\n';
}