#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,g[3000001] = {0},gb[3000001] = {0};
const int mod = 998244353;
int qpow(int x,int y){
	int hjx = x%mod,ans = 1;
	while(y){
		if(y&1){
			ans*=hjx;
			ans%=mod;
		}
		hjx*=hjx;
		hjx%=mod;
		y>>=1;
	}
	return ans%mod;
}
signed main(){
	int T;
	cin>>T;
	g[1] = 1;
	g[2] = 2;
	for(int i = 3;i<=2500000;i++){
		g[i] = g[i-2]+g[i-1];
		g[i]%=mod;
	}
	gb[0] = 1;
	for(int i = 1;i<=1000500;i++){
		gb[i] = gb[i-1]*g[i*2];
		gb[i]%=mod;
	}
	while(T--){
		cin>>n>>m;
		if(n>m)swap(n,m);
		int ans = gb[n];
		ans*=ans;
		ans%=mod;
		ans*=qpow(g[2*n+1],m-n)%mod;
		cout<<ans%mod<<endl;
	}
	return 0;
}
