#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;
typedef pair<int, int> pii;
int vis[maxn + 5];


int main() {
    double a, b; cin >> a >> b;
    int A = a * maxn, B = b * maxn;
    queue<int> q; q.push(B);
    vector<pii> pre(maxn + 5, {-1, -1})
    while (!q.empty()) {
        
        auto insert = [&] (int nxt_u, int op) {
            if (nxt_u < 0 || nxt_u > maxn || vis[nxt_u]) return;
            vis[nxt_u] = 1;
            vis[nxt_u] = 1;
            q.push(node(nxt_u, u, op));
        };
    
        insert(u * 2, 1); insert((u - maxn) * 2 + maxn, 2);
    }
}