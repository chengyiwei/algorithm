#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<string> p = {"pie", "map","mapie"};
    vector<int> num(3,0);
    for (int i = 0; i < 3; i++) {
        string now = p[i];
        for (int j = 0; j + now.size() - 1 < s.size(); j++) {
            if (s.substr(j, now.size()) == now)
                num[i] ++;
        }
    }
    cout << num[0] + num[1] - num[2] << '\n';
}
int main() {
    freopen ("C.in", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
}