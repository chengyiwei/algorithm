#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), s(n + 1, 0), f(n + 1, INF);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    vector<int> p;
    int lst = 0;
    for (int i = 1; i <= n; i ++) {
        if (i != 1)
            p.push_back(i - 1);
        if (p.size() > 0) {
            int l = 0, r = p.size() - 1, now = INF;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (s[i - 1] - s[p[mid] - 1] > a[i]) 
                    now = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            if (now != INF)
                f[i] = i - p[now];
        }
        if (i != 1)
            p.pop_back();
        if (i != 1 && a[i] != a[i - 1]) {
            for (int j = lst + 1; j < i; j++) 
                p.push_back(j);
            lst = i - 1;
        }
    }

    p.clear(); lst = n + 1;
    for (int i = n; i ; i--) {
        if (i != n)
            p.push_back(i + 1);
        if (p.size() > 0) {
            int l = 0, r = p.size() - 1, now = INF;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (s[p[mid]] - s[i] > a[i]) 
                    now = mid, l = mid + 1;
                else
                    r = mid - 1;
            }
            if (now != INF)
                f[i] = min(f[i], p[now] - i);
        }
        if(i != n)
            p.pop_back();
        if (i != n && a[i] != a[i + 1]) {
            for (int j = lst - 1; j > i; j--) 
                p.push_back(j);
            lst = i + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (f[i] == INF) 
            f[i] = -1;
        cout << f[i] << ' ';
    }

    cout << '\n';
}   

signed main() {
    freopen("D.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}