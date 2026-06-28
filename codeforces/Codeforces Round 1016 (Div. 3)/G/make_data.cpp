#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(0));
    freopen ("G.in", "w", stdout);
    int T = 1; cout << T << '\n';
    int n = 50, k = rand() % 10000;
    cout << n << ' ' << k << '\n';
    for (int i = 1; i <= n; i++) {
        cout << (rand() % 10000) << ' '; 
    }
    cout << '\n';
    
}