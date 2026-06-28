#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,m,t;
ll n0,res,f1,f2,f3,f4;

int main(){
	cin>>n0>>m;
	f1=1; f2=m; n=n0%M;
	for(i=1;i+1<n;i+=2){
		f4=((1ll*m*m+i+1)%M*f2+1ll*i*m%M*f1)%M;
		f3=(f1*i+f2*m)%M;
		f1=f3; f2=f4;
	}
	for(;i<n;i++){
		f2=(f1*i+f2*m)%M;
	}
	while(n0>n){f2=f2*m%M; n0-=M;}
	cout<<f2;
}