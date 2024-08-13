#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
typedef long long LL;
const LL INF = 1e18;
int n, k;
LL a[maxn], s[maxn], ans = -INF;
int nxt[maxn];
struct node{
    LL w,v;
    node(LL w, LL v):w(w),v(v){}
};
int main(){
    freopen("E.in", "r", stdin);
    freopen("E.out","w",stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++){
        nxt[i] = i;
        for (int j = i; j <= n; j++){
            if(s[j] - s[i - 1] > s[nxt[i]] - s[i - 1])
                nxt[i] = j;
        }
        ans = max(ans, s[nxt[i]] - s[i - 1]);
    }

    for (int i = 1; i <= n; i++){
        if(a[i] < 0) continue;
        vector<node> h;
        for (int j = 1; j < i; j++){
            if (a[j] > 0){
                h.push_back(node(i - j - 1, a[j]));
            }
        }
        for (int j = nxt[i] + 1; j <= n; j++){
            if (a[j] > 0){
                h.push_back(node(j - i - 1, a[j]));
            }
        }
        //01背包
        LL now_ans = 0;
        vector<LL> dp(k + 1, 0);
        for (auto& x : h){
            for (int j = k; j >= x.w; j--){
                dp[j] = max(dp[j], dp[j - x.w] + x.v);
            }
        }
        for (int j = 0; j <= k; j++)
            now_ans = max(now_ans, dp[j]);
        ans = max(ans, s[nxt[i]] - s[i - 1] + now_ans);
    }
    printf("%lld\n", ans);
    return 0;
}