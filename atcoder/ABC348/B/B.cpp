#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i].first >> a[i].second;
    for (int i = 0; i < n; i++) {

        auto dist = [&](pii a, pii b) {
            return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
        };

        int idx = -1;
        int max_x = -1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (max_x < dist(a[i], a[j])) {
                max_x = dist(a[i], a[j]);
                idx = j;
            }
        }
        cout << idx + 1 << '\n';
    }
    return 0;
}