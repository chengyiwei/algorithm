#include<bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<string> s(n);
    vector<vector<int> > cnt (n, vector<int> (26, 0));
    vector<string> ans(n, "");
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        for (auto &c : s[i]) cnt[i][c - 'a']++;

    map<int, vector<int> > mp;

    function<bool(int,map<int, vector<int> >)> check = [&] (int i, map<int, vector<int> > PS) {  // 对于第 i 个来说有这么多约束
        if (i == 0) {
            vector<int> now_cnt(26, 0);
            for (auto [k, P] : PS) {
                for (int j = 0; j < 26; j++) {
                    if (P[j] < now_cnt[j]) return false;
                    for (int p = now_cnt[j]; p < P[j]; p++)
                        ans[0].push_back('a' + j), now_cnt[j]++;
                }
            }
            for (int j = 0; j < 26; j++)
                while (now_cnt[j] < cnt[0][j]) 
                    ans[0].push_back('a' + j), now_cnt[j]++;
            return true;
        }

        map<int, vector<int> > now_PS;

        function<bool(int,vector<int>)> build = [&] (int k, vector<int> P) {
            int k_ = k % s[i - 1].size();
            int num = k / s[i - 1].size();
            if (num > 0) {
                for (int j = 0; j < 26; j++) {
                    if (P[j] < cnt[i - 1][j] * num) return false;
                    P[j] -= cnt[i - 1][j] * num;
                }
            }
            if (!now_PS.count(k_)) now_PS[k_] = P;
            else if (now_PS[k_] != P) return false;
            return true;
        };

        // si 约束 si-1
        if (!build(s[i].size(), cnt[i])) return false;

        for (auto [k, P] : PS) // 传递约束
            if (!build(k, P)) return false;

        bool ok = check(i - 1, now_PS);
        if (!ok) return false; 
        // 开始构造序列

        vector<int> now_cnt(26, 0);
        for (int j = 0; j < s[i].size(); j++) {
            char c = ans[i - 1][j % s[i - 1].size()];
            if (now_cnt[c - 'a'] < cnt[i][c - 'a']) {
                ans[i].push_back(c);
                now_cnt[c - 'a']++;
            }
            else 
                return false;
        }

        return true;
    };
    bool ok = check(n - 1, mp);
    if (!ok) {cout << "NO" << '\n'; return;}
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
    
}

signed main() {
    freopen("E.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}