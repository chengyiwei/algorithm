#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    ll x_1, y_1, x_2, y_2;
    cin >> x_1 >> y_1 >> x_2 >> y_2;

    auto dis = [&](ll x, ll y) -> ll {
        return abs(x_1 - x) + abs(x_2 - x) + abs(y_1 - y) + abs(y_2 - y);
    };

    map<ll, int> mp;
    mp[dis(x_1, y_1)] += 2;
    vector<pair<ll, ll>> nums(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> nums[i].first >> nums[i].second;
        mp[dis(nums[i].first, nums[i].second)]++;
    }
    ll mid = dis(x_1, y_1);
    for (int i = 1; i <= n; i++) {
        ll sum = (abs(x_1 - x_2) + 1) * (abs(y_1 - y_2) + 1);
        ll ds = dis(nums[i].first, nums[i].second);
        if (mid != ds) sum = ((ds - mid) / 2 - 1) * 4 + (mid + 2) * 2;
        cout << sum - mp[ds] << " ";
    }
    cout << endl;
}
// by TRfirst

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}