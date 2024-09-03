#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        int x; char ch; cin >> x >> ch;
        if (ch == 'L') a.push_back(x);
        else b.push_back(x);
    }
    int ans1 = 0;
    for (int i = 0; i + 1 < a.size(); i++)
        ans1 += abs(a[i + 1] - a[i]);
    int ans2 = 0;
    for (int i = 0; i + 1 < b.size(); i++)
        ans2 += abs(b[i + 1] - b[i]);
    cout << ans1 + ans2 << '\n';
    return 0;
}