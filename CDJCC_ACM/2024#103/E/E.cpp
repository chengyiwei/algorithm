#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
typedef long long ll;
signed main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(0);
    int N, B; cin >> N >> B;
    vector<pii> a(N);
    for (int i = 0; i < N; i++) cin >> a[i].first >> a[i].second;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        vector<ll> p(N);
        for (int j = 0; j < N; j++)
            if (i == j)
                p[j] = a[j].first / 2 + a[j].second;
            else 
                p[j] = a[j].first + a[j].second;    
        sort(p.begin(), p.end());
        int now = 0; ll now_sum = 0;
        for (int j = 0; j < N; j++) {
            now_sum += p[j];
            if (now_sum <= B) now++;
            else break;
        }
        ans = max(ans, now);
    }
    cout << ans << endl;
    return 0;
}