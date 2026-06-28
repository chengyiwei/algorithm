#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int x; cin >> x;
    int l = 0, r = n - 1;
    int cnt = 0;
    while (l < r) {
        cnt += 1;
        int mid = (l + r) >> 1;
        if (a[mid] == x)
            return cout << mid << "\n" << cnt << endl, 0;
        if (a[mid] < x)
            l = mid + 1;
        else 
            r = mid;
    }
    cout << -1 << "\n" << cnt << endl;
    return 0;
}