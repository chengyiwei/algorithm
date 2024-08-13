#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL n, m, k;
LL check (LL x) { //check 返回的是 mid 在序列中是第几小的 
    LL res = 0;
    res += x / n;
    res += x / m;
    LL Lcm = n / __gcd(n, m) * m;
    res -= x / Lcm * 2;
    return res;
}
int main() {
    freopen ("D.in","r", stdin);
    cin >> n >> m >> k;
    LL L = 0, R = 1e18; //去二分最后的答案
    while (L < R) {
        LL mid = (R - L >> 1) + L;
        if (check (mid) >= k) R = mid;
        else L = mid + 1;
    }
    cout << L << endl;
    return 0;
}