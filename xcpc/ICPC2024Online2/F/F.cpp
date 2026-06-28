#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x = 1500, n, a;
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a;
        x += a;
        if(x >= 4000){
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}