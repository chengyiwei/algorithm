#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int read(){
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
void print(int x){
    if (x < 0) {putchar('-'); x = -x;}
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

bool vis[maxn];
void solve() {
    int n = read(), k = read();
    int cnt = 0, j = 0;
    vector<int> p;
    int q = k - 1;
    while (q >= (1 << j)) {
        p.push_back(1 << j);
        q -= 1 << j;
        j++;
    }
    if (q) p.push_back(q);
    vis[0] = 1;
    for (auto& x : p) {
        for (int j = n; j >= x; j--)
            vis[j] |= vis[j - x];
    }
    for (int i = k + 1; i <= n; i++)
        if (!vis[i]) {
            p.push_back(i);
            for (int j = n; j >= i; j--)
                vis[j] |= vis[j - i];
        }
    print(p.size()), putchar('\n');
    for (auto x : p)
        print(x), putchar(' ');
    putchar('\n');
    for (int i = 0; i <= n; i++)
        vis[i] = 0;
}

int main() {
    int t = read();
    while (t--) solve();
    return 0;
}