#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1ll << 60;
int main(){
    int t; cin >> t;
    while (t--) {
    	int n; cin >> n;
    	ll sum = 0;
        double ans = 0;
        vector<ll> a(n + 1),s(n + 1,0);
        for (int i = 1; i <= n; i++)
            cin >> a[i], s[i] = s[i - 1] + a[i];
        ll minn = inf; int idx = -1;
        for (int i = 1; i <= n; i++) 
            if (a[i] < minn) minn = a[i], idx = i;
        for (int i = 1; i < idx; i++) 
            ans = max(ans, 1.0 * (s[n] - s[i - 1]) / (n - i + 1));
        for (int i = idx + 1; i <= n; i++) 
            ans = max(ans, 1.0 * (s[i] - s[0]) / i);
        printf("%.10f\n", ans);
    }
    return 0;
} 
