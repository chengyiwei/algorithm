#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int> p(n + 1);
    for (int i = 1; i < n; i++) cin >> a[i], p[a[i]] += 1;
    if (a[n - 1] != 1 || p[1] > 2) {cout << -1 << endl; return;}
    vector<int> ans(n + 1);
    int front = 1, back = n;
    for (int i = 2; i <= n; i++)
        if (p[i] >= 2) {cout << -1 << endl; return;} 
    if (p[1] == 1) {  // 1 只出现过一次，说明 ans[1] = 1
        ans[front++] = 1;
        for (int i = n; i >= 1; i--) 
            if (p[i] == 0) ans[back--] = i;
    }
    else { // 1 出现过两次
        for (int i = n; i >= 1; i--) 
            if (p[i] == 0) { ans[back--] = i, p[i] = 1; break;}
        for (int i = 1; i <= n; i++) 
            if (p[i] == 0) {ans[front++] = i; break;}
    }
    int pos = 1;
    while (front <= back) 
        if (ans[front - 1] > ans[back + 1])
            ans[front++] = a[pos++];
        else 
            ans[back--] = a[pos++];
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}