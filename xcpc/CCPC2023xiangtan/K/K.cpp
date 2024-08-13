#include <bits/stdc++.h>
using namespace std;
const int TT = 25;

auto init() {
    vector<string> h;
    for (int i = 0; i < TT; i++)
        for (int j = i + 1; j < TT; j++) {
            string now;
            now.push_back(i + 'b');
            now.push_back(j + 'b');
            h.push_back(now);
        }
    return h;
}

int main() {
    freopen ("K.in","r",stdin);
    freopen ("K.out","w",stdout);
    int n, m, k; cin >> n >> m >> k;

    if (m >= k) {cout << "No" << '\n'; return 0;} 

    vector<string> st;
    if (m == 0) {
        if (n > 26) {cout << "No" << '\n'; return 0;}
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            string now;
            for (int j = 1; j <= k; j++) {
                now.push_back('a' + i - 1);
            }
            st.push_back(now);
        }
    }
    else {
        auto h = init();
        for (int i = 0; i < n; i++) {
            string now;
            for (int j = 0; j < m - 1; j ++) {
                now.push_back('a');
            }
            int cnt = 0;
            for (int j = m - 1; j < k; j++) {
                now.push_back(h[i][cnt % 2]);
                cnt ++;
            }
            st.push_back(now);
        }
    }
    cout << "Yes" << '\n';
    // cout << st.size() << '\n';
    for (auto & x : st)
        cout << x << '\n';
    return 0;
}