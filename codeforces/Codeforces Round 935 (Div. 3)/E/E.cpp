#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("E.in","r",stdin);
    
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        int pos;
        vector<int> a(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            if (a[i] == x) {pos = i; break;}
        int l = 1, r = n + 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (a[mid] <= x) l = mid;
            else r = mid;
        }
        if (l == pos)
            cout << 0 << '\n';
        else {
            cout << 1 << '\n';
            cout << l << ' ' << pos << '\n';
        }
    }
    return 0;
}