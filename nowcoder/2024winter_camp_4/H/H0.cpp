#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int n, m;
int mp[maxn][maxn];

int s[maxn][maxn];
int Le[maxn][maxn], Re[maxn][maxn];
char read_ch(){
    char ch = getchar();
    while (ch != '.' && ch != '*') ch = getchar();
    return ch;
}

int main() {
    freopen ("H.in", "r", stdin);
    freopen ("H0.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mp[i][j] = read_ch();

    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i][j - 1] + (mp[i][j] == '*');
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int x = i, y = j, len = 0;
            while (1 <= x && x <= n && 1 <= y && y <= m && mp[x][y] == '*')
                x--, y++, len++;
            Re[i][j] = len;
            
            x = i, y = j, len = 0;
            while (1 <= x && x <= n && 1 <= y && y <= m && mp[x][y] == '*')
                x--, y--, len++;
            Le[i][j] = len;
        }
    
    
    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++)
    //         printf ("%d", Le[i][j]);
    //     printf ("\n");
    // }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int len = 3; len <= m; len += 2) {
            for (int j = 1; j + len - 1 <= m; j++) {
                int L = j, R = j + len - 1;
                if (s[i][R] - s[i][L - 1] < len) continue;
                int siz = len + 1 >> 1;
                if (Le[i][R] >= siz && Re[i][L] >= siz) {
                    ans++;
                }
            }
        }
    printf ("%d\n", ans);
    return 0;
}