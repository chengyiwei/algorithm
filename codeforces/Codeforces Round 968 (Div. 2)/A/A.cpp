#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (s.front() == s.back())
        cout << "No" << '\n';
    else 
        cout << "Yes" << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}