#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("H.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n, m, k; cin >> n >> m >> k;
    vector<int> up(k), dn(k), le(k), ri(k);
    for (int i = 0; i < k; i++) cin >> le[i] >> dn[i] >> ri[i] >> up[i];
    
    vector<vector<int>> cf(n + 2, vector<int>(m + 2, 0)), cnt(n + 2, vector<int>(m + 2, 0));
    for (int i = 0; i < k; i++) cf[le[i]][up[i]] += 1, cf[ri[i] + 1][up[i]] -= 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cnt[i][j] = cnt[i - 1][j] + cf[i][j];
    vector pre_up(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++) for (int j = m; j >= 1; j--) pre_up[i][j] = cnt[i][j] == 0 ? pre_up[i][j + 1] : j;

    fill(cf.begin(), cf.end(), vector<int>(m + 2, 0)); fill(cnt.begin(), cnt.end(), vector<int>(m + 2, 0));
    for (int i = 0; i < k; i++) cf[le[i]][dn[i]] += 1, cf[ri[i] + 1][dn[i]] -= 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cnt[i][j] = cnt[i - 1][j] + cf[i][j];
    vector pre_dn(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) pre_dn[i][j] = cnt[i][j] == 0 ? pre_dn[i][j - 1] : j;

    fill(cf.begin(), cf.end(), vector<int>(m + 2, 0)); fill(cnt.begin(), cnt.end(), vector<int>(m + 2, 0));
    for (int i = 0; i < k; i++) cf[le[i]][dn[i]] += 1, cf[le[i]][up[i] + 1] -= 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cnt[i][j] = cnt[i][j - 1] + cf[i][j];
    vector pre_le(n + 2, vector<int>(m + 2, 0));
    for (int j = 1; j <= m; j++) for (int i = 1; i <= n; i++) pre_le[i][j] = cnt[i][j] == 0 ? pre_le[i - 1][j] : i;

    fill(cf.begin(), cf.end(), vector<int>(m + 2, 0)); fill(cnt.begin(), cnt.end(), vector<int>(m + 2, 0));
    for (int i = 0; i < k; i++) cf[ri[i]][dn[i]] += 1, cf[ri[i]][up[i] + 1] -= 1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cnt[i][j] = cnt[i][j - 1] + cf[i][j];
    vector pre_ri(n + 2, vector<int>(m + 2, 0));
    for (int j = m; j >= 1; j--) for (int i = n; i >= 1; i--) pre_ri[i][j] = cnt[i][j] == 0 ? pre_ri[i + 1][j] : i;


    fill(cf.begin(), cf.end(), vector<int>(m + 2, 0)); fill(cnt.begin(), cnt.end(), vector<int>(m + 2, 0));
    for (int i = 0; i < k; i++) {
        cf[le[i]][up[i]] += 1, cf[ri[i] + 1][up[i]] -= 1;
        cf[le[i]][dn[i] - 1] -= 1, cf[ri[i] + 1][dn[i] - 1] += 1;
    }
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cnt[i][j] = cnt[i - 1][j] + cf[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 1; j--)
            cnt[i][j] = cnt[i][j + 1] + cnt[i][j];

    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (cnt[i][j] == 0) continue;
            int up = pre_up[i][j], dn = pre_dn[i][j], le = pre_le[i][j], ri = pre_ri[i][j];
            if (up == 0 || dn == 0 || le == 0 || ri == 0) continue;
            int now = (up - dn + 1) * (ri - le + 1);
            ans = min(now, ans);
        }
    }
    
    cout << ans << '\n';

    return 0;
}