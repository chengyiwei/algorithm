#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("F.in", "w", stdout);
    srand(time(0));
    int t = 1; cout << t << '\n';
    int n = rand() % 200 + 1; cout << n << "\n";
    for (int i = 1; i <= n; i++) {
        cout << rand() % 100000000 + 1 << ' ';
    }
    cout << '\n';
    return 0;
}