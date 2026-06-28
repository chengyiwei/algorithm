#include <cstdio>
#include <iostream>
#include <cstring>
const int flg[5][2] = {{0, 0},{-1, 0},{0, 1},{1, 0},{0, -1}};
int n, matrix[230][230];

void reset() {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            for (int k = 0; k < 5; k++){
                int x = i + flg[k][0], y = j + flg[k][1];
                if (x >= 0 && x < n && y >= 0 && y < n)
                    matrix[i * n + j][x * n + y] = 1;
            }
}

void print() {
    for (int i = 0; i < n * n; i++){
        for (int j = 0; j <= n * n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int gauss() { //高斯消元 -1 表示无解，0 表示有唯一解，1 表示有无穷解
    int p = 0;
    for (int i = 0; i < n * n; i++) {
        int maxi = i; p = i;
        for (int j = i + 1; j < n * n; j++)
            if (matrix[j][i] > matrix[maxi][i]) 
                maxi = j;
        if (maxi != i)
            for (int j = 0; j <= n * n; j++)
                std::swap(matrix[i][j], matrix[maxi][j]);
        if (matrix[i][i] == 0) {break;}
        for (int j = 0; j < n * n; j++){
            if (j == i) continue;
            if (matrix[j][i] == 1)
                for (int k = 0; k <= n * n; k++)
                    matrix[j][k] ^= matrix[i][k];
        }
    }
    if (p == n * n - 1) return 0;
    else{
        for (int i = p; i < n * n; i++)
            if (matrix[i][n * n] != 0) return -1;
        return 1;
    }
}

void solve() {
    scanf("%d\n", &n);
    memset(matrix, 0, sizeof(matrix));
    reset();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char ch;
            scanf("%c", &ch);
            if (ch == 'w') matrix[i * n + j][n * n] = 1;
            if (ch == 'y') matrix[i * n + j][n * n] = 0;
        }
        scanf("\n");
    }
    int res = gauss();
    if (res == -1) printf("inf\n");
    else {
        int ans = 0;
        for (int i = 0; i < n * n; i++) 
            if (matrix[i][n * n] == 1) ans++;
        printf("%d\n", ans);
    }
}

int main() {
    freopen("1681.in", "r", stdin);
    freopen("1681.out", "w", stdout);
    int t; scanf("%d", &t);
    while (t--) solve();
    return 0;
}