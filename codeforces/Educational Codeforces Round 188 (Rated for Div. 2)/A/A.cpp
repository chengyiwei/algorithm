#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int cnt = 1;
        for (auto c : s) {
            if (c == 'R') cnt += 1;
            else break;
        }
        cout << cnt << '\n';
    }
    return 0;
}