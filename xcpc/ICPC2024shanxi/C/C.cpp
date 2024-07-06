#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int fa[maxn], p[maxn], vis[maxn], dep[maxn], hsh[maxn], clr[maxn];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x != y)
        fa[x] = y;
}

int main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= 2 * n; i++) fa[i] = i, dep[i] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        merge(p[i], i);
    }
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (dep[i] != -1) continue;
        int x = i;
        while (1) {
            st.push(x), vis[x] = 1;
            if (p[x] == 0) {
                dep[x] = 0; st.pop(); break;
            }
            else if (vis[p[x]]) {
                if (dep[p[x]] != -1) {
                    break;
                }
                else {
                    clr[find(x)] = 1;
                    int cnt = 0;
                    stack<int> stk_now;
                    do {
                        stk_now.push(st.top()); st.pop();
                    } while (stk_now.top() != p[x]);
                    cnt = stk_now.size();
                    while (!stk_now.empty())
                        dep[stk_now.top()] = cnt, stk_now.pop();
                    hsh[find(x)] = cnt;
                    break;
                }
            }
            x = p[x];
        }
        while (!st.empty()) {
            int u = st.top(); st.pop();
            dep[u] = dep[p[u]] + 1;
            if (clr[find(u)] == 0) hsh[find(u)] = max(hsh[find(u)], dep[u]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n; i++)
        ans += hsh[i];
    cout << ans << endl;
    return 0;
}  