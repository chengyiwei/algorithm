#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, K; cin >> N >> K;
    string S; cin >> S;
    int cnt = 0;

    map<string, int> mp;

    auto check = [&] (string S) {
        for (int L = 0; L + K - 1 < N; L++) {
            string T = S.substr(L, K);
            if (T == string(T.rbegin(), T.rend())) return 0;
        }
        return 1;
    };
    
    vector<int> id(N);
    iota(id.begin(), id.end(), 0);
    
    int num = 0;

    do {
        string S_ = S;
        for (int i = 0; i < N; i++) S_[i] = S[id[i]];
        if (mp.count(S_)) continue;
        else mp[S_] = 1;
        if (check (S_)) cnt += 1;
        num += 1;
    } while (next_permutation(id.begin(), id.end()));
    cout << cnt << endl;
    return 0;
}