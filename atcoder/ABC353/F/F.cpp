#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll K; cin >> K;
    ll Sx, Sy, Tx, Ty; cin >> Sx >> Sy >> Tx >> Ty; Sx += K, Sy += K, Tx += K, Ty += K;
    ll dist = abs(Tx - Sx) + abs(Ty - Sy);
    if (1 < K) {
        vector<tuple<ll, ll, ll> > st;
        if (((Sx / K) ^ (Sy / K)) & 1) {
            st.emplace_back(Sx / K, Sy / K, 0);
        }
        else {
            st.emplace_back(Sx / K - 1, Sy / K, 1 + Sx % K);
            st.emplace_back(Sx / K + 1, Sy / K, K - Sx % K);
            st.emplace_back(Sx / K, Sy / K - 1, 1 + Sy % K);
            st.emplace_back(Sx / K, Sy / K + 1, K - Sy % K);
        }

        vector<tuple<ll, ll, ll> > ed;
        if (((Tx / K) ^ (Ty / K)) & 1) {
            ed.emplace_back(Tx / K, Ty / K, 0);
        }
        else {
            ed.emplace_back(Tx / K - 1, Ty / K, 1 + Tx % K);
            ed.emplace_back(Tx / K + 1, Ty / K, K - Tx % K);
            ed.emplace_back(Tx / K, Ty / K - 1, 1 + Ty % K);
            ed.emplace_back(Tx / K, Ty / K + 1, K - Ty % K);
        }

        if (K == 2) {
            for (auto [sx, sy, d1] : st)
                for (auto [tx, ty, d2] : ed)
                    dist = min(dist, abs(sx - tx) + abs(sy - ty)  + abs (abs(sx - tx) - abs(sy - ty)) / 2 + d1 + d2);
        }
        else {
            for (auto [sx, sy, d1] : st)
                for (auto [tx, ty, d2] : ed)
                    dist = min(dist, abs(sx - tx) + abs(sy - ty) + abs(abs(sx - tx) - abs(sy - ty)) + d1 + d2);
        }
    }
    cout << dist << endl;
    return 0;
}