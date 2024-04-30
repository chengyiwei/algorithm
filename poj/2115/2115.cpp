#include <cstdio>
#include <iostream>

using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, x, y), x0 = x, y0 = y;
    x = y0, y = x0 - a / b * y0;
    return d;
}
int main() {
    LL A, B, C, k;
    while(scanf("%lld%lld%lld%lld", &A, &B, &C, &k) != EOF && A + B + C + k) {
        LL d = gcd(C, 1ll << k);
        if ((B - A) % d != 0) {
            puts("FOREVER");
        } else {
            LL a = C / d, b = (1ll << k) / d, c = (B - A) / d;
            LL x, y;
            exgcd(a, b, x, y);
            x = (x * c % b + b) % b;
            printf("%lld\n", x);
        }
    }
}