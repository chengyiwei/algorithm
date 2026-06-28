#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;

int cmp(double x, double y) {
    if (fabs(x - y) < eps) return 0;
    return x < y ? -1 : 1; // x < y 返回 -1, x > y 返回 1
}


set<pair<double, string> > mp;

int main() {
    // freopen ("J.in", "r",stdin);
    double a, b;
    cin >> a >> b;
    queue<double> q; q.push(a);
    mp.insert({a, ""});

    while (!q.empty()) {
        double u = q.front(); q.pop();
        
        auto it = mp.lower_bound({u,""});
        double v = it->first; string s = it->second;

        auto insert = [&] (double nxt_u, string s) {
            if (nxt_u < 0 || nxt_u > 1) return;

            if (cmp(nxt_u, b) == 0) {
                if (s.size() > 50)
                    s = s.substr(0, 50);
                cout << s << endl;
                exit(0);
            }
            
            double v = mp.lower_bound({nxt_u, ""})->first;
            if (cmp(v, nxt_u) == 0) return; // 存在
            mp.insert({nxt_u, s});
            q.push(nxt_u);
        };

        insert(u * 0.5 , s + "1"); 
        insert((u - 1.0) * 0.5 + 1, s + "2");
    }
    return 0;
}
