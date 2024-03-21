#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
const int N = 2e5 + 10;

double cross(PLL x, PLL y)//向量叉乘，直接乘好像会爆longlong用了double
{
    return (double)x.first * y.second - (double)x.second * y.first;
}
PLL operator-(PLL x, PLL y)//重载向量减法
{
    return { x.first - y.first,x.second - y.second };
}
double fun(PLL v)//求向量斜率
{
    return (double)v.second / v.first;
}
LL s[N];
double ans[N];
void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &s[i]), s[i] += s[i - 1];
    vector<PLL>v{ {n,s[n]} };
    for (int i = n - 1; i >= 0; --i)
    {
        PLL x = { i,s[i] };
        while (v.size() > 1)//典 凸包板子
        {
            PLL y = v.back(), z = v[v.size() - 2];
            if (cross(y - x, z - y) < 0)break;
            v.pop_back();
        }
        ans[i + 1] = fun(v.back() - x);
        v.push_back({ i,s[i] });
    }
    for (int i = 1; i <= n; ++i)
        printf("%.10lf\n", ans[i]);
}
int main()
{
    freopen("G.in", "r", stdin);
    freopen ("G0.out", "w", stdout);
    solve();
    return 0;
}   