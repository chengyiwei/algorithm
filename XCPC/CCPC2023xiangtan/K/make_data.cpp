#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return (rand() << 15) + rand();
}
int main() {
    freopen ("K.in","w",stdout);
    srand(GetTickCount());
    int n = brand() % 50 + 2, m = brand() % 50, k = brand() % 100 + 1;
    printf("%d %d %d\n",n,m,k);
    return 0;
}