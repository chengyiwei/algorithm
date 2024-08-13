#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
	ll x=343720,y=233333;
	ll dx=15,dy=17;
	ll d=__gcd(y*dx,x*dy);
	ll k1=y*dx/d;
	ld t=2.l*k1*x/dx;
	
	ld sx=t*dx;
	ld sy=t*dy;
	
	ld s=sqrt(sx*sx+sy*sy);
	printf("%.10Lf\n",s);
	return 0;
}