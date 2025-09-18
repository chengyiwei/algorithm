#include <bits/stdc++.h>
using namespace std;

int n;

struct node {
    int tot, ch[26];
    node () {
        tot = 0;
        memset(ch, 0, sizeof ch);
    }
};

int cnt = 0;
vector<node> tr(1);

void insert(string &s) {
    int now = 0;
    for (auto &c : s) {
        int x = c - 'a';
        if (tr[now].ch[x] == 0) {
            tr[now].ch[x] = ++cnt;
            tr.emplace_back();
        }
        now = tr[now].ch[x];
        tr[now].tot += 1;
    }
}

long long ans = 0;

void dfs(int now) {
    ans += 1ll * (tr[now].tot / 2) * (tr[now].tot - tr[now].tot / 2);
    for (int j = 0; j < 26; j++) {
        if (tr[now].ch[j] != 0)
            dfs(tr[now].ch[j]);
    }
}

int main() {
    // freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        string s; cin >> s;
        insert(s);
    }
    dfs(0);

    cout << ans << '\n';
    return 0;
}