#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+5;
typedef long long ll;
ll A[maxn], B[maxn], L, R; 
int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld", &A[i], &B[i]);
	}
	R = A[1] / B[1];
	L = (A[1] + 1) / (B[1] + 1) + ((A[1] + 1) % (B[1] + 1) != 0);
	for (int i = 2; i <= n; i++) {
		R = min (R, A[i] / B[i]);
		L = max (L, (A[i] + 1) / (B[i] + 1) + ((A[i] + 1) % (B[i] + 1) != 0));
	}
	printf ("%lld %lld\n", L, R);
	return 0;
} 
