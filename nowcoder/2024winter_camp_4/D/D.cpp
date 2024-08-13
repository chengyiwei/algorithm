#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 5;
int n, cnt = 0;
LL a[maxn], sum;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n == 1) { cout << 1 << endl; return 0; }
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    for (LL i = 1; i; i++) {
        if (sum / i < n) break;
        if (sum % i == 0)
            cnt ++;
    }
    cout << cnt << endl;
    return 0;
}