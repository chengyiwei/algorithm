#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pil;
const ll MAXN = 2e5+5;
ll n, b, ra, rb, a[MAXN], flag[MAXN], ans;
int main(){
//	freopen ("D.in" ,"r", stdin);
	ios::sync_with_stdio(false);
	cin >> n >> b >> ra >> rb;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	priority_queue<ll, vector<ll>, greater<ll> > total;
	set<pil> st;
	priority_queue<pil> op;
	ll sum1 = 0, sum2 = 0;
	for(int i = 1; i <= n; i ++){
		if(total.size() < b || total.top() <= a[i]){
			sum1 += a[i];
			total.push(a[i]);
		}
		while(total.size() > b){
			sum1 -= total.top();
			total.pop();
		}
		
		op.push({a[i], i});
		for(int i = 1; i <= n; i ++){
			
		}
		while(!op.empty() && op.top().second <= max(0ll, i - ra))
			op.pop();
		if(flag[max(0ll, i - ra)]){
			st.erase({a[max(0ll, i - ra)], max(0ll, i - ra)});
			flag[max(0ll, i - ra)] = 0;
			sum2 -= a[max(0ll, i - ra)];
		}
		if(st.size() < rb || st.begin() -> first <= op.top().first){
			st.insert(op.top());
			sum2 += op.top().first;
			flag[op.top().second] = 1;
			op.pop();
		}
		while(st.size() > rb){
			sum2 -= st.begin() -> first;
			flag[st.begin() -> second] = 0;
			op.push(*st.begin());
			st.erase(st.begin());
		}
//		cout << sum1 << " " << sum2 << endl;
		ans = max(ans, sum1 + sum2);
	}
	cout << ans << endl;
	return 0;
}
