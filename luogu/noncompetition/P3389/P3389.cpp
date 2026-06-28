#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
double a[105][105];

int main() {
    freopen ("P3389.in", "r", stdin);
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n + 1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    for (int i = 1; i <= n; i++){
        int maxx = i;
        for (int j = i + 1; j <= n; j++)
            if (fabs(a[j][i]) > fabs(a[maxx][i]))
                maxx = j;
        for (int j = 1; j <= n + 1; j++)
            swap(a[i][j], a[maxx][j]);
        if (fabs(a[i][i]) < eps) {
            printf("No Solution");
            return 0;
        }
        for (int j = n + 1; j >= i; j--)
            a[i][j] /= a[i][i];
        for (int j = 1; j <= n; j++)
            if (i != j){
                double tmp = a[j][i];
                for (int k = n + 1; k >= i; k--)
                    a[j][k] -= a[i][k] * tmp;
            }
    }
    for (int i = 1; i <= n; i++)
        printf("%.2lf\n", a[i][n + 1]);
    return 0;
}