#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Tex, n, k;
ll fastPow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a;
        a = a * a;
        b >>= 1;
    }
    return ret;
}
void AC(){
    cin >> n >> k;
    vector<ll> vec;
    for(int c = 1; c <= 1000000; c ++){
        if(n % c == 0) vec.push_back(c);
    }
    if(k == 3){
        ll ans = 0;
        for(auto it : vec){
            ll a1 = 3;
            ll b1 = 3 * it;
            ll c1 = it * it - n / it;
            ll det = b1 * b1 - 4 * a1 * c1;
            if(det < 0){
                continue;
            }
            if(sqrtl(det) * sqrtl(det) == det){
                if(det == 0){
                    ans ++;
                    cout << "op" << '\n';
                }
                else{
                    ans += 2;
                }
            }
        }
        cout << ans << '\n';
        return;
    }
    ll tmp = sqrt(sqrt(n));
    ll ans = 0;
    for(auto it : vec){
        for(int i = -tmp; i <= tmp; i ++){
            if(fastPow(i + it, k) - fastPow(i, k) == n){
                ans ++;
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    freopen ("I.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}