#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 0x3f3f3f3f;

void solve() {
    int n, x, y, s; cin >> n >> x >> y >> s;
    int m = x % y;
    if ((s - n * m) % y != 0 || s < n * m) {
        cout << "NO" << '\n';
        return ;
    }
    int C = (s - n * m) / y;
    vector<int> F(C + 1,INF), G(C + 1, -1);
    for (int i = 1, j = x / y, sum = j; ; i++, j++ ,sum += j) {
        if (sum > C) break;
        F[sum] = i;
    }
    for (int i = 1, j = 0, sum = j; ; i++, j++, sum +=j) {
        int c = sum, w = i;
        if (c > C) break;
        for (int j = c; j <= C; j++){
            if (F[j - c] + w < F[j]){
                F[j] = F[j - c] + w;
                G[j] = j - c;
            }
        }
    }
    if (F[C] <= n){
        cout << "YES" << '\n';
        int p = C;
        vector<int> ans;
        while(p != -1) {
            int lst = G[C];
            if (G[p] != -1)
                ans.push_back(F[p] - F[G[p]]);
            else
                ans.push_back(F[p]);
            p = G[p];
        }
        reverse(ans.begin(), ans.end());
        for (int j = 0; j < ans.size(); j ++){
            if (j == 0) 
                for (int k = 0; k < ans[j]; k++)
                    cout << x + k * y << ' ';
            else 
                for (int k = 0; k < ans[j]; k++)
                    cout << m + k * y << ' ';
        }
        for (int j = 0; j < n - accumulate(ans.begin(), ans.end(), 0); j ++)
            cout << m << ' ';
        cout << '\n';
    }
    else{
        cout << "NO" <<'\n';
    }
}

signed main() {
    freopen ("E.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}