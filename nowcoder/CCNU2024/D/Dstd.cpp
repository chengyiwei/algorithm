#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5+5;
ll n, b, ra, rb, a[MAXN], ans;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> b >> ra >> rb;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	priority_queue<ll, vector<ll>, greater<ll>> to;
	ll sum1 = 0;
	for(int i = 1; i <= n; i ++){
		vector<ll> vc;
		if(to.size() < b || to.top() <= a[i]){
			sum1 += a[i];
			to.push(a[i]);
		}
		while(to.size() > b){
			sum1 -= to.top();
			to.pop();
		}
		for(int j = max(1ll, i - ra + 1); j <= i; j ++){
			vc.push_back(a[j]);
		}
		sort(vc.begin(), vc.end(), greater<ll>());
		ll sum2 = 0;
		for(int j = 0; j < vc.size(); j ++){
			if(j < rb) sum2 += vc[j];
		}
		cout << sum1 << " " << sum2 << endl;
		ans = max(ans, sum1 + sum2);
	}
	cout << ans << endl;
}
