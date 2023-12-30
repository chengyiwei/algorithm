#include<bits/stdc++.h>
#include<ctime>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pil;
const ll MAXC = 505;
const ll MAXN = 5e4 + 5;
const ll INF = 1e9 + 5;
ll Tex = 1, n, c, a[MAXN], dp[MAXC];
void AC()
{
	cin >> n >> c;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater<ll>());
//	for(int i = 1; i <= n; i ++)
//		cout << a[i] << " ";
//	cout << endl;
	random_shuffle(a + 1, a + n + 1);
	random_shuffle(a + 1, a + n + 1);
	random_shuffle(a + 1, a + n + 1);
	set<pil> st[MAXC];
	for(int i = 1; i <= c; i ++)
	{
		st[i].insert({-INF, INF});
		dp[i] = INF;
	}
	st[0].insert({INF, -INF}); dp[0] = INF;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = c; j >= a[i]; j --)
		{
			for(auto it : st[j - a[i]])
			{
				ll mn1 = it.first;
				ll mx1 = it.second;
//				cout << i << " " << j - a[i] << " " << mn1 << " " << mx1 << endl;
				if(dp[j] > max(mx1, a[i]) - min(mn1, a[i]))
				{
					dp[j] = max(mx1, a[i]) - min(mn1, a[i]);
					st[j].clear();
					st[j].insert({min(mn1, a[i]), max(mx1, a[i])});
						
				}
				if(dp[j] == max(mx1, a[i]) - min(mn1, a[i]))
					st[j].insert({min(mn1, a[i]), max(mx1, a[i])});
			}
		}
//		for(auto it : st[8])
//		{
//			ll mn1 = it.first;
//			ll mx1 = it.second;
//			cout << i << " " << dp[8] << " " << mn1 << " " << mx1 << endl;
//		}
	}
	dp[c] >= 500 ? cout << -1 << endl : cout << dp[c] << endl;
}
/*
1
20 13
1 1 1 2 3 3 4 5 5 5 6 6 6 8 8 8 9 9 9 10
*/
int main()
{
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    srand(time(0));
	ios::sync_with_stdio(false);
	cin >> Tex;
	while(Tex --) AC();
	return 0;
}