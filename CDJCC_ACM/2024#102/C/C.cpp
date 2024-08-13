#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    map<int, vector<int>> mp;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        mp[A[i]].push_back(i);
    }
    while (Q--) {
        int x, k; cin >> x >> k;
        if (mp.find(x) == mp.end() || mp[x].size() < k) {
            cout << -1 << endl;
        }
        else {
            cout << mp[x][k - 1] << endl;
        }
    }
    return 0;
}