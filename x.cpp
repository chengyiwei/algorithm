#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
typedef long long LL;

LL c[maxn], a[maxn];

void add_x(int x,LL val) {
    while(x < maxn) c[x] += val, x += x & -x;
}

LL query(int x) {
    LL ret=0;
    while (x) ret += c[x], x -= x & -x;
    return ret;
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        add_x(i,a[i]);
    for (int i = 1; i <= m;i++)  {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1) {
            add_x(x,y);
        }
        else {
            cout << query(y) - query(x - 1) << '\n';
        }
    }
    return 0;
}