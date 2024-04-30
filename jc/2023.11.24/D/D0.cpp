#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
priority_queue< ll,vector<ll>,greater<ll> > a; 
priority_queue< ll,vector<ll>,greater<ll> > b; 
int main(){
	freopen("D.in","r",stdin);
	freopen("D0.out","w",stdout); 
	cin>>n>>m;
	ll x; 
	for(ll i=1;i<=n;i++)
		cin>>x,a.push(x);
	for(ll i=1;i<=m;i++)
		cin>>x,b.push(x);
	ll ans=0;
	while(a.size()>0){
		if(b.top()>=a.top()&&b.size()>0)
			ans+=b.top(),b.pop(),a.pop();
		else{
			if(b.size()==0&&a.size()>0){
				cout<<"you died!";	
				return 0;
			}
			b.pop(); 
		}
	}
	cout<<ans;
	return 0;
}  
