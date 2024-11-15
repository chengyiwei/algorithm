#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll a, b, c;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b >> c;
    cout << 100 << "\n";
    for(int i = 1; i <= 100; i ++){
        if(i <= 50) cout << a << " ";
        else if(i <= 95) cout << b << " ";
        else if(i <= 99) cout << c << " ";
        else cout << c + 1 << "\n";
    }
    return 0;
}