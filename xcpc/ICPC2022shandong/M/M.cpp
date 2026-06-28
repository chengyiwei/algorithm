#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll MAXN = 5e5+5;
ll Tex, n, k;
db S[MAXN];
struct Point{
	db x, y;
	void read(){
		cin >> x >> y;
	}
}A[MAXN];
db Cross(Point A, Point B){
	return A.x * B.y - A.y * B.x;
}
db calc_s(Point p[], int n){
	db area = 0;
	for(int i = 0; i < n; i ++){
		area += Cross(p[i], p[(i + 1) % n]);
	}
	return fabs(area / 2);
}
db calc_san_s(Point A1, Point A2, Point A3){
	db f =  (A1.x * A2.y + A2.x * A3.y + A3.x * A1.y - A1.y * A2.x - A2.y * A3.x - A3.y * A1.x) / 2;
	return fabs(f);
}
void AC(){
	cin >> n >> k;
	for(int i = 0; i < n; i ++){
		A[i].read();
	}
	S[0] = calc_s(A, k + 1);
	for(int i = 1; i < n; i ++){
		S[i] = fabs(S[i - 1] - calc_san_s(A[i - 1], A[i], A[(i - 1 + k) % n]) + calc_san_s(A[i], A[(i - 1 + k) % n], A[(i + k) % n]));
	}
	db mx = 0;
	ll idx = 0;
	for(int i = k + 1; i < n; i ++){
		db s = calc_san_s(A[0], A[k], A[i]);
		if(s > mx){
			mx = s;
			idx = i;
		}
	}
	db ans = 0;
	ans = max(ans, S[0] + mx);
	for(int i = 1; i < n; i ++){
		ll le = i + k, ri = i + n;
		db now = 0;
		while (le <= ri) {
			ll lmid = (le + le + ri) / 3, rmid = (le + ri + ri) / 3;
			db lval = calc_san_s(A[i], A[(i + k) % n], A[lmid % n]), rval = calc_san_s(A[i], A[(i + k) % n], A[rmid % n]);
			now = max(now, min(lval, rval));
			if (lval < rval) {
				le = lmid + 1;
			} else {
				ri = rmid - 1;
			}
		}
		// cout << "S[i]:" << S[i] << " now:" << now << endl;
		ans = max(ans, S[i] + now);
	}
	printf("%.15lf\n", ans);
}
/*
1
7 2
3 6
1 1
3 1
7 1
8 1
5 6
4 6
*/
int main(){
	freopen("M.in", "r", stdin);
	cin >> Tex;
	while(Tex --) AC();
	return 0;
}
