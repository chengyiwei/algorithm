#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    
    freopen ("in.in", "w", stdout);
    srand(time(0));
    cout << 1 << "\n";
    ll n = rand() % 10 + 1, m = rand() % 10 + 1;
    cout << n << " " << m << "\n";
    for(int i = 1; i <= n; i ++){
        cout << rand() % 10 + 1 << " ";
    }
    cout << "\n";
    ll x, y, z = 0;
    for(int i = 1; i <= m; i ++){
        x = rand() % 5 + 1;
        x = z + x;
        y = rand() % n + 1;
        cout << x << " " << y << '\n';
        z = x;
    }
    return 0;
}