#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int ans = INF;
int lst_a, now_a;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i ++) {
        int x = b[i];
        auto it = upper_bound(a.begin(), a.end(), x);
        if (it != a.end()) {
            if (ans > *it - x) {
                ans = *it - x;
                lst_a = *it; now_a = i;
            }
        }
        if (it != a.begin()) {
            it --;
            if (ans > x - *it) {
                ans = x - *it;
                lst_a = *it; now_a = i;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == lst_a)
            swap (a[i], a[now_a]);
    }
    for (auto x : a) cout << x << " ";
    return 0;
}