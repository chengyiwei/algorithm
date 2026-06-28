#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL read() {
    LL x = 0, f = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

void print(LL x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    LL n, TT; n = read(); TT = read();
    vector<LL> inv(n + 1);
    inv[1] = 1;
    for (LL i = 2; i <= n; i++)
        inv[i] = (LL)(TT - TT / i) * inv[TT % i] % TT;
    for (LL i = 1; i <= n; i++)
        print(inv[i]), putchar('\n');
    return 0;
}