#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int brand() {
    return rand() << 15 | rand();
}

int main() {
    freopen("C.in","w",stdout);
    srand(GetTickCount());
    int n = 100000;
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
        string name;
        int len = brand() % 8 + 1;
        for (int j = 1; j <= len; j++) {
            name += brand() % 26 + 'a';
        }
        int x = brand() % 150;
        int y = brand() % 150;
        int z = brand() % 150;
        printf("%s %d %d %d\n", name.c_str(), x, y, z);
    }
    putchar('\n');
}