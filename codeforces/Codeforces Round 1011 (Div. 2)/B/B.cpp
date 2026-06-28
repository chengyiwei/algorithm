#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    map<int, int> mp;

    auto Mex = [&] (vector<int> &A) {
        mp.clear();
        for (int i = 0; i < A.size(); i++)
            mp[A[i]] += 1;
        for (int i = 0; i > -1 ; i++)
            if (mp[i] == 0) return i;
        return 0;
    };


    vector<pair<int, int>> ans;
    
    auto print = [&] () {
        assert(N == 1 and A[1] == 0);
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
    };

    auto check = [&] (int l, int r) {
        ans.push_back({l, r});
        vector<int> b;
        for (int i = l; i <= r; i++)
            b.push_back(A[i]);
        int m = Mex(b);
        A[l] = m;
        for (int i = l + 1; i + 1 <= N; i++)
            A[i] = A[i + 1];
        for (int i = N - (r - l) + 1; i <= N; i++)
            A[i] = 0;
        N -= (r - l);
    };

    if (*max_element(A.begin(), A.end()) == 0) {
        check(1, 2);
        check(2, N);
        check(1, N);
        print();
        return;
    }

    while (N >= 2) {
        int flg = 0;
        for (int i = 1; i <= N; i++) {
            if (A[i] == 0) {
                if (i != N) {
                    check(i, i + 1);
                    flg = 1;
                    break;
                }
                else {
                    check(i - 1, i);
                    flg = 1;
                    break;
                }
            }
        }
        if (!flg)
            check(1, N);
    }

    print();
}


int main() {
    freopen ("B.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) solve();
}