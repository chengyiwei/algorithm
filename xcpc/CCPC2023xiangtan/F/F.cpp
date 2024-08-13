#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int MAXN = 1e6 + 5;
db E[MAXN], p, q, fp, fq;
int a, b;
int main(){
	cin >> a >> b >> p >> q;
	fp = (100.0 - p) / 100.0;
	fq = (100.0 - q) / 100.0;
	p = p / 100.0;
	q = q / 100.0;
	for(int i = b; i <= a; i ++){
		db ep, eq;
		if(b == 1) ep = (q / fq) + E[i - b] + 1;
		else ep = q * (E[i - b + 1] + 1) + fq * (E[i - b] + 1);
		
		eq = p * (E[i - b] + 2) + fp * (E[i - b] + 1);
		
		E[i] = max(ep, eq);
	}
	printf("%.15lf\n", E[a]);
	return 0;
}
