#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll h, a;
    bool operator < (const Node B) const {
        return h > B.h || (h == B.h && a < B.a);
    }
};

ll ans = 0;
int main() {
    freopen ("J.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;cin >> n;
    vector<Node> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].h;
    for (int i = 0; i < n; i++)
        cin >> p[i].a;
    sort(p.begin(), p.end());
    ll sum_h = 0, sum_a = 0;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && p[j].h == p[i].h) {
            sum_h += p[j].h;
            sum_a += p[j].a;
            j++;
        }
        ll k = p[i].h - 1;
        ll now = sum_a - sum_h + k * j;
        ans = max (ans, now);
        i = j;
    }
    cout << ans << endl;
    return 0;
}