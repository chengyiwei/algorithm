#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return rand() << 15 | rand();
}
int main() {
    freopen ("I.in", "w", stdout);
    srand(GetTickCount());
    int t = 1e5;
    printf("%d\n", t);
    while (t--) {
        int n = brand() % int(1e9) + 1, m = brand() % 5 + 1;
        printf("%d %d\n", n, m);
        vector<pair<int, int> > p(m + 1);
        p[0] = {0, 0};
        for (int i = 1; i <= m; i++) {
            p[i].first = brand() % n + 1;
        }
        sort(p.begin() + 1, p.end());
        if (1) {
            for (int i = 1; i <= m; i++) {
                if (brand() & 1) {
                    p[i].second = max(0, p[i].first - p[i - 1].first);
                }
                else {
                    p[i].second = brand() % max(1, (p[i].first - p[i - 1].first));
                }
            }
            for (int i = 1; i <= m / 2; i++) {
                int pos = brand() % m + 1;
                p[pos].second += 1;
            }
        }
        for (int i = 1; i <= m; i++) {
            printf("%d %d\n", p[i].first, p[i].second);
        }
    }
    return 0;
}