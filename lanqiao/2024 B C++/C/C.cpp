#include <bits/stdc++.h>
using namespace std;

bool check (int x) {
    vector<int> p;
    do {
        p.push_back(x % 10);
        x /= 10;
    } while (x);
    for (int i = 0; i < p.size(); i++) 
        if ((!(i & 1)) ^ (p[i] & 1)) return false;
    return true;
}

int main() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += check(i);
    cout << ans << endl;
    return 0;
}