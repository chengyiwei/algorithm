#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Team {
    int id, val;
    string name;
    bool operator < (const Team B) const {
        return val < B.val;
    }
};

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<Team> a(n + 1);
    int c = INF;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        c = min(c, x);
    }
    for (int i = 1; i <= n; i++) {
        a[i].id = i;
        cin >> a[i].val;
        cin >> a[i].name;
    }
    auto v = a;
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    map<string, int> cnt;
    int pre = 0;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; ) {
        int j = i;
        while (j <= n && a[j].val == a[i].val) j += 1;
        for (int k = i; k < j; k++) {
            int id = a[k].id;
            ans[id] = pre + 1;
            if (cnt[a[k].name] == c) ans[id] -= 1;
        }

        for (int k = i; k < j; k++) {
            if (cnt.find(a[k].name) == cnt.end()) cnt[a[k].name] = 0;
            if (cnt[a[k].name] < c) {
                cnt[a[k].name] += 1;
                pre += 1;
            }
        }

        i = j;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}