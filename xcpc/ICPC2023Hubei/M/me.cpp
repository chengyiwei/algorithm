#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x, y;
ll a, b, c;
int main(){
    ios::sync_with_stdio(false);
    cin >> x >> y;
    for(int i = 0; i <= x; i ++){
        c = i;
        b = (y - c * 2500) / 1000;
        if(b >= 0 && b * 1000 + c * 2500 == y && b + c <= x){
            cout << x - (b + c) << " " << b << " " << c << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}