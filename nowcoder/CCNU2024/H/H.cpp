#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5+5;
const ll INF = 1e9;
ll n, m, s, t, c, a[MAXN];
ll dis[MAXN];
bool flag[MAXN];
struct node{
	ll u, v, w;
};
vector<node> mp[MAXN];
struct ds{
	ll id, dist;
};
bool operator < (ds xx, ds yy){
	return xx.dist > yy.dist;
}
void dijkstra(ll x){
	memset(dis, 0x3f, sizeof dis);
	memset(flag, 0, sizeof flag);
	priority_queue<ds> op;
	op.push({s, a[s]});
	dis[s] = a[s];
	while(!op.empty()){
		ds qwq = op.top();
		op.pop();
		if(flag[qwq.id]) continue;
		flag[qwq.id] = 1;
		for(auto it : mp[qwq.id]){
			if(it.w > x) continue;
			if(dis[it.v] > dis[qwq.id] + a[it.v]){
				dis[it.v] = dis[qwq.id] + a[it.v];
				op.push({it.v, dis[it.v]});
			}
		}
	}
}
bool check(ll x){
	dijkstra(x);
	return dis[t] <= c;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> s >> t >> c;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int j = 1; j <= m ;j ++){
		ll x, y, z;
		cin >> x >> y >> z;
		mp[x].push_back({x, y, z});
	}
	ll l = -1, r = INF;
	while(l + 1 < r){
		ll mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	cout << r << endl;
	return 0;
}
