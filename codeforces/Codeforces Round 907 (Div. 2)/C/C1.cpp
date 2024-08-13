#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll t;
ll n;
ll a[200005],ans,x;
void solve()
{
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	x=0;
	ans=0;
	ll i=1,j=n;
	while(i<j)
	{
		x+=a[i];//加上值
		if(x>=a[j])
		{
			ans+=a[j]+1;//次数等于a[j]加上转换的 
			x=x-a[j];//多余的x
			a[j]=0;
			a[i]=x;
			x=0;
			i--;
			j--; 
		}
		i++;
	}
	if(a[i]==0);
	else if(a[i]==1)
		ans+=x+1;
	else if(x<=1&&a[i]==2)
		ans+=x+2;
	else
		ans+=x+1+(a[i]-x+1)/2;
	cout<<ans<<"\n";
}
int main()
{
    freopen("C.in","r",stdin);
	cin>>t;
	while(t--)
		solve();
	return 0;
}