#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn  = 1e5 + 5;
const int inf = 1e18 + 5;
string s[maxn];
int st(int k,int t){
    int ans = 0;    
    while(k){
         ans ++;
         k /= t;
    }
    return ans;
}
void solve(){
     
    int n,k;
    cin >> n >> k;
    int cnt = 0,t = 0,num = inf,p = 0;
    int mx = 0;
    priority_queue<int> q;
    for(int i = 1; i <= n ;i ++){
         int l;
         cin >> l;
         mx = max(l,mx);
         if(k != 1)
           p += st(l,k);
         q.push(l);
    }
    if(k == 1){
         cout <<  mx << endl;
         return;
    }
    while(!q.empty()){
        int k1 = q.top();q.pop();
        num = min(min(k1,p) + t,num);
        if(k1 / k > 0)
           q.push(k1/k);
        p--;
        t++;
    }
    cout << num << endl;
}
signed main() {
    freopen ("K.in", "r", stdin);
    freopen ("K0.out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}