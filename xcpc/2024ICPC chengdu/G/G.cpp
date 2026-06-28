#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n; cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> p;
    
    auto calc = [&] (int x, int y) {
        p.push_back(x);
        p.push_back(y);
        p.push_back(x ^ y);
        p.push_back(x & y);
        p.push_back(x | y);
        p.push_back(x & (x ^ y));
        p.push_back(y & (x ^ y));
    };

    p.push_back(0);
    for (int i = 0; i + 1 < n; i++) {
        calc(a[i], a[i + 1]);
    }

    sort(p.begin(), p.end());
    cout << unique(p.begin(), p.end()) - p.begin() << '\n';
    return 0;
}