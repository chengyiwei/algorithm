#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> sg(505, 0);
    
    auto mex = [&](const vector<int> &v) {
        set<int> s(v.begin(), v.end());
        for (int i = 0; ; i++) {
            if (!s.count(i)) return i;
        }
    };

    sg[0] = 0; sg[1] = 0;
    for (int i = 2; i <= 500; i++) {
        vector<int> v;
        for (int j = 0; j <= i - 2; j++) {
            v.push_back(sg[j] ^ sg[i - 2 - j]);
        }
        sg[i] = mex(v);
    }

    auto SG = [&] (int x) {
        if (x == 0) return 0;
        int t = (x - 100) / 34;
        t = max(t, 0);
        return sg[x - t * 34];
    };

    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<pair<int, int>> a(m);
        vector<int> hsh1(m), hsh2(m);
        map<int, int> mp;
        for (int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            a[i] = {x, y};
            hsh1[i] = rand() * rand();
            hsh2[i] = rand() * rand();
            mp[x] = i; mp[y] = i;
        }
        
        int lst = -1, g1 = 0, g2 = 0;
        map<pair<int, int>, int> cnt;
        for (auto [x, id] : mp) {
            cnt[{g1, g2}] += x - lst - 1;
            g1 ^= hsh1[id];
            g2 ^= hsh2[id];
            lst = x;
        }
        cnt[{g1, g2}] += n - lst - 1;

        int res = 0;
        for (auto [_, v] : cnt) {
            res ^= SG(v);
        }
        if (res) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}