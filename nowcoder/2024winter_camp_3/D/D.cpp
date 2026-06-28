#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, k;
LL a[maxn], b[maxn], F[maxn];

int main(){
    freopen("D.in", "r", stdin);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(k == 0){
        for (int i = 1; i <= n; i++)
            b[i] = a[i];
        LL ans = -INF;
        memset(F, ~0x3f, sizeof(F));
        for (int i = 1; i <= n; i++){
            F[i] = max(F[i - 1], 0ll) + b[i];
            ans = max(ans, F[i]);
        }
        cout << ans << '\n';
    }
    else{
        LL ans = -INF;
        for (int p = 1; p < n; p ++){
            for (int i = 1; i <= n; i++)
                b[i] = a[i];
            swap(b[p], b[p + 1]);
            LL now_ans = -INF;
            memset(F, ~0x3f, sizeof(F));
            for (int i = 1; i <= n; i++){
                F[i] = max(F[i - 1], 0ll) + b[i];
                now_ans = max(now_ans, F[i]);
            }
            ans = max(ans, now_ans);
        }
        cout << ans << '\n';
    }
    return 0;
}