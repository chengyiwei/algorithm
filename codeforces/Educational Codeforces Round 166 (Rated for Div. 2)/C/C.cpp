#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
void solve() {
    int n, m; cin >> n >> m;
    vector<pii> p(n + m + 1 + 1);
    int num_a = 0, num_b = 0;
    for (int i = 1; i <= n + m + 1; i++)
        cin >> p[i].first;
    for (int i = 1; i <= n + m + 1; i++)
        cin >> p[i].second;
    int pos = 0;
    for (int i = 1; i <= n + m + 1; i++) {
        if (num_a == n) {pos = i; break;}
        if (num_b == m) {pos = i; break;}
        auto [a, b] = p[i];
        if (a > b) num_a++;
        else num_b++;
    }
    if (num_b == m) {
        swap(n, m);
        for (int i = 1; i <= n + m + 1; i++) {
            auto &[a, b] = p[i];
            swap(a, b);
        }
    }
    num_a = 0, num_b = 0;
    int sum = 0;
    for (int i = 1; i <= n + m + 1; i++) {
        auto [a, b] = p[i];
        if (num_a == n) {sum += b; continue;}
        if (num_b == m) {sum += a; continue;}
        if (a > b) num_a += 1, sum += a;
        else num_b += 1, sum += b;
    }

    num_a = -1, num_b = 0;
    int sum2 = 0;
    for (int i = 1; i <= n + m + 1; i++) {
        auto [a, b] = p[i];
        if (num_a == n) {sum2 += b; continue;}
        if (num_b == m) {sum2 += a; continue;}
        if (a > b) num_a += 1, sum2 += a;
        else num_b += 1, sum2 += b;
    }

    int add = sum2 - sum;
    for (int i = 1; i <= n + m + 1; i++) {
        auto [a, b] = p[i];
        if (i >= pos) {
            cout << sum - b << ' ';
            continue;
        }
        if (a > b) 
            cout << sum - a + add << ' ';
        else 
            cout << sum - b << ' ';
    }
    cout << '\n';
}

signed main() {
    freopen ("C.in", "r", stdin);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}