#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N,K; cin >> N >> K;
    vector<int> A(N + 1, 0), B(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];

    if (A == B) {cout << "Yes\n"; return;}
    if (K == 1) {
        vector<int> A_, B_;
        for (int i = 1; i <= N; i++) {
            if (A_.empty() || A_.back() != A[i]) A_.push_back(A[i]);
            if (B_.empty() || B_.back() != B[i]) B_.push_back(B[i]);
        }

        int j = 0;
        for (int i = 0; i < A_.size(); i++) {
            if (A_[i] == B_[j]) j += 1;
            if (j == B_.size()) break;
        }
        if (j == B_.size()) cout << "Yes\n";
        else cout << "No\n";
    }
    else {
        vector<int> cnt(N + 1, 0);
        for (int i = 1; i <= N; i++) cnt[A[i]] = 1;
        for (int i = 1; i <= N; i++) 
            if (cnt[B[i]] == 0) {cout << "No\n"; return;}
        
        vector<vector<int>> pos(N + 1);
        for (int i = 1; i <= N; i++) pos[B[i]].push_back(i);
        int ok = 0;
        for (auto v : pos) {
            if (ok) break;
            for (int i = 0; i + 1 < v.size(); i++) {
                ok |= (v[i + 1] - v[i] <= K);
            }
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    freopen ("D.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}