#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        char ch; cin >> ch;
        a[i] = ch - '0';
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int cnt_1 = 0;
    for (int i = 1; i <= n;) {
        int j = i;
        while (j <= n && a[j] == a[i]) j++;
        if (j - i > 1) pq.push({i, j - i});
        i = j;
    }
    int ans = 0, pos = 1;
    

    while (pos <= n) {

        auto get_pair = [&] () {
            while (!pq.empty() && pq.top().first < pos) pq.pop();
            if (pq.empty()) return pii(-1, -1);
            return pq.top();
        };

        auto [id, len] = get_pair();
        if (id == -1) {
            int ans2 = 0;
            for (int i = pos; i <= n; i) {
                int j = i;
                while (j <= n && a[j] == a[i]) j++;
                ans2 += 1;
                i = j;
            }
            cout << ans + (ans2 + 1) / 2 << '\n';
            return ;
        }
        else {
            int j = pos;
            while (j <= n && a[j] == a[pos]) j++;
            pos = j;
            ans += 1;
            pq.pop();
            if (len - 1 > 1) pq.push({id, len - 1});
        }
    }
    cout << ans << '\n';
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}