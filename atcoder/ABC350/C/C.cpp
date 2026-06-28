#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> ans;
int main() {
    int n; cin >> n;
    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == i) continue;
        int pos = p[i];
        swap(a[pos], a[i]);
        ans.push_back({pos, i});
        p[a[pos]] = pos;
        p[a[i]] = i;
    }
    cout << ans.size() << endl;
    for (auto &x : ans) {
        if (x.first > x.second) 
            swap(x.first, x.second);
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}