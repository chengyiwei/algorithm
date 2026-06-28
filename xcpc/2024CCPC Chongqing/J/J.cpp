#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll n, m, f[5] = {0, 6, 9, 10}, g[5] = {0, 6, 8, 9};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if(n == 1){
        cout << f[m % 4] + (m / 4) * 14 << "\n";
    }
    else if(m == 1){
        cout << g[m % 4] + (m / 4) * 14 << "\n";
    }
    else{
        cout << n * m * 6 << "\n";
    }
    return 0;
}