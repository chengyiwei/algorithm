#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll N = 1e7 + 5;
ll f[N], inv[N], n, ans;
ll M(ll x){
	return (x % MOD + MOD) % MOD;
}
ll fastPow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = M(res * a);
		a = M(a * a);
		b >>= 1;
	}
	return res;
}
ll C(ll x, ll y){
	if (x < y) return 0;
	if (x == y) return 1;
	return M(M(f[x] * inv[y]) * inv[x - y]);
}
int main(){
	cin >> n;
	f[0] = 1;
	for(int i = 1; i <= n; i ++){
		f[i] = M(f[i - 1] * i);
	}
	inv[n] = fastPow(f[n], MOD - 2);
	for(int i = n; i >= 2; i --){
		inv[i - 1] = M(inv[i] * i);
	}
	ans = f[n - 1];
	for(int i = 2; i <= n; i ++){
		ans = M(ans + M(M(C(n - i, i - 1) * f[n - i]) * f[i - 1]));
	}
	cout << M(ans) << endl;
	return 0;
}
