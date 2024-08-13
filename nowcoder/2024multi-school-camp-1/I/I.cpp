#include <bits/stdc++.h>
using namespace std;

const int flg[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
typedef pair<int, int> pii;


int main() {
    freopen ("I.in", "r", stdin);
    ios::sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> mp(n + 2, vector<char>(m + 2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mp[i][j];
    
    int N = (n + 2) * (m + 2) * 4;

    vector<pii> nxt(N + 1, {-1, -1});
    vector<int> du(N + 1);

    auto get_id = [&] (int i, int j, int k) {
        return i * (m + 1) * 4 + j * 4 + k;
    };
    
    auto add_e = [&] (int u, int v, int w) {
        // cout << u << " " << v << " " << w << endl;
        nxt[u] = pii(v, w);
        du[v] += 1;
    };

    auto get_pos = [&] (int id) {
        int k = id % 4; id /= 4;
        int j = id % (m + 1); id /= (m + 1);
        int i = id;
        return pii(i, j);
    };

    auto check = [&] (int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '|') {
                for (int k = 0; k < 4; k++) {
                    if (k == 0 || k == 2) {
                        int nk = k ^ 2, nx = i + flg[nk][0], ny = j + flg[nk][1];
                        // if (!check(nx, ny)) continue;
                        add_e(get_id(i, j, k), get_id(nx, ny, nk ^ 2), 0);
                    } else {
                        int nk = k, nx = i + flg[nk][0], ny = j + flg[nk][1];
                        // if (!check(nx, ny)) continue;
                        add_e(get_id(i, j, k), get_id(nx, ny, nk ^ 2), 1);
                    }
                }
            }
            else if (mp[i][j] == '-') {
                for (int k = 0; k < 4; k++) {
                    if (k == 1 || k == 3) {
                        int nk = k ^ 2, nx = i + flg[nk][0], ny = j + flg[nk][1];
                        // if (!check(nx, ny)) continue;
                        add_e(get_id(i, j, k), get_id(nx, ny, nk ^ 2), 0);
                    } else {
                        int nk = k, nx = i + flg[nk][0], ny = j + flg[nk][1];
                        // if (!check(nx, ny)) continue;
                        add_e(get_id(i, j, k), get_id(nx, ny, nk ^ 2), 1);
                    }
                }
            }
            else if (mp[i][j] == '\\') {
                for (int k = 0; k < 4; k++) {
                    int nk = k ^ 1;
                    int nx = i + flg[nk][0], ny = j + flg[nk][1];
                    // if (!check(nx, ny)) continue;
                    add_e(get_id(i, j, k), get_id(nx, ny, nk ^ 2), 1);
                }
            }
            else if (mp[i][j] == '/') {
                for (int k = 0; k < 4; k++) {
                    int nk = k ^ 3;
                    int nx = i + flg[nk][0], ny = j + flg[nk][1];
                    // if (!check(nx, ny)) continue;
                    add_e(get_id(i, j, k), get_id(nx, ny, nk ^ 2), 1);
                }
            }
        }

    vector<int> dis(N + 1, -1);
    stack<int> stk;
    map<pii, int> cnt;
    
    auto dfs = [&] (auto &&dfs, int u) {
        cout << u << '\n';
        int v = nxt[u].first, w = nxt[u].second;
        if (v == -1) {
            dis[u] = 0;
            return;
        }
        dfs(dfs, v);
        if (w == 1) {
            auto [x, y] = get_pos(u);
            cnt[{x, y}] = 1;
        }
        dis[u] = cnt.size();
        du[u] = 0;
        return ;
    };

    for (int i = 1; i <= N; i++) {
        if (du[i] == 0 && dis[i] == -1) {
            cnt.clear();
            dfs(dfs, i);
        }
    }

    for (int i = 0; i < N; i++) {
        if (du[i]) {
            if (dis[i] != -1) continue;
            cnt.clear();
            int p = i;  dis[i] = 1; stk.push(i);
            int now_dis = -1;
            do {
                int q = nxt[p].first, w = nxt[p].second;
                if (w != 0) {
                    auto [x, y] = get_pos(p);
                    cnt[{x, y}] = 1;
                }
                if (dis[q] == -1) {
                    dis[q] = dis[p] + w;
                    stk.push(q);
                    p = q;
                }
                else {
                    now_dis = cnt.size();
                    while (!stk.empty()) {
                        int x = stk.top(); stk.pop();
                        dis[x] = now_dis;
                    }
                    break;
                }
            } while (1);
        }
    }


    int Q; cin >> Q;

    while (Q--) {
        string s; 
        int x, y, k; cin >> x >> y >> s;
        if (s == "above") k = 0;
        else if (s == "right") k = 1;
        else if (s == "below") k = 2;
        else if (s == "left") k = 3;

        int nk = k, nx = x + flg[nk][0], ny = y + flg[nk][1];
        if (!check(nx, ny)) cout << 0 << endl;
        else {
            int id = get_id(nx, ny, nk ^ 2);
            cout << max(dis[id], 0) << endl;
        }
    }

    return 0;
}