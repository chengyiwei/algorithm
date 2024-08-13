#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ans;
int main() {
    freopen("I.in", "r", stdin);
    int n, m; scanf("%d%d", &n, &m);
    vector<LL> a(n + 1), b(m + 1), sum_a(n + 1, 0), sum_b(m + 1, 0);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum_a[i] = sum_a[i - 1] + a[i];
    for (int i = 1; i <= m; i++) scanf("%lld", &b[i]), sum_b[i] = sum_b[i - 1] + b[i];

    LL lst_min = 0;
    LL max_a = *max_element(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) {
        max_a = max(max_a, sum_a[i] - lst_min);
        lst_min = min(lst_min, sum_a[i]);
    }
    lst_min = 0;
    LL max_b = *max_element(b.begin() + 1, b.end());
    for (int i = 1; i <= m; i++) {
        max_b = max(max_b, sum_b[i] - lst_min);
        lst_min = min(lst_min, sum_b[i]);
    }

    LL lst_max  = 0;
    LL min_a = *min_element(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) {
        min_a = min(min_a, sum_a[i] - lst_max);
        lst_max = max(lst_max, sum_a[i]);
    }
    lst_max = 0;
    LL min_b = *min_element(b.begin() + 1, b.end());
    for (int i = 1; i <= m; i++) {
        min_b = min(min_b, sum_b[i] - lst_max);
        lst_max = max(lst_max, sum_b[i]);
    }
    // printf("%lld %lld\n", max_a, max_b);
    // printf("%lld %lld\n", min_a, min_b);
    ans = max(max(max_a * max_b, max_a * min_b), max(min_a * max_b, min_a * min_b));
    printf("%lld\n", ans);
    return 0;
}