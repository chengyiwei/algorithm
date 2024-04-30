#include <bits/stdc++.h>
using namespace std;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

void print(int x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

const int maxn = (1<<20) + 5;

int a[maxn];
int st[25];
int main() {
    int n = read();
    for (int i = 0; i < n; i++) a[i] = read();
    int q = log2(n);
    for (int i = 0; i < n; i++) {
        int x = i;
        for (int j = 0; j < q; j++) 
            st[j] = x >> j & 1;
        int p = 0;
        reverse(st, st + q);
        for (int j = 0; j < q; j++)
            p |= st[j] << j;
        print(a[p]);
        putchar(' ');
    }
    return 0;
}