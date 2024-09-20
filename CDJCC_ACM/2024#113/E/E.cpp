#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("E.in", "r", stdin);
    int T; cin >> T;
    while (T--) {
        int L, R; cin >> L >> R;
        vector<int> v;
        v.push_back(L);
        for (int i = L + 1; i <= R;) {
            v.push_back(i);
            int n = v.size(), d = v[n - 1] - v[n - 2];
            i = v[n - 1] + d + 1;
        }
        cout << v.size() << endl;
    }
}