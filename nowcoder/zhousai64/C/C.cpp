#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += mp[a[i]];
        cout << cnt << ' ';
        mp[a[i]] += 1;
        
    }
}