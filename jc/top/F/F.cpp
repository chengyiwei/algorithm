#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; cin >> T;
    vector<int> vis(10001,0);
    while (T--) {
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            vis[x] ++ ;
        }
    }
    int max_x = 0, max_i = 0;
    for (int i = 1; i <= 10000; i++) {
        if (vis[i] >= max_x) {
            max_x = vis[i];
            max_i = i;
        }
    }
    cout << max_i << " " << max_x << endl;
    return 0;
}