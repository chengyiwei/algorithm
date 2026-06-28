#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll TT = 1e9 + 7;

ll dp[104][205][11][11][2][2][2];

ll dfs(int pos, int cp, int pre1, int pre2, int limit, int n3, int lead, vector<int> &num) {
    ll ret = 0;
    if (pos == -1)
        return n3 && (abs (cp - 100) >= 1);
    if (~ dp[pos][cp][pre1][pre2][limit][n3][lead])
        return dp[pos][cp][pre1][pre2][limit][n3][lead];
    int up = (limit ? num[pos] : 9);
    for (int i = 0; i <= up; i++) {
        if (lead && i == 0)
            ret += dfs (pos - 1, cp, i, pre1, limit && (i == up), n3 , 1, num);
        else 
            ret += dfs (pos - 1, cp + (i == 0) - (i == 1), i, pre1, limit && (i == up), n3 | (i == 3 && pre1 == 3 && pre2 == 3), 0, num);
        ret %= TT;
    }
    return dp[pos][cp][pre1][pre2][limit][n3][lead] = ret;
}

ll solve(vector<int> p) {
    memset(dp, -1, sizeof dp);
    return dfs (p.size() - 1, 100, -1, -1, 1, 0, 1, p);
}

int check (string s) {
    int op = 0, op2 = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') op ++;
        if (s[i] == '0') op --;
    }
    for (int i = 0; i + 3 - 1 < s.size(); i++) {
        if (s.substr(i, 3) == (string)"333")
            op2 |= 1;
    }
    op = (abs (op) >= 1);
    return op && op2;
}

int main() {
    freopen ("M.in" ,"r", stdin);
    string l, r; cin >> l >> r;
    vector<int> L, R;
    for (int i = 0; i < l.size(); i++)
        L.push_back(l[i] - '0');
    for (int i = 0; i < r.size(); i++)
        R.push_back(r[i] - '0');

    reverse(R.begin(), R.end());
    reverse(L.begin(), L.end());
    ll ans = ((solve(R) - solve(L) + check(l)) % TT + TT) % TT;
    cout << ans << endl;
    return 0;
}