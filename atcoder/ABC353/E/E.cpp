#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int maxn = 3e5 + 10;

int cnt;

struct Node {
    int val;
    int son[26];
    Node() {
        val = 0;
        memset (son, 0, sizeof (son));
    }
}tr[maxn];

void insert (string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!tr[p].son[u]) tr[p].son[u] = ++cnt;
        p = tr[p].son[u];
        tr[p].val += 1;
    }
}

int find_same (string s) {
    int p = 0;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!tr[p].son[u]) break;
        p = tr[p].son[u];
        res += tr[p].val;
    }
    return res;
}

signed main() {
    // freopen ("E.in", "r", stdin);
    int n; cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        ans += find_same (s);
        insert (s);
    }
    cout << ans << endl;
    return 0;
}