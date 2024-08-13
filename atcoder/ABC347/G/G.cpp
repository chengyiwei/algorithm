#include <bits/stdc++.h>
#include <atcoder/maxflow>
using namespace std;

const int inf = 0x3f3f3f3f;

int main() {
    freopen ("G.in", "r", stdin);
    int n; cin >> n;
    atcoder::mf_graph<int> g(1 + 4 * n * n + 1);
    const int S = 0, T = 1 + 4 * n * n;
    const auto id = [&] (int x, int y, int v) {
        return (x * n + y) * 4 + v;
    };
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int v = 1; v + 1 <= 4; v++) 
                g.add_edge(id(i, j, v + 1), id(i, j, v), inf);
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j + 1 < n; j++)
            for (int v = 1; v <= 4; v++) {
                g.add_edge(id(i, j, v), id(i, j + 1, v), 1);
                g.add_edge(id(i, j + 1, v), id(i, j, v), 1);
                for (int u = 1; u < v; u++) {
                    g.add_edge(id(i, j, v), id(i, j + 1, u), 2);
                    g.add_edge(id(i, j + 1, v), id(i, j, u), 2);
                }
            }
    
    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j < n; j++)
            for (int v = 1; v <= 4; v++) {
                g.add_edge(id(i, j, v), id(i + 1, j, v), 1);
                g.add_edge(id(i + 1, j, v), id(i, j, v), 1);
                for (int u = 1; u < v; u++) {
                    g.add_edge(id(i, j, v), id(i + 1, j, u), 2);
                    g.add_edge(id(i + 1, j, v), id(i, j, u), 2);
                }
            }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            if (x == 0) continue;
            if (x < 5)
                g.add_edge(id(i, j, x), T, inf);
            if (x > 1) 
                g.add_edge(S, id(i, j, x - 1), inf);
        }
    
    g.flow(S, T);
    const auto &cut = g.min_cut(S);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = 1;
            for (int v = 1; v <= 4; v++)
                x += cut[id(i, j, v)];
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}