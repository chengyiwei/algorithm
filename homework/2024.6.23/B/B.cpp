#include <stdio.h>
int a[105];
int main() {
    int n; scanf("%d", &n);

    for (int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);

    for (int i = 1; i < 4; i++) {
        for (int j = n - 1; j >= i; j--)
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        for (int j = 1; j <= n; j++) 
            printf("%d%c", a[j], " \n"[j == n]);
    }
}