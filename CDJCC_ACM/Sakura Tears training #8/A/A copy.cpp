#include <bits/stdc++.h>
using namespace std;

struct Node {
    int pos, op, val;
    bool operator < (const Node &rhs) const {
        return pos < rhs.pos || (pos == rhs.pos && op > rhs.op);
    }
};

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mx_ = *max_element(a.begin() + 1, a.end());
    if (mx_ != m) {
        bool ok = 0;
        for (int i = 1; i <= n; i++) if (a[i] == 0) {
            ok = 1; a[i] = m; break;
        }
        if (!ok) {
            cout << "NO\n"; return 0;
        }
    }
    for (int i = 1; i <= n; i++) 
        if (a[i] != 0) {
            a[0] = a[i]; break;
        }
    for (int i = 1; i <= n; i++) 
        if (a[i] == 0) a[i] = a[i - 1];
    
    vector<int> cnt(m + 1, 0);
    vector<Node> p;
    for (int i = 1; i <= n; i++) 
        if (cnt[a[i]] == 0) {
            p.push_back({i, 1, a[i]});
            cnt[a[i]] = 1;
        }
    
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = n; i >= 1; i--) 
        if (cnt[a[i]] == 0) {
            p.push_back({i, -1, a[i]});
            cnt[a[i]] = 1;
        }
    
    sort(p.begin(), p.end());
    stack<int> stk;
    for (auto [pos, op, val] : p) {
        if (op == 1) {
            stk.push(val);
        }
        else {
            if (stk.top() < val) {
                cout << "NO\n"; return 0;
            }
            while (stk.top() != val) {
                if (stk.top() > val) { stk.pop(); }
                else { cout << "NO\n"; return 0; }
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
    return 0;
}