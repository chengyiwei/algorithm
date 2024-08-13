#include <bits/stdc++.h>
using namespace std;

const int flg[3][3] = {{-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};
const int inf = 0x3f3f3f3f;
struct Dinic {
    struct Edge {
        int from, to, cap, flow;
    };
    int n, m, s, t;
    vector<Edge> edges;
    vector<vector<int>> g;
    vector<int> d, cur;

    void init (int n_) {
        n = n_;
        edges.clear();
        d.assign(n, 0);
        g.assign(n, vector<int>());
    }

    void add_e (int from, int to, int cap) {
        // cout << from << " " << to << " " << cap << endl;
        edges.push_back({from, to, cap, 0});
        edges.push_back({to, from, 0, 0});
        m = edges.size();
        g[from].push_back(m - 2);
        g[to].push_back(m - 1);
    }

    bool bfs () {
        vector<int> vis(n, 0);
        queue<int> q; q.push(s); d[s] = 0; vis[s] = 1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (auto i : g[x]) {
                Edge &e = edges[i];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int dfs (int x, int a) {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < g[x].size(); i++) {
            Edge &e = edges[g[x][i]];
            if (d[x] + 1 == d[e.to] && (f = dfs(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[g[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    int max_flow (int s_, int t_) {
        s = s_, t = t_;
        int flow = 0;
        while (bfs()) {
            cur.assign(n, 0);
            flow += dfs(s, inf);
        }
        return flow;
    }
};

int main() {
    // freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M, L; cin >> N >> M >> L;
    vector mp(N, vector (M, vector<char>(L, 0)));
    vector w(N, vector(M, vector<int>(L, 0)));
    for (int k = 0; k < L; k++) 
    for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++) 
        cin >> mp[i][j][k];
    
    for (int k = 0; k < L; k++) 
    for (int i = 0; i < N; i++) 
    for (int j = 0; j < M; j++) 
        cin >> w[i][j][k];

    Dinic dinic; dinic.init(N * M * L + 2);
    int S = N * M * L, T = N * M * L + 1;

    auto id = [&](int i, int j, int k) {
        return i * M * L + j * L + k;
    };

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < L; k++) {
                if (mp[i][j][k] == 'B')
                    dinic.add_e(S, id (i, j, k), w[i][j][k]);
                else 
                    dinic.add_e(id(i, j, k), T, w[i][j][k]);
                for (int p = 0; p < 3; p++) {
                    int x = i + flg[p][0], y = j + flg[p][1], z = k + flg[p][2];
                    if (x < 0 || x >= N || y < 0 || y >= M || z < 0 || z >= L) continue;
                    dinic.add_e(id(i, j, k), id(x, y, z), inf);
                }
            }
    dinic.add_e(S, 0, inf); dinic.add_e(id(N - 1, M - 1, L - 1), T, inf); // 0 号点必须是黑色，NML-1 号点必须是白色
    auto ans = dinic.max_flow(S, T);
    cout << ans << endl;
    return 0;
}