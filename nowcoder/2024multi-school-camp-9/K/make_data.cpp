#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("K.in", "w", stdout);
    srand(time(0));
    int n = rand() % 10 + 1;
    int k = rand() % 10 + 1;
    cout << n << " " << k << endl;
    for (int i = 1; i <= n; i++) {
        cout << rand() % 100 + 1 << " ";
    }
    
}