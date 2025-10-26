#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 50005;

int belong[MAXN], a[MAXN];
int block; // 块的大小

struct Query {
    int l, r, id;
    bool operator < (const Query &other) const {
        if (belong[l] != belong[other.l]) return belong[l] < belong[other.l];
        return r < other.r;
    }
}q[MAXN];

int sum, cnt[MAXN];

void add(int x) {
    sum += cnt[x];
    cnt[x] += 1;
}

void del(int x) {
    cnt[x] -= 1;
    sum -= cnt[x];
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

pair<int, int> ans[MAXN];

signed main() {
    int n, m; cin >> n >> m;
    block = sqrt(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        belong[i] = (i - 1) / block + 1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);

    int l = 1, r = 0;
    for (int i = 1; i <= m; i++) {
        while (r < q[i].r) add(a[++r]);
        while (r > q[i].r) del(a[r--]);
        while (l < q[i].l) del(a[l++]);
        while (l > q[i].l) add(a[--l]);
        int total = (q[i].r - q[i].l + 1) * (q[i].r - q[i].l) / 2;
        if (sum == 0) ans[q[i].id] = {0, 1};
        else {
            int g = gcd(sum, total);
            ans[q[i].id] = {sum / g, total / g};
        }
    }

    for (int i = 1; i <= m; i++) 
        cout << ans[i].first << "/" << ans[i].second << "\n";
    return 0;
}