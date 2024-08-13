#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e4 + 5;
ll Tex, n, a[MAXN], p[MAXN];
void AC(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    ll l = 1, r = n, cnt = 0;
    queue<pair<ll, ll>> op;
    while(l < r){
        for(int i = l; i <= n; i ++){
            l = i;
            if(a[i] != p[i]){
                break;
            }
        }
        for(int i = r; i >= 1; i --){
            r = i;
            if(a[i] != p[i]){
                break;
            }
        }
        if(l >= r) break;
        for(int k = r; k >= l; k --){
            if(a[l] > a[k]){
                op.push({l, k});
                ll tmp = a[l];
                sort(a + l, a + k + 1);
                l = tmp + 1;
                break;
            }
        }
        
    }
    cout << op.size() << endl;
    while(!op.empty()){
        cout << op.front().first << " " << op.front().second << endl;
        op.pop();
    }
}
int main(){
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    for(int i = 1; i <= MAXN - 5; i ++){
        p[i] = i;
    }
    ios::sync_with_stdio(false);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}