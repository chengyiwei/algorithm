#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Tex, n, k;
map<ll, ll> f;
void AC(){
    cin >> n >> k;
    if(n & 1) cout << "Alice" << "\n";
    else{
        ll dq = 1;
        while(n % 2 == 0) n /= 2, dq *= 2;
        if(dq <= k) cout << "Alice" << "\n";
        else cout << "Bob" << "\n";
    }
}
int main(){
    // freopen("in.in", "r", stdin);
    ll dq = 1;
    for(int i = 1; i <= 35; i ++){
        dq <<= 1;
        f[dq] = 1;
    }
    ios::sync_with_stdio(false);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}