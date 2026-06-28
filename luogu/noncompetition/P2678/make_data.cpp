#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return rand() << 15 | rand();
}

int main() {
    freopen("P2678.in","w",stdout);
    srand(GetTickCount());
    int d = 1e9, n = 500, m = 0;
    printf("%d %d %d\n",d,n,m);
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        a[i] = brand() % (d - 1) + 1;
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) {
        printf("%d\n", a[i]);
    }
}