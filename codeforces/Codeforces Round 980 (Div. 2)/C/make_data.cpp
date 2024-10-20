#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("C.in","w", stdout);
    srand(time(0));
    int T = 1;
    cout << T << '\n';
    int n = rand() % 10 + 1;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        cout << rand() % 10 + 1 << ' ' << rand() % 10 + 1 << '\n';
    }
}