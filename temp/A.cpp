#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll a[N],sum=0;
map<int,int>b;

int main()
{
    freopen ("A.in", "r", stdin);
    freopen ("A.out", "w", stdout);
	ll n,c;
	cin >>n>>c;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
		a[i]-=c;
	}
	for(int i=0;i<n;i++)
		sum+=b[a[i]];
	cout<<sum;
	return 0;
}