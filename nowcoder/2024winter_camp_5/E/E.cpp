#include <bits/stdc++.h>

using namespace std;
typedef __int128 LL;

LL read() {
    LL x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

void print(LL x) {
    if (x < 0) {putchar('-'); x = -x;}
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

vector<LL> c;
void add_x(int x,LL data){
    for (; x < c.size(); x += x & -x) c[x]+=data;
}
LL get(int x){
    LL ans = 0;
    for (; x; x -= x & -x) ans += c[x];
    return ans;
}

void solve() {
    int n = read();
    vector<LL> a(n+1); c.assign(n+2,0);
    for (int i = 1; i <= n; i++) a[i] = read();
    if (n % 2 == 0) {printf("YES\n"); return;}
    for (int i = n - 1; i > 1; i --) {
        LL now = a[i] + get(i) * (LL)i, pre = a[i - 1] + get(i - 1) * (LL)(i - 1);
        if (pre > now) {
            LL x = pre - now;
            if (i % 2 == 0)
                add_x(1,x), add_x(i + 1, -x);
            else 
                add_x(1,x), add_x(i + 2, -x);
        }
    }

    for (int i = 1; i <= n; i++) {
        a[i] += get(i) * i;
    }

    // for (int i = 1; i <= n; i++) {
    //     print(a[i]); putchar(' ');
    // }

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) {printf("NO\n"); return ;}
    }
    printf("YES\n");
}

int main() {
    freopen("E.in", "r", stdin);
    int T; scanf ("%d", &T);
    while (T--) solve(); 
}