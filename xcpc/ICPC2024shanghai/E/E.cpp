#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s; string T = "shanghai";
    vector<int> cnt(26, 0);
    for (auto &c : s) {
        if ('A' <= c && c <= 'Z') c = c - 'A' + 'a';
        cnt[c - 'a'] += 1;
    }
    int min_x = 1e9;
    for (auto &c : T) {
        int x = cnt[c - 'a'];
        if (c == 'h' || c == 'a') x /= 2;
        min_x = min(min_x, x);
    }
    cout << min_x << endl;
    return 0;
}
