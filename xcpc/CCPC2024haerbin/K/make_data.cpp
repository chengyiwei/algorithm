#include <bits/stdc++.h>

int main() {
    
    freopen ("K.in", "w", stdout);
    srand(time(0));


    std::vector<std::array<int, 3>> ans;
    int n = 1000;
    long long sum_l = 0, sum_r = 0;
    for (int i = 1; i <= n; i++) {
        int w = rand() % 100 + 1, l = rand() % 100 + 1, r = rand() % 100 + l;
        // printf("%d %d %d\n", w, l, r);
        ans.push_back({w, l, r});
        sum_l += l, sum_r += r;
    }
    long long m = rand() % (sum_r - sum_l + 1) + sum_l;
    
    printf("%d %lld\n", n, m);

    for (auto a : ans) {
        printf("%d %d %d\n", a[0], a[1], a[2]);
    }

}