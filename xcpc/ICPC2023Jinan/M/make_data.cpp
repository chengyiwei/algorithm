#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int main() {
    freopen ("M.in", "w", stdout);
    srand(GetTickCount());
    int n = 4;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << rand() % 5 << " " << rand() % 5 << endl;
    }
}
