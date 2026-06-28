#include <bits/stdc++.h>
using namespace std;

int n, k;
deque<int> res;

int dfs(int pos, int now) {
    if (now + k > n * (n - 1) / 2) return 0;
    if (now + k == n * (n - 1) / 2) {
        vector<int> ans;
        res.push_front(0);
        int len = res.size();
        for (int i = 0; i + 1 < len; i++)
            for (int j = res[i + 1]; j > res[i]; j--)
                ans.push_back(j);

        for (int j = res.back() + 1; j <= n; j++)
            ans.push_back(j);
        reverse(ans.begin(), ans.end());
        for (int x : ans) cout << x << ' ';
        return 1;
    }
    if (pos == n || pos == n - 1)
        return 0;
    for (int nxt = pos + 2; nxt <= n; nxt++) {
        res.push_back(nxt);
        int len = nxt - pos;
        int tmp = len * (len - 1) / 2;
        if (dfs(nxt, now + tmp)) return 1;
        res.pop_back();
    }
    return 0;
}

void solve() {
    cin >> n >> k;
    res.clear();
    if (!dfs(0, 0)) cout << 0;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}