#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll k, p[10005], cnt, mp[10005];
ll Tex, x;
int main(){
    ios::sync_with_stdio(false);
    cin >> Tex;
    while(Tex --){
        cin >> x;
        ll LCM = 1;
        for(ll i = 2; i <= (ll)(1000000); i ++){
            LCM = LCM / __gcd(LCM, i) * i;
            if(x % LCM){
                cout << i << endl;
                break;
            }
        }
    }
    // cin >> k;
    // for(int i = 1; i <= 1000; i ++){
    //     ll dq = i, zh = 1;
    //     while(dq){
    //         zh *= (dq % k);
    //         dq /= k;
    //     }
    //     if(zh == 0) continue;
    //     if(i % zh == 0){
    //         mp[i] = 1;
    //         p[++ cnt] = i;
    //         // cout << i << endl;
    //     }
    // }
    // for(int i = 1; i <= 1000; i ++){
    //     if(mp[i] && (i % 12 == 0)) cout << i << endl;
    //     else if(mp[i] == 0){
    //         for(int j = 1; j <= cnt; j ++){
    //             mp[i + p[j]] = 1;
    //         }
    //     }
    // }
    return 0;
}