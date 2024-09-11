#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("J.in", "w", stdout);
    srand(time(0));
    int T = 1;
    cout << T << '\n';
    int n = rand() % 2 + 1;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) cout << rand() % 100 + 1 << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++) cout << rand() % 100 + 1 << ' ';
    cout << '\n';
    return 0;
}