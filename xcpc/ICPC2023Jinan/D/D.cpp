#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Tex, l1, r1, l2, r2;
void AC(){
    cin >> l1 >> r1 >> l2 >> r2;
    ll cnt = 0, mx = 0;
    for(ll i = l1 + l2; i <= r1 + r2; i ++){
        cnt ++;
        ll dq = i;
        while(dq){
            mx = max(dq % 10, mx);
            dq /= 10;
        }
        if(cnt >= 20) break;
    }
    cout << mx << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}