#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll a, b; cin >> a >> b;
    ll g = __gcd(a, b), d = 0;
    if (a / g % 2 == 1 && b / g % 2 == 1) 
        d = g;
    cout << ( a * b + d >> 1 ) << endl;
    return 0;
}