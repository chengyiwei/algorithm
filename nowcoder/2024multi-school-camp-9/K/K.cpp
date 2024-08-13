#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
int main() {
    freopen ("K.in", "r", stdin);
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (k == 1) {
        cout << *max_element(a.begin() + 1, a.end()) << endl;
        return 0;
    }

    vector<int> p;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        while (x) { p.push_back(x); x /= k; }
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    reverse(p.begin(), p.end());
    sort(a.begin() + 1, a.end(), greater<int>());
    int ans = INF, cnt = 0;
    int pos = 1;
    multiset<int> st;
    for (auto x : p) {
        while (pos <= n && a[pos] > x) {
            st.insert(a[pos]); pos += 1;
        }
        while (!st.empty()) {
            auto it = st.end(); it--;
            if (*it > x) {
                int y = *it; st.erase(it);
                cnt += 1; y /= k;
                st.insert(y);
            }
            else break;
        }
        ans = min(ans, x + cnt);
    }

    cout << ans << endl;
    return 0;
}
