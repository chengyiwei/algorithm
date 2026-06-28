#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f;
int main() {
    freopen ("E.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> H(n + 1); H[0] = INF;
    vector<ll> ans(n + 1, 0);
    stack<ll> stk; stk.push(0);
    for (int i = 1; i <= n; i++)
        cin >> H[i];
    for (int i = 1; i <= n; i++) {
        while (H[stk.top()] < H[i]) stk.pop();
            ans[i] = ans[stk.top()] + (i - stk.top()) * H[i];
        stk.push(i);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] + 1 << " ";
    return 0;
}