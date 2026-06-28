#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    // freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    vector<pair<int, int>> a(n);
    vector<pair<int, int>> b(m);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
    for (int i = 0; i < m; i++) cin >> b[i].first, b[i].second = i;
    sort(a.begin(), a.end()); sort(b.begin(), b.end());

    auto check1 = [&](int T) {
        int now = 0, posi = n - 1, posj = m - 1;
        while (T > 0 && (posi >= 0 || posj >= 0)) {
            T -= k;
            if (now == 0) {
                if (posi >= 0) {
                    if (a[posi].first > T) return false;
                    posi--;
                }
            }
            else {
                if (posj >= 0) {
                    if (b[posj].first > T) return false;
                    posj--;
                }
            }
            now ^= 1;
        }
        return (posi < 0 && posj < 0);
    };

    auto check2 = [&](int T) {
        int now = 1, posi = n - 1, posj = m - 1;
        while (T > 0 && (posi >= 0 || posj >= 0)) {
            T -= k;
            if (now == 0) {
                if (posi >= 0) {
                    if (a[posi].first > T) return false;
                    posi--;
                }
            }
            else {
                if (posj >= 0) {
                    if (b[posj].first > T) return false;
                    posj--;
                }
            }
            now ^= 1;
        }
        return (posi < 0 && posj < 0);
    };

    int op = -1;
    
    int L = 0, R = 1e15;
    while (L + 1 < R) {
        int mid = (R - L) / 2 + L;
        if (check1(mid)) R = mid;
        else if (check2(mid)) R = mid;
        else L = mid;
        // cout << L << " " << R << "\n";
    }


    if (check1(R)) op = 0;
    else op = 1;

    int ansT = R, T = ansT;
    cout << ansT << "\n";
    vector<array<int, 3>> ans;
    int posi = n - 1, posj = m - 1;
    while (T > 0 && (posi >= 0 || posj >= 0)) {
        T -= k;
        if (op == 0) {
            if (posi >= 0) {
                assert(a[posi].first <= T);
                ans.push_back({T, 0, a[posi].second});
                posi--;
            }
        }
        else {
            if (posj >= 0) {
                assert(b[posj].first <= T);
                ans.push_back({T, 1, b[posj].second});
                posj--;
            }
        }
        op ^= 1;
    }
    reverse(ans.begin(), ans.end());
    for (auto &[t, ty, id] : ans)
        cout << t << " " << ty << " " << id + 1 << "\n";
    
    return 0;
}