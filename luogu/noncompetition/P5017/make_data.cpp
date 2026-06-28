#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return rand() << 15 | rand();
}

int main() {
    freopen("P5017.in","w",stdout);
    srand(GetTickCount());
    int n = 500, m = 100;
    printf("%d %d\n", n, m);
    vector<int> a;
    for (int i = 1; i <= n; i++) {
        a.push_back(brand() % 4000000);
    }
    for (auto x : a) {
        printf("%d ", x);
    }
    putchar('\n');
}