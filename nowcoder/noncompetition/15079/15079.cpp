#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a[4] = {2, 5, 11, 13};
    long long n;
    while (cin >> n) {
        long long ans = 0;
        for (int S = 0; S < (1 << 4); S++) {
            long long p = 1;
            for (int i = 0; i < 4; i++)
                if (S >> i & 1) p *= a[i];
            if (__builtin_popcount(S) & 1) ans -= n / p;
            else ans += n / p;
        }
        cout << ans << endl;
    }
    return 0;
}