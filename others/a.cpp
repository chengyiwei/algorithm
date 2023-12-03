#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];  // 储存数据
int b[1005][1005] = {0};  // 标记是否走过
int c[1000005] = {0};     // 统计个数

bool legal_site(int x, int y, int n)
{
    if (x >= 1 && x <= n && y >= 1 && y <= n)
    {
        return 1;
    }
    return 0;
}

void dfs(int x, int y, int n, int j)
{
    b[x][y] = j;
    c[j]++;
    printf("%d %d\n",x,y);
    if (legal_site(x - 1, y, n) && a[x - 1][y] != a[x][y] && b[x - 1][y] == 0)
    {
        dfs(x - 1, y, n, j);
    }
    if (legal_site(x + 1, y, n) && a[x + 1][y] != a[x][y] && b[x + 1][y] == 0)
    {
        dfs(x + 1, y, n, j);
    }
    if (legal_site(x, y - 1, n) && a[x][y - 1] != a[x][y] && b[x][y - 1] == 0)
    {
        dfs(x, y - 1, n, j);
    }
    if (legal_site(x, y + 1, n) && a[x][y + 1] != a[x][y] && b[x][y + 1] == 0)
    {
        dfs(x, y + 1, n, j);
    }
    return;
}

int main()
{
    freopen("a.in","r",stdin);
    int n, m;
    char s;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf(" %c", &a[i][j]);
        }
    }

    int x, y;
    for (int j = 1; j <= m; j++)
    {
        scanf("%d %d", &x, &y);
        if (b[x][y] == 0)
        {
            dfs(x, y, n, j);
            printf("%d\n", c[j]);
        }
        else
        {
            printf("%d\n", c[b[x][y]]);
        }
    }
    return 0;
}