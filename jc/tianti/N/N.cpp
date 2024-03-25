#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
struct Block {
    int st, ed;
    LL add, cf;
}b[1500];

int a[maxn], belong[maxn];

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

inline void print(LL x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    freopen ("N.in","r",stdin);

    int n, q;  n = read(); q = read();

    int siz = sqrt(n), t = n / siz + (n % siz != 0);

    for (int i = 1; i <= t; i++) {
        b[i].st = (i - 1) * siz + 1; b[i].ed = i * siz;
        b[i].add = b[i].cf = 0;
    }
    b[t].ed = n;

    for (int i = 1; i <= n; i++)
        a[i] = read(), belong[i] = (i - 1) / siz + 1;
    
    while (q--) {
        int opt; opt = read();
        if (opt == 1) {
            int l, r; LL K, D; l = read(); r = read(); K = read(); D = read();
            if (belong[l] = belong[r]) {
                for (int i = l; i <= r; i++)
                    a[i] += K + D * (i - l);
                continue;
            }
            for (int i = l; i <= b[belong[l]].ed; i++)
                a[i] += K + D * (i - l);
            for (int i = belong[l] + 1; i < belong[r]; i++) {
                b[i].add += K + D * (b[i].st - l);
                b[i].cf += D;
            }
            for (int i = b[belong[r]].st; i <= r; i++)
                a[i] += K + D * (i - l);
        }
        else {
            LL pos; pos = read();
            LL ret = a[pos] + b[belong[pos]].add + b[belong[pos]].cf * (pos - b[belong[pos]].st);
            print(ret); putchar('\n');
        }
    }
    return 0;
}