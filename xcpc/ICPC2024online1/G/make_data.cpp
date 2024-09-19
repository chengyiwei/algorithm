#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("G.in", "w", stdout);
    srand(time(0)); 
    int n = rand() % 10 + 1;
    cout << n << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << rand() % 100 << ' ';
    }
    cout << '\n';
}