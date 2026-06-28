#include <bits/stdc++.h>
using namespace std;
int main() {
    int ans = 0;
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n;) {
        int sum = 0;
        int j = i;
        while (j <= n && sum + a[j] <= k) sum += a[j++];
        ans += 1; 
        i = j;
    }
    cout << ans << endl;
    return 0;
}