#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const ll MAXN = 2e5+5;
ll Tex = 1, n, x, y;
void AC(){
	cin >> n >> x >> y;
	cout << "Yes" << endl;
	cout << n - 1 << endl;
	ll lx = x, ly = y, rx = x, ry = y, cnt = 1;
	for(int i = 1; i <= n - 1; i ++){
		ll ckx = lx - 1, cky = ly - 1;
		if(ckx >= 1 && ckx <= n && cky >= 1 && cky <= n && ckx + cnt <= n && cky + cnt <= n){
			cout << ckx << " " << cky << " " << cnt << " " << cnt << endl;
			lx = ckx, ly = cky;
			cnt ++;
			continue;
		}
		ckx = rx + 1, cky = ly - 1;
		if(ckx >= 1 && ckx <= n && cky >= 1 && cky <= n && ckx - cnt >= 1 && cky - cnt <= n){
			cout << ckx << " " << cky << " " << -cnt << " " << cnt << endl;
			ly = cky, rx = ckx;
			cnt ++;
			continue;
		}
		ckx = rx + 1, cky = ry + 1;          
		if(ckx >= 1 && ckx <= n && cky >= 1 && cky <= n && ckx - cnt >= 1 && cky - cnt >= 1){
			cout << ckx << " " << cky << " " << -cnt << " " << -cnt << endl;
			rx = ckx, ry = cky;
			cnt ++;
			continue;
		}
		ckx = lx - 1, cky = ry + 1;
		if(ckx >= 1 && ckx <= n && cky >= 1 && cky <= n && ckx + cnt <= n && cky - cnt >= 1){
			cout << ckx << " " << cky << " " << cnt << " " << -cnt << endl;
			lx = ckx, ry = cky;
			cnt ++;
			continue;
		}
	}                                  
}
int main(){
	ios::sync_with_stdio(false);
//	cin >> Tex;
	while(Tex --) AC();
	return 0;
}                                      
