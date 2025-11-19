#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen ("G.in", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    srand(time(0));
    int n = rand() % 10000 + 1, m = rand() % 10000 + 1;
    cout << n << " " << m << "\n";
    for (int i = 0; i < m; i++) {
        int op = rand() % 3 + 1;
        int l = rand() % n + 1, r = rand() % n + 1;
        if (l > r) swap(l, r);
        if (op == 3) {
            cout << op << " " << l << " " << r << "\n";
        } else {
            int v = rand() % 60 + 1;
            cout << op << " " << l << " " << r << " " << v << "\n";
        }
    }
    return 0;
}