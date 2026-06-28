#include <bits/stdc++.h>
using namespace std;

int rnd () {
    return rand();
}

int main() {
    srand(time(0));
    int n = rnd() % 20 + 2, m = 10;
    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) {
        cout << rnd() % 3 << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= m; i++) {
        int op = rnd() % 2 + 1;
        if (op == 1) {
            int l, r; 
            l = rnd() % n + 1;
            r = rnd() % n + 1;
            if (l > r) swap (l, r);
            int v = rnd() % 5 + 1;
            cout << op << ' ' << l << ' ' << r << ' ' << v << '\n';
        } else {
            int l;
            int r;
            while (true) {
                l = rnd() % n + 1;
                r = rnd() % n + 1;
                if (l <= r && (r - l + 1) % 2 == 0) break;
            }
            cout << op << ' ' << l << ' ' << r << '\n';
        }
    }
}