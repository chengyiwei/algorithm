#include<bits/stdc++.h>
#include<windows.h>
using namespace std;   
int brand() {
    return rand() << 15 | rand();
}
int main() {
    freopen("D.in", "w", stdout);
    srand(GetTickCount());
    int T = 10;
    printf("%d\n", T);
    while (T--) {
        int n = brand() % 100 + 1;
        for (int i = 1; i <= n; i++) {
            if (brand() & 1) {
                printf("?");
            }
            else {
                printf("%c", 'a' + brand() % 26);
            }
        }
        puts("");
    }
}