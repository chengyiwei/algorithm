#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("I.in", "w", stdout);
    srand(time(0));
    int n = rand() % 10 + 3;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        int x = rand() % 64;
        if (0 <= x && x <= 9) cout << x;
        else if (10 <= x && x <= 35) cout << (char)(x - 10 + 'A');
        else if (36 <= x && x <= 61) cout << (char)(x - 36 + 'a');
        else cout << '?';
    }
    return 0;
}