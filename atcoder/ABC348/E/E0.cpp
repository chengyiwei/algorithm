#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn = 2e6+50;
const int inf = 1e19 + 5;
vector<int> op[maxn];
int c[maxn];
long long  n,sc[maxn];
int ans = inf;
int p = 0;
int l = 0;
void dfs(int k,int fa,int d){
	  sc[k] = c[k];
	  l += d * c[k];
	  for(auto it :op[k]){
	  	 if(it == fa) continue;
	  	 dfs(it,k,d+1);
	  	 sc[k] += sc[it];
	  }
}
void dfs1(int k,int fa,int num){
     ans = min(ans,num);
	 for(auto it : op[k]){
	 	 if(it == fa) continue;
	 	 int k1 = num - sc[it] +  (p - sc[it]);
		 dfs1(it,k,k1); 
	 }
}
signed main(){
    freopen ("E.in", "r", stdin);
    freopen ("E0.out", "w", stdout);
    cin >>n;
    for(int i = 1 ;i < n ;i ++){
    	 int x,y;
    	 cin >>x>>y;
    	 op[x].push_back(y);
    	 op[y].push_back(x);
	}
	for(int i = 1;i <= n ;i ++){
	      cin >> c[i];
	      p += c[i];
	}
	dfs(1,0,0);
	dfs1(1,0,l); 
    cout << ans << endl;
	return 0;
} 