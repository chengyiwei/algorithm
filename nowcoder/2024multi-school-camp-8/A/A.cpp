#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int M = *max_element(A.begin(), A.end());
    vector<int> cnt(M + 1, 0);
    for (auto &a : A) cnt[a] = 1;
    vector<ll> p(M + 1, 0);
    for (int i = 1; i <= M; i += 1) {
        int now = 0;
        for (int j = i; j <= M; j += i) now += cnt[j];
        p[i] = 1LL * now * (now - 1) / 2;
    }
    for (int i = M; i >= 1; i -= 1) {
        for (int j = i + i; j <= M; j += i) p[i] -= p[j];
    }
    int num = 0;
    for (int i = 1; i <= M; i ++) {
        if (cnt[i] == 0 && p[i] > 0) {
            cout << i << ' ';
            num += 1;
        }
    }
    if (num & 1)
        cout << "dXqwq" << '\n';
    else 
        cout << "Haitang" << '\n';
}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}