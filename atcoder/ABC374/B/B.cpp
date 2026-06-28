#include <bits/stdc++.h>
using namespace std;
int main() {
    char a[105] = "", b[105] = "";
    scanf("%s%s", a, b);
    int dif = 0;
    for (int i = 0; i < 100; i++)
        if (a[i] != b[i]) {
            dif = i + 1;
            break;
        }
    printf("%d\n", dif);
    return 0;
}