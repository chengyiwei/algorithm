#include <bits/stdc++.h>
using namespace std;
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
    
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        if (cnt[a[i]] == 0) {
            stk.push(a[i]);
            cnt[a[i]] = 1;
        }
        else {
            if (stk.empty() || stk.top() < a[i]) {
                cout << "NO\n"; return 0;
            }
            while (!stk.empty() && stk.top() != a[i]) {
                if (stk.top() > a[i])
                    stk.pop();
                else 
                    {cout << "NO\n"; return 0;}
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n";
    return 0;
}