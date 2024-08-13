#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;
typedef double db;
typedef long long ll;
ll Tex;
db R, n;
void AC()
{
	cin >> R >> n;
	db theta = (n - 2) * 180 / (n * 2);
	cout << theta << endl;
	theta = theta / 180.0 * PI;
	db r = R / (1 / cos(theta) + 1);
	if(n == 2) r = R / 2.0;
	else if(n == 1) r = R;
	printf("%.15lf\n", r);
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> Tex;
	while(Tex --) AC();
	return 0;
}
