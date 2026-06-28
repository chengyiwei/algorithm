#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
int main(){
    srand(time(0));
    ios::sync_with_stdio(false);
    n = rand() % 100000 + 1;
    m = rand() % 100000 + 1;
    cout << n << " " << m << endl;
    for(int i = 1; i <= m; i ++){
        ll x = rand() % n + 1;
        ll y = rand() % n + 1;
        cout << x << " " << y << endl;
    }
    return 0;
}