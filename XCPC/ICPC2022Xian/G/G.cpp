#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex = 1, n, ans = 1;
string s[MAXN];
map<string, ll> mp;
bool cmp(string xx, string yy)
{
	return xx.size() < yy.size();
}
void AC()
{
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> s[i];
	sort(s + 1, s + n + 1, cmp);
	for(int i = 1; i <= n; i ++)
	{
		if(s[i].size() == 1) mp[s[i]] = 1;
		else
		{
			if(s[i].size() > 350) continue;
			string l, r;
			for(int j = 0; j < s[i].size() - 1; j ++)
				l.push_back(s[i][j]);
			for(int j = 1; j < s[i].size(); j ++)
				r.push_back(s[i][j]);
			if(mp[l] && mp[r])
			{
				ans = max(ans, (ll)s[i].size());
				mp[s[i]] = 1;
			}
		}
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