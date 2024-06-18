#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
    int n; cin >> n;
    vector<pii> p1, p2;
    for (int i = 1; i <= n; i++) {
        int a, b, oka, okb; cin >> a >> b >> oka >> okb;
        if ((okb == 0 || a < b) && oka != 0)
            p1.push_back({a, i});
        else
            p2.push_back({b, i});
    }
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    cout << p1.size() << ' ';
    for (auto [_, x] : p1)
        cout << x << ' ';
    cout << endl;
    cout << p2.size() << ' ';
    for (auto [_, x] : p2)
        cout << x << ' ';
    cout << endl;
    return 0;
}