#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m_ = *max_element(a.begin(), a.end());
    int cnt = 0;
    for (auto x : a) cnt += x == m_;
    cout << m_ << ' ' << cnt << '\n';
    return 0;
}