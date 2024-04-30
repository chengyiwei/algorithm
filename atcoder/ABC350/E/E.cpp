#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
ll N, A, X, Y; 

map<ll, ld> dp;
const ld p = 1 / 6.0;
ld f(ll T) {
    if (T == 0) return 0;
    if (dp.count(T)) return dp[T];
    ld ans1 = f(T / A) + X;
    ld ans2 = 1.2 * ( (f(T / 2) + f(T / 3) + f(T / 4) + f(T / 5) + f(T / 6)) * p + Y);
    return dp[T] = min(ans1, ans2);
}

int main() {
    cin >> N >> A >> X >> Y;
    printf ("%.10lf\n", f(N));
    return 0;
}