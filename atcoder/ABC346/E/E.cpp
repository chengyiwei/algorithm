#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> pii;
signed main() {
    freopen ("E.in","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int H, W, N; cin >> H >> W >> N;
    vector<int> A(N + H), X(N + H), T(N + H); 
    N = N + H;
    for (int i = 0; i < H; i++) {
        T[i] = 1; A[i] = i + 1; X[i] = 0;
    }
    for (int i = H; i < N; i++)
        cin >> T[i] >> A[i] >> X[i];
    map<int,pii> col, row;
    for (int i = N - 1; i>= 0; i--) {
        if (T[i] == 1) {
            if (row.count(A[i])) continue;
            row[A[i]] = {W - col.size(), X[i]};
        }
        else {
            if (col.count(A[i])) continue;
            col[A[i]] = {H - row.size(), X[i]};
        }
    }
    map<int,int> mp;
    for (auto &r : row) {
        int num = r.second.first, c = r.second.second;
        if (!mp.count(c))
            mp[c] = 0;
        mp[c] += num; 
    }
    for (auto &r : col) {
        int num = r.second.first, c = r.second.second;
        if (!mp.count(c))
            mp[c] = 0;
        mp[c] += num; 
    }

    int ans = 0;
    for (auto &x : mp) 
        ans += x.second != 0;
    cout << ans << '\n';
    for (auto &x : mp) {
        if (x.second == 0) continue;
        cout << x.first << " " << x.second << '\n';
    }
    return 0;
}