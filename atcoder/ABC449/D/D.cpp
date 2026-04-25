#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

// 统计 [low, high] 范围内有多少个整数 k 满足 |k| 是偶数
ll count_even_abs(ll low, ll high) {
    if (low > high) return 0;
    ll count = 0;
    // 转化为统计偶数和奇数，其实 |k| 是偶数等价于 k 是偶数
    // 统计 [low, high] 里的偶数个数：
    // floor(high/2) - floor((low-1)/2)
    auto get_evens = [](ll n) {
        if (n < 0) {
            // 对于负数，n/2 向零取整，我们需要向下取整
            return n / 2 - (n % 2 != 0 ? 1 : 0);
        }
        return n / 2;
    };
    
    // 这里直接写一个简单的逻辑：
    ll res = 0;
    // 调整到简单的正数逻辑或者直接循环判断边界后计算
    // 统计 [L, R] 之间的偶数个数公式：
    ll first_even = (low % 2 == 0) ? low : low + 1;
    ll last_even = (high % 2 == 0) ? high : high - 1;
    if (first_even <= last_even) {
        res = (last_even - first_even) / 2 + 1;
    }
    return res;
}

int main() {
    ll L, R, D, U;
    cin >> L >> R >> D >> U;

    ll total = 0;
    for (ll x = L; x <= R; ++x) {
        ll absX = abs(x);
        // 情况 1: |y| <= absX
        // 此时 max(|x|, |y|) = absX。如果 absX 是偶数，这些点全是黑。
        ll y_low = max(D, -absX);
        ll y_high = min(U, absX);
        
        if (y_low <= y_high) {
            if (absX % 2 == 0) {
                total += (y_high - y_low + 1); // 全黑
            }
        }

        // 情况 2: |y| > absX
        // 此时 max(|x|, |y|) = |y|。需要 |y| 是偶数。
        // 区域 A: y > absX  => y 范围 [max(D, absX + 1), U]
        ll A_low = max(D, absX + 1);
        ll A_high = U;
        if (A_low <= A_high) {
            total += count_even_abs(A_low, A_high);
        }

        // 区域 B: y < -absX => y 范围 [D, min(U, -absX - 1)]
        ll B_low = D;
        ll B_high = min(U, -absX - 1);
        if (B_low <= B_high) {
            total += count_even_abs(B_low, B_high);
        }
    }

    cout << total << endl;
    return 0;
}