#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5, MOD = 1 << 21, M = 21 + 1;

bool c[M][1 << M];
int s[MAXN], siz = 0;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

void print(int x) {
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

inline void add(int id, int pos) {
    pos += 1;
    for (int i = pos; i < (1 << M); i += i & -i) {
        c[id][i] ^= 1;
    }
}

inline bool get(int id, int pos) {
    pos += 1;
    int res = 0;
    for (int i = pos; i; i -= i & -i) {
        res ^= c[id][i];
    }
    return res;
}

inline bool query(int id, int l, int r) {
    return get(id, r) ^ get(id, l - 1);
}

int main() {
    freopen ("D.in", "r", stdin);
    int q = read();
    while (q--) {
        int t = read(), v = read();
        while (t--) {
            for (int i = 0; i <= 20; i++) {
                int TT = (1 << i + 1);
                int val = (-s[siz - 1] % TT + TT) % TT;
                add(i, val);
            }
            siz -= 1;
        }
        siz += 1;
        s[siz] = (s[siz - 1] + v) % MOD;
        for (int i = 0; i <= 20; i++) {
            int TT = (1 << i + 1);
            int val = (-s[siz - 1] % TT + TT) % TT;
            add(i, val);
        }
        int ret = 0;
        for (int i = 0; i <= 20; i++) {
            int TT = (1 << i + 1);
            int sn = s[siz] % TT;
            int l = ((1 << i) - sn + TT) % TT, r = ((1 << i + 1) - 1 - sn + TT) % TT;
            bool cnt = 0;
            if (l <= r) cnt = query(i, l, r);
            else cnt = query(i, 0, r) ^ query(i, l, (1 << i + 1) - 1);
            ret |= cnt * (1 << i);
        }
        print(ret); putchar('\n');
    }
    return 0;
}