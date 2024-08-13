#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, ans;
long long X[MAXN + 10], Y[MAXN + 10];

long long cross(long long x1, long long y1, long long x2, long long y2) {
    return x1 * y2 - x2 * y1;
}

int main() {
    freopen ("M.in", "r", stdin);
    freopen ("M0.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld%lld", &X[i], &Y[i]);

    for (int i = 0, j = 1; i < n; i++) {
        // j 是下一个 y 值不相等的点
        while (Y[i] == Y[j]) j = (j + 1) % n;
        int pre = (i + n - 1) % n;
        if (Y[i] < Y[pre] && Y[i] < Y[j]) {
            if (Y[i] != Y[(i + 1) % n]) {
                // 情况一
                assert(j == (i + 1) % n);
                if (cross(X[i] - X[pre], Y[i] - Y[pre], X[j] - X[i], Y[j] - Y[i]) > 0) ans++;
            } else {
                // 情况二
                if (X[(i + 1) % n] > X[i]) ans++;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}