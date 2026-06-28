#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MAXN = 1e5+5;
typedef pair<ll, ll> pil;
typedef pair<pil, ll> pill;
ll Tex = 1, n, W, H, L;
ll read() {
	ll ret = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') { ch = getchar();}
	while (ch <= '9' && ch >= '0') ret = ret * 10 + ch - '0', ch = getchar();
	return ret * f;
}
struct cuboids{
	ll x1, y1, z1;
	ll x2, y2, z2;
}a[MAXN];
void check(){
	ll V = W * H * L, VH = 0;
	for(int i = 1; i <= n; i ++){
		VH += (a[i].x2 - a[i].x1) * (a[i].y2 - a[i].y1) * (a[i].z2 - a[i].z1);
	}
	if(VH != V){
		puts("No");
		return;
	}
	map<pill, ll> mp;
	a[0] = {0, 0, 0, W, H, L};
	for(int i = 0; i <= n; i ++){
		mp[{{a[i].x1, a[i].y1}, a[i].z1}] ++;
		
		mp[{{a[i].x2, a[i].y1}, a[i].z1}] ++;
		mp[{{a[i].x1, a[i].y2}, a[i].z1}] ++;
		mp[{{a[i].x1, a[i].y1}, a[i].z2}] ++;
		
		mp[{{a[i].x2, a[i].y2}, a[i].z1}] ++;
		mp[{{a[i].x2, a[i].y1}, a[i].z2}] ++;
		mp[{{a[i].x1, a[i].y2}, a[i].z2}] ++;
		
		mp[{{a[i].x2, a[i].y2}, a[i].z2}] ++;
	}
	
	for(auto it : mp){
		if(it.second % 2 == 1){
			puts("No");
			return;
		}
	}
	puts("Yes");
}
void AC(){
	W = read(); H = read(); L = read(); n = read();
	for(int i = 1; i <= n; i ++){
		a[i].x1 = read();
		a[i].y1 = read();
		a[i].z1 = read();
		a[i].x2 = read();
		a[i].y2 = read();
		a[i].z2 = read();
	}
	check();
}
int main(){
	ios::sync_with_stdio(false);
	Tex = read();
	while(Tex --) AC();
	return 0;
}
