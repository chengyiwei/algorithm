#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen ("A.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int N, K; cin >> N >> K;
        string S; cin >> S;
        map<char, int> mp;
        for (int i = 0; i < N; i++)
            mp[S[i]]++;
        if (mp.size() == 1) {
            cout << "NO\n";
            continue;
        }
        if (K == 0) {
            string S_ = S;
            reverse(S_.begin(), S_.end());
            if (S < S_) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }

    return 0;
}