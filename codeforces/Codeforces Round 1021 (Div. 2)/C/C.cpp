#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    int pre_pos = -2333, num = 0;
    for (auto it = mp.begin(); it != mp.end(); ++ it) {
        int pos = it->first, val = it->second;
        if (val >= 4) {
            return 1;
        }   
        if (pre_pos == pos - 1) {
            if (val >= 2) {
                if (num >= 1) 
                    return 1;
                else
                    num = 1;
            }
        }
        else {
            if (val >= 2)
                num = 1;
            else 
                num = 0;
        }
        pre_pos = pos;
    }
    return 0;
}

int main() {
    // freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
    return 0;
}