#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen ("C.in", "w", stdout);
    ios::sync_with_stdio(false);
    srand(time(0));
    cin.tie(0); cout.tie(0);
    int t = 20; cout << t << "\n";
    while (t--) {
        int n = rand() % 2 + 2;
        cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            cout << rand() % 4 + 1 << ' ';
        }
        cout << "\n";
        for (int i = 1; i <= n; i++) {
            cout << rand() % 4 + 1 << ' ';
        }
        cout << "\n";
    }
}