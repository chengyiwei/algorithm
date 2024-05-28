#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll n, T, c[MAXN], r[MAXN], qwq1, qwq2, x;
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> T;
    for(int i = 1; i <= T; i ++){
        cin >> x;
        int WW = ceil((x * 1.0) / n);
        int QQ = x % n == 0 ? n : x % n;
        c[WW] ++;
        r[QQ] ++;
        if(WW == QQ) qwq1 ++;
        if(WW + QQ == n + 1) qwq2 ++;
        if(c[WW] == n || r[QQ] == n || qwq1 == n || qwq2 == n){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}