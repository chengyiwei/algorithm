#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool is_prime(ll x) {
    if (x < 2) return false;
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    ll p;
    cin >> p; p++;
    if (p == 1) 
        return cout << 0 << endl, 0;
    if (p == 2)
        return cout << 1 << endl, 0;
    if (p == 3)
        return cout << 2 << endl, 0;
    if (p == 4)
        return cout << 2 << endl, 0;
    if (is_prime(p))
        return cout << p - 1 << endl, 0;
    else 
        return cout << 0 << endl, 0;
}