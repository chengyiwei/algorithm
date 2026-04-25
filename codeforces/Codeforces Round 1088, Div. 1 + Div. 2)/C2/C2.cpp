#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<vector<int>> c(k + 1);
    for (int i = 1; i <= k; i++) {
        for (int j = i; j <= n; j += k) c[i].push_back(a[j]);
    }

    vector<int> flg(k + 1, 0);

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j + 1 < (int)c[i].size(); j++) {
            if (c[i][j] != c[i][j + 1]) {
                flg[i] = 1;
                break;
            }
        }
    }

    multiset<int> st;

    // for (int i = 1; i <= k; i++) {
    //     cout << "flg[" << i << "] = " << flg[i] << "\n";
    // }

    for (int i = 1; i <= k; i++) {
        if (flg[i] == 0) {
            int val = -1;
            for (int j = i; j <= n; j += k) {
                if (b[j] != -1) {
                    if (val == -1) val = b[j];
                    else if (b[j] != val) {
                        cout << "NO\n";
                        return;
                    }
                }
            }
            if (val != -1) {
                for (int j = i; j <= n; j += k) b[j] = val;
            }
            st.insert(a[i]);
        }
        else {
            for (int j = i; j <= n; j += k) {
                if (b[j] != -1 && b[j] != a[j]) {
                    cout << "NO\n";
                    return;
                }
                if (b[j] == -1) b[j] = a[j];
            }
        }
    }

    // cout << "st = ";
    // for (int x : st) cout << x << ' ';
    // cout << "\n";   

    for (int i = 1; i <= k; i++) {
        if (flg[i] == 0) {
            if (b[i] != -1 && st.count(b[i]) == 0) {
                cout << "NO\n";
                return;
            }
            else if (b[i] != -1) st.erase(st.find(b[i]));
        }
    }

    for (int i = 1; i <= k; i++) {
        if (flg[i] == 0 && b[i] == -1) {
            if (st.empty()) {
                cout << "NO\n";
                return;
            }
            b[i] = *st.begin();
            st.erase(st.begin());
            for (int j = i; j <= n; j += k) b[j] = b[i];
        }
    }

    cout << "YES\n";
    // for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
1
5 5
1 2 3 4 5
3 1 5 2 4

1
2 1
1 2
2 -1
*/