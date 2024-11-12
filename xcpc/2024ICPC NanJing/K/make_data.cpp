#include <bits/stdc++.h>

int main() {
    freopen ("K.in", "w", stdout);
    srand(time(0));

    int n = rand() % 100 + 1, m = rand() % 100 + 1;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        a[i] = rand() % 20000 + 1;
    for (int i = 0; i < m; i++)
        b[i] = rand() % 20000 + 1;
    int w = std::max(*std::max_element(a.begin(), a.end()), *std::max_element(b.begin(), b.end()));
    int k = n % 5 + 1;
    
    printf("1\n");
    printf ("%d %d %d %d\n", n, m, k, w);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < m; i++)
        printf("%d ", b[i]);
    printf("\n");
}