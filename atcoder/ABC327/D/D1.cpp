#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL N=3e5+5;
LL n,m,a[N],b[N],fa[N],to[N];
LL find(LL x)
{
	if(fa[x]==x)return x;
	LL t=find(fa[x]);
	to[x]+=to[fa[x]];
	return fa[x]=t;
}
int main()
{
    freopen("D.in","r",stdin);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&b[i]);
	}	
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		LL fx=find(a[i]),fy=find(b[i]);
		if(fx==fy)
		{
			if((to[a[i]]+to[b[i]])%2==0)
			{
				puts("No");
				return 0;
			}
		}
		else
		{
			fa[fx]=fy;
			to[fx]=1-(to[a[i]]+to[b[i]])%2;
		}
	}
	puts("Yes");
}