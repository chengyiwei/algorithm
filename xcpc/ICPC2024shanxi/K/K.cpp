#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
const int INF = 3e18 + 1000;
const int maxn = 5e5 + 5;
int n, m, k; 
int cnt[maxn];
pii cost[maxn];
struct Node {
    int tim, pos, id;
    bool operator < (const Node &a) const {
        return tim < a.tim;
    }
}a[maxn];

int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

void write(int x) {
    if (x < 0) {putchar('-'); x = -x;}
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

bool check (int T) {
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    int num = 0;
    for (int j = m; j >= 1; j--) {
        int id = a[j].id;
        if (a[j].tim > T) continue;
        if (1) {
            int now = ((T - a[j].tim + 1 - cnt[id])) + (- a[j].pos + 1) / k;
            if (now <= 0) continue;
            cnt[id] += now;
            cost[num++] = {a[j].tim, now};
        }
    }
    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += cost[i].second;
        if (sum > T + 1 - cost[i].first)
            return false;
    }
    return true;
}

signed main() {
    freopen ("K.in", "r", stdin);
    freopen ("K.out", "w", stdout);
    // ios::sync_with_stdio(0);
    n = read(), m = read(), k = read();
    set<int> st;
    for (int i = 1; i <= m; i++) {
        int t, id, y; t = read(), id = read(), y = read();
        st.insert(id);
        a[i] = {t, y, id};
    }
    if (st.size() == 1) { puts("-1"); return 0; }
    sort(a + 1, a + m + 1);
    int L = 0, R = INF;
    while (L + 1 < R) {
        int mid = (R + L) / 2;
        if (check (mid))
            L = mid;
        else 
            R = mid;
    }
    write(L);
    return 0;
}