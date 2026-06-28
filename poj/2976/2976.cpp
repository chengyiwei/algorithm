#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <functional>


using namespace std;
const int maxn = 1e3 + 5;
int n, k;
int main() {
    freopen ("2976.in", "r", stdin);
    while (scanf("%d%d", &n, &k) != EOF && n && k) {
        k = n - k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i].first);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i].second);
        double L = 0, R = 0;
        for (int i = 0; i < n; i++)
            R += a[i].first;

        auto check = [&](double x) {
            vector<double> y;
            for (auto &[a, b] : a) 
                y.push_back(1.0 * a - x * b);
            sort(y.begin(), y.end(), greater<double>());
            double sum = 0;
            for (int i = 0; i < k; i++)
                sum += y[i];
            return sum >= 0;
        };

        for (int i = 0; i < 60; i++) {
            double mid = (L + R) / 2;
            if (check(mid)) L = mid;
            else R = mid;
        }
        printf("%d\n", (int) ( (L + 0.005) * 100) );
    }
    return 0;
}