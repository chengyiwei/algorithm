#include <iostream>
using namespace std;

using int64 = long long;
const int MOD = 2026;

int main() {
    int64 a, T, n;
    cin >> a >> T >> n;

    int64 cur = a % MOD;   // 第1天能量
    int64 sum = 0;

    for (int64 i = 1; i <= n; i++) {
        sum = (sum + cur) % MOD;
        cur = cur * T % MOD;   // 下一天能量
    }

    cout << sum % MOD << '\n';
    return 0;
}