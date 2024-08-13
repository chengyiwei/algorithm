#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 15;
ll f[15], p[15], ans;
int main()
{
	ios::sync_with_stdio(false);
	for(int i = 0 ; i <= 9; i ++)
		cin >> f[i];
	for(int a = 0; a <= 9; a ++)
		for(int b = 0; b <= 9; b ++)
			for(int c = 0; c <= 9; c ++)
				for(int d = 0; d <= 9; d ++)
				{
					memset(p, 0, sizeof p);
					p[a] = 1; p[b] = 1; p[c] = 1; p[d] = 1;
					int t = 1;
					for(int i = 0; i <= 9; i ++)
						if(f[i] != p[i]) t = 0;
					if(t) ans ++;
				}
	cout << ans << endl;
	return 0;
} 
