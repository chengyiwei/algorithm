#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; ll k; int q; 
    cin >> n >> k >> q;
    vector<pair<ll, ll>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first -= 1;
    }
    ll now = 0;
    vector<ll> tim1(n + 1, 0), tim2(n + 1, 0), tim3(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ll tmp = a[i].first;
        now = max(now, tmp) + a[i].second;
        tim1[i] = now;
    }
    for (int i = 1; i <= n; i++) {
        ll tmp = a[i].first + k;
        now = max(now, tmp) + a[i].second;
        tim2[i] = now;
    }
    for (int i = 1; i <= n; i++) {
        ll tmp = a[i].first + k + k;
        now = max(now, tmp) + a[i].second;
        tim3[i] = now;
    }
    while (q--) {
        pair<ll, ll> query;
        cin >> query.first >> query.second;
        ll ans = 0;
        if (query.first == 1) {
            ans = tim1[query.second];
        }
        else if (query.first == 2) {
            ans = tim2[query.second];
        }
        else if (query.first == 3) {
            ans = tim3[query.second];
        }
        else {
            ll cz = tim3[query.second] - tim2[query.second];
            ans = tim2[query.second] + cz * (query.first - 2);
        }
        ll day = ans / k, rem = ans % k;
        if (rem == 0) { day--; rem = k;}
        cout << day + 1  << ' ' << rem << '\n';
    }
    return 0;
}