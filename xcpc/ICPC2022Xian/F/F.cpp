#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6 + 5;
const ll INF = 1e18 + 5;
ll Tex = 1, n, c1, c2, ans;
char x, y, z;
void AC()
{
	cin >> n >> c1 >> c2;
	c1 = min(c1, c2);
	c2 = min(2 * c1, c2);
	for(int i = 1; i <= n; i ++)
	{
		cin >> x >> y >> z;
		if(x == y || y == z || x == z)
		{
			ans += c1 + c2;
		}
		else ans += c1 * 3;
	}
	cout << ans << endl;
}
int main()
{
	ios::sync_with_stdio(false);
//	cin >> Tex;
	while(Tex --) AC();
	return 0;
} 