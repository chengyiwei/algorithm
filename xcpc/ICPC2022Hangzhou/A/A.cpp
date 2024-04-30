#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const ll MAXN = 2e5+5;
ll Tex = 1, n, s0, m, x;
inline ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
inline void print(ll x){
	stack<int> p;
	do{
		p.push(x%10);
		x/=10;
	}while(x);
	while(!p.empty()) {putchar(p.top()+'0');p.pop();}
}
void exgcd(ll a, ll b, ll &x, ll &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return;
	}
	exgcd(b, a % b, x, y);
	ll tmp = x;
	x = y;
	y = tmp - (a / b) * y;
}
void AC()
{
	n=read();m=read();
	for(ll i = 1; i <= n; i ++)
	{
		x=read();
		s0 += x;
	}
	ll A = n * (n + 1) / 2;
	ll B = n;
	ll gcd_AB = __gcd(A, B);
	ll gcd_ABm = __gcd(gcd_AB, m);
	ll mn = s0 - (s0 / gcd_ABm) * gcd_ABm;
    print(mn);putchar('\n');
	// cout << mn << endl;
	ll x, y, k1, k2;
	exgcd(gcd_AB, m, k1, k2);
	k2 = (mn - s0) * k2 / gcd_ABm;
	k1 = (mn - s0) * k1 / gcd_ABm;
	exgcd(A, B, x, y);
	x = x * k1;
	y = y * k1;
	x = (x % m + m) % m;
	y = (y % m + m) % m;
	print(y),putchar(' ');print(x); putchar('\n');
//	cout << y << " " << x << endl;
}
int main()
{
//	ios::sync_with_stdio(false);
//	cin >> Tex;
	while(Tex --) AC();
	return 0;	
} 

