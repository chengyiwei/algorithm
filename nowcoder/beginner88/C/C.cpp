#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> t (n + 1), p;
    for (int i = 1; i <= n; i++) {
        int h, m; cin >> h >> m;
        t[i] = h * 60 + m;
        p.push_back(t[i] - 1),
        p.push_back(t[i] - 3);
        p.push_back(t[i] - 5);
    }
    sort (p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    for (auto x : p) {
        int h = x / 60, m = x % 60;
        cout << h << " " << m << '\n';
    }
    return 0;
}