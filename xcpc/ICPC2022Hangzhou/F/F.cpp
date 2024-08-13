#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5+5;
ll Tex = 1, n;
string s;
map<string, ll> mp;
void AC()
{
	cin >> n;
	int p = 0;
	for(int i = 1; i <=n; i ++)
	{
		cin >> s;
		if(s.find("bie") != -1 && !mp[s])
		{
			p = 1;
			cout << s << "\n";
			mp[s] = 1;
		}
	}
	if(!p) cout << "Time to play Genshin Impact, Teacher Rice!" << "\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> Tex;
	while(Tex --) AC();
	return 0;	
} 
