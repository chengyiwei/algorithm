#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("P3806.in", "w", stdout);
    srand(time(0));
    int n = rand() % 5 + 1, m = 10;
    cout << n << ' ' << m << '\n';
    for (int i = 2; i <= n; i++) {
        int fa = rand() % (i - 1) + 1, w = rand() % 3 + 1;
        cout << i << ' ' << fa << ' ' << w << '\n';
    }
    for (int i = 1; i <= m; i++) {
        int w = rand() % 10 + 1;
        cout << w << ' ';
    }
    return 0;
}