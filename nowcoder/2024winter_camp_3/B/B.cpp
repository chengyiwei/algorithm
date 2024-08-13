#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(n & 1)
        cout << "qcjj" << '\n';
    else 
        cout << "zn" << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}