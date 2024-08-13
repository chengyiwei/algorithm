#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5+5;
const ll INF = 1e9;
int main(){
	ios::sync_with_stdio(false);
	srand(time(0));
	ll n = rand() % 2000 + 1;
	ll b = rand() % n + 1;
	ll ra = rand() % n + 1;
	ll rb = rand() % ra + 1;
	cout << n << " " << b << " " << ra << " " << rb << endl;
	for(int i = 1; i <= n; i ++){
		ll x = rand() % INF + 1;
		cout << x << " ";
	}
	return 0;
}
