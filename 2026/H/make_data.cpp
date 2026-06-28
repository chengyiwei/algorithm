#include <bits/stdc++.h>
using namespace std;



int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n = rand() % 100000 + 1;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        int op = rand() % 3;
        if (op == 0) {
            cout << rand() % 5 + 1 << ' ';
        }
        else if (op == 1) {
            cout << '-' << rand() % 5 + 1 << ' ';
        }
        else {
            cout << '0' << ' ';
        }
    }
    cout << '\n';
    return 0;
}
