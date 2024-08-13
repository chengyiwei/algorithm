#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, pos, val; cin >> n >> pos >> val;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    a.insert(a.begin() + pos, val);
    for (int i = 0; i < n + 1; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}