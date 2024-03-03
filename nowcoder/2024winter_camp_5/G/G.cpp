#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
typedef long long LL;
int n, m;

vector<int> pri;
void init(int N){
    vector<int> vis(N+1,0);
    for(int i=2;i<=N;i++){
        if(!vis[i])pri.push_back(i);
        for(int j=1;j<pri.size()&&i*pri[j]<=N;j++){
            vis[i*pri[j]]=1;
            if(i%pri[j]==0)break;
        }
    }
}

int main () {
    freopen ("G.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    vector<int> ans (n + 1, 0);
    pri.push_back(0);init(2*n);
    int now = n;
    while (now > 0) {
        int pos = upper_bound(pri.begin(), pri.end(), now) - pri.begin();
        int x = pri[pos] - now, cnt = now - x + 1;  //x差, cnt 能放的个数
        for (int i = x; i <= now ;i ++) {
                ans[i] = pri[pos] - i;
        }
        now -= cnt;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}