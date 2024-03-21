#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int flg[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int mp[maxn][maxn], n, m, k;
int c[maxn], ans;

int check (int x, int y) {
    for (int i = 1; i <= k; i++) {
        x += flg[c[i]][0];
        y += flg[c[i]][1];
        if (mp[x][y] == 0) return 0;
    }
    return 1;
}

int main() {
    freopen ("C.in","r", stdin);

    scanf("%d%d%d\n", &n, &m, &k);
    for(int i = 1; i <= k; i++) {
        char ch; scanf("%c", &ch); 
        if (ch == 'L') c[i] = 3;
        if (ch == 'U') c[i] = 0;
        if (ch == 'R') c[i] = 1;
        if (ch == 'D') c[i] = 2;
    }
    scanf("\n");
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {
            char ch; scanf("%c", &ch);
            mp[i][j] = ch == '.';
        }
        scanf("\n");
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j] == 1)
                ans += check(i, j);
    printf("%d\n", ans);
    return 0;
}