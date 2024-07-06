#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll a, b, l; cin >> a >> b >> l;
    vector<ll> pa, pb;
    pa.push_back(1);
    while (1) {
        ll now = pa.back();
        if (now * a > l) break;
        pa.push_back(now * a); 
    }
    pb.push_back(1);
    while (1) {
        ll now = pb.back();
        if (now * b > l) break;
        pb.push_back(now * b);
    }
    map<ll, int> mp;
    for (int i = 0; i < pa.size(); i++)
        for (int j = 0; j < pb.size(); j++) {
            if (l % (pa[i] * pb[j]) == 0) {
                mp[l / (pa[i] * pb[j])] = 1;
            }
        }
    cout << mp.size() << endl;
    return ;
}

int main() {
    int t; cin >> t;
    while (t--)
        solve();
    return 0;
}