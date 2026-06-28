#include <bits/stdc++.h>
using namespace std;

void solve (){
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    if (s1 == s2) {
        cout << "YES" << '\n';
        return;
    }
    int fst1 = n, fst2 = n;
    for (int i = 0; i < n; i++) {
        if (s1[i] == '1' && fst1 == n) fst1 = i;
        if (s2[i] == '1' && fst2 == n) fst2 = i;
    }
    if (fst1 <= fst2) {
        cout << "YES" << '\n';
        return;
    }
    cout << "NO" << '\n';
}

int main() {
    freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}