#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> p;
    int x;
    while (cin >> x) p.push_back(x);
    reverse(p.begin(), p.end());
    for (auto &x : p) cout << x << '\n';
    return 0;
}