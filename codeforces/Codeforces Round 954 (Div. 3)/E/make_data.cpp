#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("E.in", "w", stdout);
    ios::sync_with_stdio(false);
    srand(time(0));
    int T = 1; cout << T << '\n';
    int n = rand() % 10 + 1, k = rand() % 10 + 1;
    cout << n << " " << k << '\n';
    for (int i = 1; i <= n; i++)
        cout << rand() << " ";
    cout << '\n';
    return 0;
}