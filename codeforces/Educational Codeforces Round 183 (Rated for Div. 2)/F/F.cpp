#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500000 + 5;
int n;
vector<int> g[MAXN];

pair<int, vector<int>> bfs(int s) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    int far = s;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (dist[v] > dist[far] || (dist[v] == dist[far] && v > far))
                    far = v;
            }
        }
    }
    return {far, dist};
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto t1 = bfs(1);
    int A = t1.first;
    auto t2 = bfs(A);
    int B = t2.first;
    vector<int> distA = t2.second;

    auto t3 = bfs(B);
    vector<int> distB = t3.second;

    for (int i = 1; i <= n; i++) {
        if (distA[i] > distB[i]) cout << A << '\n';
        else if (distA[i] < distB[i]) cout << B << '\n';
        else cout << max(A, B) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}