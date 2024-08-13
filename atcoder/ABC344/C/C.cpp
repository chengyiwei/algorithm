#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, l;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    cin >> l;
    vector<int> c(l);
    for (int i = 0; i < l; i++) cin >> c[i];
    
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < l; k++)
                mp[a[i] + b[j] + c[k]] = 1;
    
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << (mp.count(x) ? "Yes" : "No") << endl;
    }
    return 0;
}