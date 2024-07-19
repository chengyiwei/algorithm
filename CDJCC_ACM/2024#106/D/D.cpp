#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool is_prime(ll x) {
    if (x < 2) return false;
    for (ll i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ll N, K; cin >> N >> K; N += 1; K += 1;
    if (is_prime(K)) {
        if (N < 2ll * K) puts("1");
        else puts("2");
    }
    else 
        puts("2");
    return 0;
}