#include<bits/stdc++.h>
using namespace std;

void solve(){
    string a, b; cin >> a >> b;
    a[0] = toupper(a[0]);
    b[0] = toupper(b[0]);
    if(a[0] == b[0]) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}