#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
const ll INF = 1e18;
ll n, k, a[MAXN], ans = INF;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++){
        if(a[i] < k){
            ans = i;
            break;
        }
    }
    if(a[n] >= a[n - 1] && ans == INF) cout << "Python will never be faster than C++\n";
    else{
        if(ans != INF) cout << "Python 3." << ans << " will be faster than C++" << "\n";
        else{
            ll d = a[n - 1] - a[n];
            ll t = ((a[n] - k)) / d + 1;
            ans = t + n;
            cout << "Python 3." << ans << " will be faster than C++" << "\n";
        }
    }
    return 0;
}