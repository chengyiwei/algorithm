#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void AC(){
    ll n = (ll)(3);
    ll m = (ll)(5);
    cout << n << " " << m << endl;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            ll x = rand() % 2;
            cout << x;
        }
        cout << endl;
    }
}
int main(){
    srand(time(0));
    // freopen("in.in", "r", stdin);
    // freopen("in.in", "w", stdout);
    ios::sync_with_stdio(false);
    ll Tex = 2;
    cout << Tex << endl;
    while(Tex --) AC();
    return 0;
}