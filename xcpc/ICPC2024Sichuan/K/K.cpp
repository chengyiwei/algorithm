#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL dp[1 << 17];

int main(){
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    string s;
    cin >> s; s = " " + s;
    vector<vector<int> > nxt(m + 1, vector<int>(n));
    nxt[m].assign(n, m + 1);
    for(int i = m - 1; i >= 0; i--){
        nxt[i] = nxt[i + 1];
        nxt[i][s[i + 1] - 'a'] = i + 1;
    }
    const int all = (1 << n) - 1;
    for(int i = 1; i <= m; i++){
        auto &v = nxt[i];
        sort(v.begin(), v.end());
        int state = 0;
        for(auto x : v){
            if (x == m + 1) break;
            int b = s[i] - 'a', c = s[x] - 'a';
            int t = state;
            if (b == c){
                dp[t] += a[b][c];
                dp[t ^ (1 << b)] -= a[b][c];
            }
            else{
                dp[t] += a[b][c];
                dp[t ^ (1 << b)] -= a[b][c];
                dp[t ^ (1 << c)] -= a[b][c];
                dp[t ^ (1 << b) ^ (1 << c)] += a[b][c];
            }
            state |= 1 << (s[x] - 'a');
            if (b == c) break;
        }
    }
    auto ans = dp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < (1 << n); j++){
            if (j >> i & 1){
                ans[j] += ans[j ^ (1 << i)];
            }
        }
    }
    for(int i = 0; i < (1 << n); i++)
        cout << ans[i] << ' ';
    return 0;
}