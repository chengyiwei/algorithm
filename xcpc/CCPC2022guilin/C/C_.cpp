#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> p(n);
    for (int i = 1; i <= n; i++) p[i - 1] = i;
    
    while (m --) {
        vector<int> p_;
        for (int i = p.size() - 1; i >= 0; i--)
            p_.push_back(p[i]);
        for (int i = 0; i < p.size(); i++)
            p_.push_back(p[i]);
        p = p_;
    }
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < p.size(); i++) {
        cnt[p[i]] += i + 1;
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << ' ';
    }
}