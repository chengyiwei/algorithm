#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5+5;
ll n, q, a[MAXN], s[MAXN], x;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	while(q --){
		cin >> x;
		ll idx = upper_bound(s + 1, s + n + 1, x) - s;
		cout << idx - 1 << endl;
	}
	return 0;
}
