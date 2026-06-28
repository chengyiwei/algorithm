#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        string S, T; cin >> S >> T;
        int same = 0;
        for (int i = 0; i < min(S.size(), T.size()); i++) {
            if (S[i] == T[i]) same += 1;
            else break;
        }
        if (same)
            cout << S.size() + T.size() - same + 1 << '\n';
        else 
            cout << S.size() + T.size() << '\n';
    }
    return 0;
}