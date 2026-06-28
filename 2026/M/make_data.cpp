#include <bits/stdc++.h>
using namespace std;

/*
    这个程序会随机生成二分图，寻找能 hack 掉如下错误做法的数据：
    - 先求一个最大匹配 baseMatchR
    - 枚举某个左点 x
    - 从这个固定的 baseMatchR 出发，对 x 连续做两次增广
    - 取最大值

    真正答案用最大流精确计算：
    - 枚举哪只左点 x 使用“分身机器”
    - source -> 左点容量：x 为 3，其余为 1
    - 左点 -> 右点容量：1（有边则连）
    - 右点 -> sink 容量：1
    - 最大流即该 x 下答案
*/

static mt19937 rng((unsigned)chrono::steady_clock::now().time_since_epoch().count());

struct Dinic {
    struct Edge {
        int to, cap, rev;
    };
    int n;
    vector<vector<Edge>> g;
    vector<int> level, it;

    Dinic(int n = 0) { init(n); }

    void init(int n_) {
        n = n_;
        g.assign(n, {});
        level.resize(n);
        it.resize(n);
    }

    void addEdge(int fr, int to, int cap) {
        Edge a{to, cap, (int)g[to].size()};
        Edge b{fr, 0,   (int)g[fr].size()};
        g[fr].push_back(a);
        g[to].push_back(b);
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto &e : g[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int &i = it[v]; i < (int)g[v].size(); i++) {
            Edge &e = g[v][i];
            if (e.cap > 0 && level[v] + 1 == level[e.to]) {
                int ret = dfs(e.to, t, min(f, e.cap));
                if (ret > 0) {
                    e.cap -= ret;
                    g[e.to][e.rev].cap += ret;
                    return ret;
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t) {
        int flow = 0, inf = 1e9;
        while (bfs(s, t)) {
            fill(it.begin(), it.end(), 0);
            while (int f = dfs(s, t, inf)) flow += f;
        }
        return flow;
    }
};

struct Instance {
    int n, m;
    vector<vector<int>> g;   // 左部 1..n, 右部 1..m
    vector<pair<int,int>> edges;
};

bool dfs_augment_bad(int u, const vector<vector<int>>& g, vector<int>& matchR, vector<int>& vis) {
    for (int v : g[u]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (!matchR[v] || dfs_augment_bad(matchR[v], g, matchR, vis)) {
            matchR[v] = u;
            return true;
        }
    }
    return false;
}

int base_matching_bad(int n, int m, const vector<vector<int>>& g, vector<int>& matchR) {
    matchR.assign(m + 1, 0);
    int res = 0;
    for (int u = 1; u <= n; u++) {
        vector<int> vis(m + 1, 0);
        if (dfs_augment_bad(u, g, matchR, vis)) res++;
    }
    return res;
}

// 你贴的错误做法
int solve_bad(int n, int m, const vector<vector<int>>& g) {
    vector<int> baseMatchR;
    int base = base_matching_bad(n, m, g, baseMatchR);
    int mx = min(m, n + 2);

    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        if (g[a].size() != g[b].size()) return g[a].size() > g[b].size();
        return a < b;
    });

    int K = n;
    int ans = base;

    for (int i = 0; i < K; i++) {
        int x = ord[i];
        vector<int> matchR = baseMatchR;
        int cur = base;

        for (int rep = 0; rep < 2; rep++) {
            vector<int> vis(m + 1, 0);
            if (dfs_augment_bad(x, g, matchR, vis)) cur++;
        }

        ans = max(ans, cur);
    }

    return min(ans, mx);
}

// 精确解：枚举哪个左点容量为 3，其余左点容量为 1，右点容量全为 1
int solve_exact(int n, int m, const vector<vector<int>>& g) {
    int ans = 0;

    for (int special = 0; special <= n; special++) {
        // special = 0 表示谁都不用机器
        int S = 0;
        int L = 1;
        int R = L + n;
        int T = R + m;
        Dinic dinic(T + 1);

        for (int u = 1; u <= n; u++) {
            int cap = 1;
            if (u == special) cap = 3;
            dinic.addEdge(S, L + u - 1, cap);
        }

        for (int u = 1; u <= n; u++) {
            for (int v : g[u]) {
                dinic.addEdge(L + u - 1, R + v - 1, 1);
            }
        }

        for (int v = 1; v <= m; v++) {
            dinic.addEdge(R + v - 1, T, 1);
        }

        ans = max(ans, dinic.maxflow(S, T));
    }

    return ans;
}

Instance gen_random_instance(int n, int m, double p) {
    Instance ins;
    ins.n = n;
    ins.m = m;
    ins.g.assign(n + 1, {});
    ins.edges.clear();

    for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= m; v++) {
            double x = (double)uniform_real_distribution<double>(0.0, 1.0)(rng);
            if (x < p) {
                ins.g[u].push_back(v);
                ins.edges.push_back({u, v});
            }
        }
    }

    // 去重并排序（虽然这里不会重）
    for (int u = 1; u <= n; u++) {
        sort(ins.g[u].begin(), ins.g[u].end());
        ins.g[u].erase(unique(ins.g[u].begin(), ins.g[u].end()), ins.g[u].end());
    }

    return ins;
}

void print_instance(const Instance& ins) {
    cout << ins.n << " " << ins.m << " " << ins.edges.size() << "\n";
    for (auto &e : ins.edges) {
        cout << e.first << " " << e.second << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 你可以把这里的范围再调大一点
    // 一般小图就很容易出锅
    for (int round = 1; ; round++) {
        int n = uniform_int_distribution<int>(2, 8)(rng);
        int m = uniform_int_distribution<int>(2, 8)(rng);

        // 稍微偏稠密一点，更容易出现“固定某个 base matching 会坏掉”的情况
        double p = uniform_real_distribution<double>(0.20, 0.75)(rng);

        Instance ins = gen_random_instance(n, m, p);

        if (ins.edges.empty()) continue;

        int bad = solve_bad(ins.n, ins.m, ins.g);
        int exact = solve_exact(ins.n, ins.m, ins.g);

        if (bad != exact) {
            cerr << "Found counterexample after " << round << " rounds.\n";
            cerr << "bad = " << bad << ", exact = " << exact << "\n";
            print_instance(ins);
            return 0;
        }
    }
}