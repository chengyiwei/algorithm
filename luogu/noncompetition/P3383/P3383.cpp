#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> p;
    vector<bool> vis(n + 1, 0);
    for (int i = 2; i <= n; i++ ){
        if (!vis[i]) p.push_back(i);
        for (int j = 0; j < p.size(); j++) {
            if (i * p[j] > n) break;
            vis[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
    while (q--) {
        int x;
        cin >> x;
        cout << p[x - 1] << '\n';
    }
    return 0;
}