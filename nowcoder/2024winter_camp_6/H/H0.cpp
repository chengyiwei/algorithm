#include<bits/stdc++.h>
#define endl '\n'

using namespace std;
using i64 = int64_t;
using f64 = double_t;
using i128 = __int128_t;

typedef i64 LL;
typedef pair<LL, LL> PLL;


const int N = 1e6+10, M = 30010;

LL res = 0, n;

struct Point{
    __int128 x,y;
}p[1005];
  
 
i128 dist(LL x1, LL y1, LL x2, LL y2)
{
    return ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int calc(int i , int j ,LL x, LL y, LL r)
{
    LL x1 = p[i].x, y1 = p[i].y, x2 = p[j].x, y2 = p[j].y;
    bool flag1 = false, flag2 =false, flag3 = false, flag4 = false;
    if(dist(x1, y1, x, y) < r * r) flag1 = true;//圆内
    if(dist(x2, y2, x, y) < r * r) flag2 = true;
    if(dist(x1, y1, x, y) == r * r) flag3 = true;//圆上
    if(dist(x2, y2, x, y) == r * r) flag4 = true;
    if(flag1 && flag2) return 0;//两个点都在圆内，肯定无交点
    else if(flag1 || flag2)//一个点在圆内，一定只有一个交点
    {
        return 1 ;
    }
    i128 A = dist(x1, y1 , x2 , y2) * r * r;
    i128 B = (x1 - x)* (y2 - y) - (x2 - x)* (y1 - y);//叉乘结果的值替代absinθ
    B = B * B;
    if(B > A) return 0;//圆心到直线距离大于半径，肯定没有交点
    i128 angle1=(x - x1)*(x2 - x1) + (y - y1)*(y2 - y1);
    i128 angle2=(x - x2)*(x1 - x2) + (y - y2) * (y1 - y2);
    if(angle1 > 0 && angle2 > 0)//如果两个角都是锐角，说明此时直线和圆的关系是相切或相交
    {
        if(A == B)//相切
        {
            return 1;
        }
        return 2 ;//相交
    }
    else
    {
        if(flag3 || flag4)//否则如果存在至少一个圆上的点也可以说明是有一个交点的
        {
            return 1;
        }
        else return 0;//相离
    }
    return 0;
}

void solve()
{
    cout<<setiosflags(ios::fixed)<<setprecision(10);
    LL x0, y0, r;
    cin>>x0>>y0>>r;
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x,y;
        cin>>x>>y;
        p[i]={x,y};
         
        if((x-x0)*(x-x0)+(y-y0)*(y-y0)==r*r){
            res-=(n-1)*(n-2)/2; //如果三角形上存在圆上的点，在三角形上会同时被相邻两条线取为交点，因此必须提前减去一半这种情况的贡献
        }
    }
    for(int i = 1 ;i <= n ;i++)
    {
        for(int j = i + 1;j <= n;j++)
        {
            LL now = calc(i, j, x0, y0, r);
            cout << i << " " << j << " " <<now << endl;
            res = res + (n - 2) * now; //交点数目乘以其余的点就是贡献度
        }
    }
    LL num = n * (n - 1) * (n - 2) / 6; // 除以n中取3的取法
    long double ans = res * 1.0 / num;
    cout<<ans<<endl;
}

int main()
{
    freopen("H.in", "r", stdin);
    freopen("H0.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}