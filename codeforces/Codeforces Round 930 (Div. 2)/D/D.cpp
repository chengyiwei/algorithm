#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e18;
void solve() {
    int n;
    string s;
    cin >> n >> s;

    auto calc = [&]() {
        vector<LL> ans(n, INF);
        int cnt1 = 0,cnt2 = 0;
        LL s1 = 0, s2 = 0;
        if (s[0] == '<') cnt2 += 1, s2 += 0;
        int last = -1;
        for (int i = 0, j = 0; i < n; i++) {
            if (s[i] == '>') {
                cnt1 += 1;
                s1 += i;
                if (last == -1) last = i;
            }
            if (s[i] == '<') {
                cnt2 -= 1;
                s2 -=i;
            }
            while (cnt1 > cnt2 && j < n) {
                ++ j;
                if (s[j] == '<') 
                    cnt2 += 1, s2 += j;
            }
            if (cnt1 > cnt2) break;
            if (last == -1) ans[i] = i + 1;
            else ans[i] = 2 * (s2 - s1) + i + 1;
        }
        return ans;
    };

    auto ans1 = calc();
    reverse(s.begin(), s.end());
    for (auto & x : s) {
        if (x == '>') x = '<';
        else x = '>';
    }
    auto ans2 = calc();
    for (int i = 0; i < n; i++) 
        cout << min(ans1[i], ans2[n - i - 1]) << " ";
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}