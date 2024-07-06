#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, mp[105][105];
ll dx[4] = {0, 0, -1, 1};
ll dy[4] = {1, -1, 0, 0};
int main(){
    double ans = 0;
    ll x, y;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> x >> y;
        if(mp[x][y]) continue;
        mp[x][y] = 1;
        ans += 2;
        for(int j = 0; j < 4; j ++){
            ll xx = x + dx[j];
            ll yy = y + dy[j];
            if(mp[xx][yy]) ans -= 0.5;
        }
    }
    printf("%.15lf\n", ans);
    return 0;
}