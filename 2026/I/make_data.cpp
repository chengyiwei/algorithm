#include <bits/stdc++.h>
using namespace std;



int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n = rand() % 100000 + 1;
    cout << n << '\n';
    for (int i = 1; i <= n; i++) {
        cout << rand() % 1000000 + 1 << ' ' << rand() % 1000000 + 1 << '\n';
    }
    return 0;
}
