#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int TT = 15;
int brand() {
    return (rand() << 16) | rand();
}

void print(int x) {
    if (x == 0) return ;
    print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    freopen ("B.in", "w", stdout);
    srand(GetTickCount());
    int n = 10;
    int q = 100;
    print(n); puts("");
    for (int i = 1; i <= n; i++) {
        int op = rand() % TT + 1;
        int x = rand() % TT + 1;
        print(op); putchar(' '); print(x); puts("");
    }
    print(q); puts("");
    for (int i = 1; i <= q; i++) {
        int m = rand() % 15 + 1;
        print(m); puts("");
        for (int j = 1; j <= m; j++) {
            int op = rand() % TT + 1;
            int x = rand() % TT + 1;
            print(op); putchar(' '); print(x); puts("");
        }
        m = rand() % 15 + 1;
        print(m); puts("");
        for (int j = 1; j <= m; j++) {
            int op = rand() % TT + 1;
            int x = rand() % TT + 1;
            print(op); putchar(' '); print(x); puts("");
        }
    }
    return 0;
}
