#include<bits/stdc++.h>
using namespace std;
int main(){
    using ll = long long;
    ll N; cin >> N;
    ll ans = N - N / 2 - N / 3 + N / 6;
    cout << ans << endl;
    return 0;
}