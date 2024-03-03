#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long LL;


struct Hash {
    int p, mod;
    Hash(int p, int mod) : p(p), mod(mod) {}

    LL pow(LL a, LL b) {
        LL ans = 1;
        for (; b; b >>= 1, a = a * a % mod) if (b & 1) ans = ans * a % mod;
        return ans;
    }

    vector<LL> get_hash(string &s) {
        int n = s.size();
        vector<LL> h(n + 1, 0);
        h[0] = s[0] - 'a' + 1;
        for (int i = 1; i < n; i++) {
            h[i] = (h[i - 1] * p + s[i] - 'a' + 1) % mod;
        }
        return h;
    }

    LL get_sub_hash(vector<LL> &h, int l, int r) {
        if (l == 0) return h[r];
        return (h[r] - h[l - 1] * pow(p, r - l + 1) % mod + mod) % mod;
    }
};

int main() {
    freopen("G.in","r",stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    Hash hsh1(37, 1e9 + 7);
    vector<string> s(n + 1);
    vector<vector<LL> > h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i], h[i] = hsh1.get_hash(s[i]);
    
    vector<vector<int> > p(n + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= n; i++)  // s[i] 在前 s[j] 在后
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;

            int flg = 0;
            if (s[i].size() >= s[j].size()) {
                for (int k = 0; k + s[j].size() - 1 < s[i].size(); k++ )
                    if (hsh1.get_sub_hash(h[i], k, k + s[j].size() - 1) == h[j][s[j].size() - 1]) {
                        p[i][j] = s[j].size();
                        flg = 1;
                        break;
                    }
            }
            if (flg) continue;

            int cnt;
            for (cnt = min(s[i].size(), s[j].size()) - 1; cnt >= 0; cnt--) {
                LL A = hsh1.get_sub_hash(h[i], s[i].size() - 1 - cnt , s[i].size() - 1);
                LL B = hsh1.get_sub_hash(h[j], 0, cnt);
                if (A == B)
                    break;
            }
            p[i][j] = cnt + 1;
        }

    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= n; j++) {
    //         printf("%d%c", p[i][j], " \n"[j == n]);
    //     }

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;

    int ans = INF;
    do {
        int pre = 0, now = s[a[0]].size();
        for (int i = 1; i < n; i++) {
            now -= p[a[pre]][a[i]];
            now += s[a[i]].size();
            if (p[a[pre]][a[i]] != s[a[i]].size())
                pre = i;
        }
        ans = min(ans, now);
    } while (next_permutation(a.begin(), a.end()));
    cout << ans << endl;
    return 0;
}