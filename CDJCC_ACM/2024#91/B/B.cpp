#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    deque<ll> dq;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        dq.push_back(x);
        while (dq.size() >= 2) {
            int r1 = dq.back(), r2 = dq[dq.size() - 2];
            if (r1 == r2) {
                dq.pop_back();
                dq.pop_back();
                dq.push_back(r1 + 1);
            }
            else break;
        }
    }
    cout << dq.size() << endl;
    return 0;
}