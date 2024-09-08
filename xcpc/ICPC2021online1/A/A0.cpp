#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "r", stdin);
    freopen ("A0.out", "w", stdout);
    int k, n; cin >> k >> n;
    vector<int> a(n), b(n), cnt(k, 0), tim(k, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++) {
        int st = i % k;
        for (int j = st; ;) {
            if (tim[j] <= a[i]) {
                cnt[j] += 1;
                tim[j] = a[i] + b[i];
                break;
            }
            j = (j + 1) % k;
            if (j == st) break;
        }
    }
    int mx_ = *max_element(cnt.begin(), cnt.end());
    vector<string> ans;
    for (int i = 0; i < k; i++) {
        if (cnt[i] == mx_)
            ans.push_back(to_string(i));
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        cout << (i == ans.size() - 1 ? '\n' : ' '); 
    }
    return 0;
}