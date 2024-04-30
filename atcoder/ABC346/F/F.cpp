#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1ll << 60;

int main() {
    ll n;
    string S, T;
    cin >> n >> S >> T;
    int s = S.size(), t = T.size();
    vector<vector<int> > pos(26);
    for (int i = 0; i < s * 2; i++) 
        pos[S[i % s] - 'a'].push_back(i);
    vector<vector<int> >  pre(s + 1, vector<int>(26));
    for (int i = 0; i < s; i++) {
        pre[i + 1] = pre[i];
        pre[i + 1][S[i] - 'a']++;
    }
    vector<int> cnt(26, 0);
    for (int i = 0; i < s; i++)
        cnt[S[i] - 'a']++;
    ll le = 0, ri = INF;
    auto check = [&] (ll x) -> bool {
        ll iter = 0; // 表示s的长度
        for (int i = 0; i < t; i++) {
            int c = T[i] - 'a';
            if (cnt[c] == 0) return false;
            ll r = (x - 1) % cnt[c] + 1;
            ll q = (x - r) / cnt[c];
            if (q > INF / s) return false;
            iter += q * s;
            int nx = pos[c][pre[iter % s][c] + r - 1]; // 从iter % s开始的第 r 个 c 的位置
            iter += nx - iter % s + 1;
            if (iter > n * s) return false;
        }
        return true;
    };

    while (le + 1 < ri) {
        ll mid = (le + ri) >> 1;
        if (check(mid)) le = mid;
        else ri = mid;
    }
    cout << le << endl;
    return 0;
}