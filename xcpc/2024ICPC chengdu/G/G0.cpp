#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    srand(time(0));

    int n = 2;
    vector<int> a(2, 0);
    cin >> a[0] >> a[1];
    
    for (int _ = 0; _ < 1000000; _++) {
        int pos = rand() % a.size() - 1;
        int op = rand() % 3;
        int x = a[pos], y = a[pos + 1], z;
        if (op == 0) z = x & y;
        if (op == 1) z = x | y;
        if (op == 2) z = x ^ y;
        if (z == x || z == y) continue;
        a.insert(a.begin() + pos + 1, z);
    }

    sort(a.begin(), a.end());
    cout << unique(a.begin(), a.end()) - a.begin() << '\n';

}
