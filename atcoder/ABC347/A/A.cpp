#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> ans;
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n;i++) {
        int x; cin >> x;
        if (x % k == 0) {
            ans.push_back(x / k);
        }
    }
    for (auto x : ans)
        cout << x << " ";
    return 0;
}