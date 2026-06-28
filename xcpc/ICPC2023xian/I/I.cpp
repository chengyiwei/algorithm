#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("I.out","w",stdout);
    int n = 10000;
    int x = 1000;
    vector<int> dis(n + 1, -1);
    vector<int> pre(n + 1, -1);
    queue<int> q; q.push(x); dis[x] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        auto insert = [&] (int x) {
            if (x < 1 || x > n) return ;
            if (dis[x] != -1) return ;
            dis[x] = dis[u] + 1;
            pre[x] = u; 
            q.push(x);
        };

        insert(u - 1); 
        insert(u + (int)(sqrt(2.0 * u) + 1.5));
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " " << pre[i] << endl;
    return 0;
}
