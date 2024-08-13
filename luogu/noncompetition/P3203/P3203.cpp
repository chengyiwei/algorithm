#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("P3203.in", "r", stdin);
    int n; cin >> n;
    int block = sqrt(n), t = n / block + (n % block != 0); // t 表示块数
    vector<int> a(n + 1), belong(n + 1), stp(n + 1, 0), to(n + 1, 0);
    vector<int> st(t + 1), ed(t + 1);
    for (int i = 1; i <= t; i++)
        st[i] = (i - 1) * block + 1, ed[i] = i * block;
    ed[t] = n;
    for (int i = 1; i <= n; i++)
        belong[i] = (i - 1) / block + 1;

    for (int i = 1; i <= n; i++) 
        cin >> a[i];

    auto update = [&](int x) { // 更新块 x
        for (int i = ed[x]; i >= st[x]; i--) {
            if (i + a[i] > ed[x])
                to[i] = i + a[i], stp[i] = 1;
            else
                to[i] = to[i + a[i]], stp[i] = stp[i + a[i]] + 1;
        }
    };
    
    for (int i = t; i >= 1; i--) 
        update(i);
    
    int q; cin >> q;
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int ret = 0, x; cin >> x;x += 1;
            while (x <= n) 
                ret += stp[x], x = to[x];
            cout << ret << '\n';
        }
        else {
            int x, val; cin >> x >> val; x += 1;
            a[x] = val;
            update(belong[x]);
        }
    }
    return 0;
}