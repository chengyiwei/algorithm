#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define init(x) memset (x,0,sizeof (x))
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MAX = 5e5 + 5;
const int MOD = 1e9 + 7;
inline ll read ();
struct node
{
	ll t,x,y;
} s[MAX];
ll tot,n,m,k,l = 0,r = INF,ans,ex[MAX],st[MAX]; 
bool cmp (node xx,node yy);
ll check (ll ti);
int main ()
{
	freopen ("K.in","r",stdin);
	freopen ("K0.out","w",stdout);
	n = read ();m = read ();k = read ();
	for (int i = 1;i <= m;++i) 
	{
		s[i].t = read ();s[i].x = read ();s[i].y = read ();
		if (!ex[s[i].x]) ex[s[i].x] = 1,++tot;
	}
	sort (s + 1,s + 1 + m,cmp);//按照时间降序排序
	if (tot == 1) {puts ("-1");return 0;}//特判
	while (l <= r)
	{
		ll mid = (l + r) >> 1;
		if (check (mid)) ans = mid,l = mid + 1;
		else r = mid - 1;
	}
	printf ("%lld\n",ans);
	return 0;
}
inline ll read ()
{
    ll s = 0;int f = 1;
    char ch = getchar ();
    while ((ch < '0' || ch > '9') && ch != EOF)
	{
        if (ch == '-') f = -1;
        ch = getchar ();
    }
    while (ch >= '0' && ch <= '9')
	{
        s = s * 10 + ch - '0';
        ch = getchar ();
    }
    return s * f;
}
bool cmp (node xx,node yy) {return (xx.t == yy.t) ? xx.y < yy.y : xx.t > yy.t;}//时间晚的优先 
ll check (ll ti)
{
	ll ret = ti;//从 ti 开始消耗用于凝视 
	for (int i = 1;i <= n;++i) st[i] = 0;//每个通道被凝视的次数 
	for (int i = 1;i <= m;++i)
	{
		if (ti < s[i].t) continue;//该子弹还未出现 
		ll tmp = (s[i].y - 1) / k + 1 + st[s[i].x] + s[i].t - 1;//到达时的时间 
		if (tmp > ti) continue;//子弹在 ti 时无法达到 	
		tmp = ti - tmp + 1;//需要凝视的时间 
		if (ret - tmp + 1 < s[i].t) return 0;//剩余时间无法处理 
		ret -= tmp;st[s[i].x] += tmp;//进行标记
	}
	return 1;
}