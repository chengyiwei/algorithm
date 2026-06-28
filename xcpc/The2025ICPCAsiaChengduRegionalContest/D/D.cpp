#include <bits/stdc++.h>
using namespace std;

typedef array<int, 5> info;

map<info, int> vis;
map<info, info> pre;
map<info, int> g;

int main() {
    // freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    info start = {0, 0, 21, 0, 0};
    queue<info> q; q.push(start); vis[start] = 1;
    while (!q.empty()) {
        auto [scoreA, scoreB, rem_balls, op, redok] = q.front(); q.pop();
        // cout << scoreA << ' ' << scoreB << ' ' << rem_balls << ' ' << op << ' ' << redok << '\n';

        if (rem_balls == 0) continue;

        // 击球失败
        info nxt_state = {scoreA, scoreB, rem_balls, op ^ 1, 0};
        if (!vis.count(nxt_state)) {
            vis[nxt_state] = 1;
            q.push(nxt_state);
            pre[nxt_state] = {scoreA, scoreB, rem_balls, op, redok};
            g[nxt_state] = 0;
        }

        // 打红球
        if (redok == 0 && rem_balls > 6) {
            nxt_state = {scoreA + (op == 0), scoreB + (op == 1), rem_balls - 1, op, 1};
            if (!vis.count(nxt_state)) {
                vis[nxt_state] = 1;
                q.push(nxt_state);
                pre[nxt_state] = {scoreA, scoreB, rem_balls, op, redok};
                g[nxt_state] = 1;
            }
        } 

        //  打完之后打彩球
        if (redok == 1) {
            for (int c = 2; c <= 7; c++) {
                nxt_state = {scoreA + (op == 0) * c, scoreB + (op == 1) * c, rem_balls, op, 0};
                if (!vis.count(nxt_state)) {
                    vis[nxt_state] = 1;
                    q.push(nxt_state);
                    pre[nxt_state] = {scoreA, scoreB, rem_balls, op, redok};
                    g[nxt_state] = c;
                }
            }
        }

        // 打完红球之后只剩下彩球
        if (rem_balls <= 6 && redok == 0) {
            int c = 8 - rem_balls;
            nxt_state = {scoreA + (op == 0) * c, scoreB + (op == 1) * c, rem_balls - 1, op, 0};
            if (!vis.count(nxt_state)) {
                vis[nxt_state] = 1;
                q.push(nxt_state);
                pre[nxt_state] = {scoreA, scoreB, rem_balls, op, redok};
                g[nxt_state] = c;
            }
        }
    }

    int T; cin >> T;
    while (T--) {
        int scoreA, scoreB, rem, op; cin >> scoreA >> scoreB >> rem >> op;
        if (!vis.count({scoreA, scoreB, rem, op, 0}) && !vis.count({scoreA, scoreB, rem, op, 1})) {
            cout << "NA\n";
            continue;
        }
        else {
            info cur;
            if (vis.count({scoreA, scoreB, rem, op, 0})) cur = {scoreA, scoreB, rem, op, 0};
            else cur = {scoreA, scoreB, rem, op, 1};
            vector<int> ans;
            while (cur != start) {
                ans.push_back(g[cur]);
                cur = pre[cur];
            }
            reverse(ans.begin(), ans.end());
            for (int x : ans) {
                if (x == 0) cout << '/';
                else cout << x;
            }
            cout << '\n';
        }
    }
    return 0;
}