#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    freopen ("K.in","r",stdin);
    int n; LL k;
    LL ans = 0;
    cin >> n >> k;
    vector<LL> a(n + 1);
    map<LL,LL> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (mp.count(a[i]) == 0) mp[a[i]] = 1;
        else mp[a[i]] ++;
    }

    for (int i = 1; i <= n; i++) {
        LL x = a[i] / 2;
        auto fid = [&](LL p){
            if (mp.count(p)) {
                ans += mp[p];
                if (p == a[i])
                    ans --;
            }
        };
        if (k)
            fid (x - k), fid (x + k);
        else 
            fid (x);
    }
    cout << ans << '\n';
    return 0;
}