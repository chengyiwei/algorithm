#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, a[1005][1005], cnt[1005], q_cnt;
ld w, p, px[1005], q;
int main(){
    freopen ("B.in", "r", stdin);
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    cin >> n >> m >> w;
    p = w / 100.0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> a[i][j];
            if(a[i][j]) cnt[i] ++;
        }
        if(i == 3 || i == 4 || i == n - 2 || i == n - 3) continue;
        q_cnt ++;
    }
    q = ((100.0 - w) / 100.0) / q_cnt;
    px[3] += p / 4.0; px[n - 2] += p / 4.0;
    px[4] += p / 4.0; px[n - 3] += p / 4.0;
    ld ans = 1.0;
    for(int i = 1; i <= n; i ++){
        if(cnt[i] == m) continue;
        if(i == 3 || i == 4 || i == n - 2 || i == n - 3){
            ld py = 1.0 / (cnt[i] + 1.0);
            ld pp = px[i] * py;
            // cout << px[i] << " " << py << " " << pp << "\n";
            ans = min(ans, pp);
        }
        else{
            px[i] = q;
            ld py = 1.0 / (cnt[i] + 1.0);
            ld pp = px[i] * py;
            // cout << px[i] << " " << py << " " << pp << "\n";
            ans = min(ans, pp);
        }
    }
    printf("%.2Lf\n", ans);
    return 0;
}