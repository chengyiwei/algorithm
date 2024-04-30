#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 5e5+5;
const ll MOD = 1e9 + 7;
ll Tex, n, a[MAXN], b[MAXN], c[MAXN], inv[MAXN];

// init
bool flag[MAXN];
vector<ll> mp[MAXN];
ll p[MAXN];

ll fastPow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
void AC(){
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		mp[i].clear();
		flag[i] = 0;
		p[i] = 0;
	}
	for(int j = 1; j <= n; j ++){
		cin >> b[j];
	}
	for(int i = 1; i <= n; i ++){
		cin >> c[i];
	}
	queue<pair<ll,ll>> op;
	for(int i = 1; i <= n; i ++){
		if(a[b[i]] + c[b[i]] > a[i]){
			mp[b[i]].push_back(i);
		}
		if(a[b[i]] > a[i]){
			op.push({i, 1});
			p[i] += 1;
			flag[i] = 1;
		}
	}
	while(!op.empty()){
		pair<ll, ll> qwq = op.front();
		op.pop();
		for(int i = 0; i < mp[qwq.first].size(); i ++){
			if(flag[mp[qwq.first][i]]) continue;
			flag[mp[qwq.first][i]] = 1;
			p[mp[qwq.first][i]] += inv[qwq.second + 1];
			op.push({mp[qwq.first][i], qwq.second + 1});
		}
	}
	for(int i = 1; i <= n; i ++){
		cout << (a[i] + (c[i] * p[i]) % MOD) % MOD << " ";
	}
	cout << endl;
}
int main(){
	ios::sync_with_stdio(false);
	inv[1] = 1;
	for(int i = 2; i <= 500000; i ++){
		inv[i] = (inv[i - 1] * i) % MOD;
	}
	inv[500000] = fastPow(inv[500000], MOD - 2);
	for(int i = 499999; i >= 1; i --){
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;
	}
	cin >> Tex;
	while(Tex --) AC();
	return 0;
}
