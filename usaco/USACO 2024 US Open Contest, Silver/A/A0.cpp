#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    // freopen ("A.in", "r", stdin);
    int N, K; cin >> N >> K;
    vector<ll> t(N + 1);
    for (int i = 1; i <= N; i++) cin >> t[i];
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    vector<int> vis(K + 1, 0);
    vector<pair<ll, ll> > v(N + 1);
    for (int i = 1; i <= K; i++) {
        v[i] = {0, t[i]};
        pq.push(t[i]);
    }
    for (int i = K + 1; i <= N; i++) {
        auto tim = pq.top(); pq.pop();
        pq.push(tim + t[i]);
        v[i] = {tim, tim + t[i]};
    }

    ll ans = pq.top();
    set<ll> st;
    st.insert(ans);
    for (int i = N; i >= 1; i--) {
        if (st.find(v[i].second) != st.end()) {
            if (i <= K) {
                vis[i] = 1;
            }else {
                st.insert(v[i].first);
            }
        }
    }

    cout << ans << endl;
    for (int i = 1; i <= K; i++)
        cout << vis[i];
    return 0;
}