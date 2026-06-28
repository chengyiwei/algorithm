#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        if (s.find(1) == s.end())
            cout << 1000000007 << '\n';
        else 
            cout << -1 << '\n';
    }
}