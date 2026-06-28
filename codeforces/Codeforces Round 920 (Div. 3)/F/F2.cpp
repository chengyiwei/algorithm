#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using i64=long long;

void solve(){
	int n,q;
	cin>>n>>q;
	vector<i64> a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];

	vector<vector<i64> > f(n+1,vector<i64>(205)),sum(n+1,vector<i64>(205));
	for(int j=1;j<=200;j++){
		for(int i=1;i<=n;i++){
			if(i-j>=0){
				f[i][j]=f[i-j][j]+a[i]*((i-1)/j+1);
				sum[i][j]=sum[i-j][j]+a[i];
			}else{
				f[i][j]=a[i];
				sum[i][j]=a[i];
			}
		}
	}

	while(q--){
		i64 s,d,k,res=0;
		cin>>s>>d>>k;
		if(k<=1000ll){
			for(int j=s+d*(k-1);k;j-=d,k--)
				res+=a[j]*k;
		}else if(d<=200){
			if(s-d>=0){
				res=f[s+d*(k-1)][d]-f[s-d][d];
				res-=(s-1)/d*(sum[s+d*(k-1)][d]-sum[s-d][d]);
			}else{
				res=f[s+d*(k-1)][d];
			}
		}
		cout<<res<<" \n"[!q];
	}
}

int main(){
    freopen("F.in","r",stdin);
    freopen("F2.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}