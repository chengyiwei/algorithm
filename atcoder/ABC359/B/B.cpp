#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<vector<int> > p(N,vector<int>());
    for (int i = 1; i <= 2 * N; i++) {
        int col; cin >> col;
        p[col-1].push_back(i);
    }
    int cnt = 0;
    for (auto v : p) {
        if (abs(v[0] - v[1]) == 2)
            cnt += 1;
    }
    cout << cnt << endl;
    return 0;
}