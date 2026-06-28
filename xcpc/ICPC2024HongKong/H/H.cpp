#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e5 + 5;
ll Tex, n, a[MAXN];
bool g[4][4][4][4][4][4][4][4], h[4][4][4][4][4][4][4][4];
struct node{
    int a1, a2, a3, a4, a5, a6, a7, a8;
};
vector<node> st;
int cnt = 0;
int M(int x) {
    if (x >= 3 && x % 3 == 0) return 3;
    else if(x < 0) return x;
    return (x % 3 + 3) % 3;
}
void dfs(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
    if(g[a1][a2][a3][a4][a5][a6][a7][a8]) return;
    g[a1][a2][a3][a4][a5][a6][a7][a8] = 1;
    cnt ++;
    st.push_back({a1, a2, a3, a4, a5, a6, a7, a8});
    dfs(M(a1 + 1), M(a2 + 1), M(a3 + 1), a4, a5, a6, a7, a8);
    dfs(a1, M(a2 + 1), M(a3 + 1), M(a4 + 1), a5, a6, a7, a8);
    dfs(a1, a2, M(a3 + 1), M(a4 + 1), M(a5 + 1), a6, a7, a8);
    dfs(a1, a2, a3, M(a4 + 1), M(a5 + 1), M(a6 + 1), a7, a8);
    dfs(a1, a2, a3, a4, M(a5 + 1), M(a6 + 1), M(a7 + 1), a8);
    dfs(a1, a2, a3, a4, a5, M(a6 + 1), M(a7 + 1), M(a8 + 1));
}
void dfs2(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
    if(h[a1][a2][a3][a4][a5][a6][a7][a8]) return;
    h[a1][a2][a3][a4][a5][a6][a7][a8] = 1;
    cnt ++;
    // if (a2 == 1) cout << a1 << " " << a2 << " " << a3 << "\n";
    st.push_back({a1, a2, a3, a4, a5, a6, a7, a8});
    dfs2(M(a1 + 3), a2, a3, a4, a5, a6, a7, a8);
    dfs2(a1, M(a2 + 3), a3, a4, a5, a6, a7, a8);
    dfs2(a1, a2, M(a3 + 3), a4, a5, a6, a7, a8);
    dfs2(a1, a2, a3, M(a4 + 3), a5, a6, a7, a8);
    dfs2(a1, a2, a3, a4, M(a5 + 3), a6, a7, a8);
    dfs2(a1, a2, a3, a4, a5, M(a6 + 3), a7, a8);
    dfs2(a1, a2, a3, a4, a5, a6, M(a7 + 3), a8);
    dfs2(a1, a2, a3, a4, a5, a6, a7, M(a8 + 3));
}
ll f[4][4][4][4][4][4][4][4];
void AC() {
    ll ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    node now = {0, 0, 0, 0, 0, 0, 0, 0};
    vector<node> qwq;
    f[now.a1][now.a2][now.a3][now.a4][now.a5][now.a6][now.a7][now.a8] ++;
    for (int i = 1; i <= n; i ++) {
        qwq.push_back(now);
        if (a[i] == 1) now.a1 = M(now.a1 + 1);
        if (a[i] == 2) now.a2 = M(now.a2 + 1);
        if (a[i] == 3) now.a3 = M(now.a3 + 1);
        if (a[i] == 4) now.a4 = M(now.a4 + 1);
        if (a[i] == 5) now.a5 = M(now.a5 + 1);
        if (a[i] == 6) now.a6 = M(now.a6 + 1);
        if (a[i] == 7) now.a7 = M(now.a7 + 1);
        if (a[i] == 8) now.a8 = M(now.a8 + 1);
        for (auto it : st) {
            node last;
            last = {
                M(now.a1 - it.a1),
                M(now.a2 - it.a2), 
                M(now.a3 - it.a3),
                M(now.a4 - it.a4),
                M(now.a5 - it.a5),
                M(now.a6 - it.a6),
                M(now.a7 - it.a7),
                M(now.a8 - it.a8)   
            };
            if (last.a1 < 0 || last.a2 < 0 || last.a3 < 0 || last.a4 < 0 || last.a5 < 0 || last.a6 < 0 || last.a7 < 0 || last.a8 < 0) continue;
            if(f[last.a1][last.a2][last.a3][last.a4][last.a5][last.a6][last.a7][last.a8]) {
                cout << last.a1 << " " << last.a2 << " " << last.a3 << " " << last.a4 << " " << last.a5 << " " << last.a6 << " " << last.a7 << " " << last.a8 << "\n";
                cout << now.a1 << " " << now.a2 << " " << now.a3 << " " << now.a4 << " " << now.a5 << " " << now.a6 << " " << now.a7 << " " << now.a8 << "\n";
            }
            ans += f[last.a1][last.a2][last.a3][last.a4][last.a5][last.a6][last.a7][last.a8];
        }
        f[now.a1][now.a2][now.a3][now.a4][now.a5][now.a6][now.a7][now.a8] ++;
        cout << ans << "\n";
    }
    qwq.push_back(now);
    for (auto it : qwq) {
        f[it.a1][it.a2][it.a3][it.a4][it.a5][it.a6][it.a7][it.a8] = 0;
    }
    cout << ans << "\n";
}

int main() {
    freopen("H.in", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    dfs(0, 0, 0, 0, 0, 0, 0, 0);
    dfs2(0, 0, 0, 0, 0, 0, 0, 0);

    // cout << cnt << "|\n";
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}