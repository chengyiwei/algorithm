#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1), z(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> z[i];
    if(n == 1) {
        if(a[1] == b[1] && z[1] == 1){
            cout << "No" << '\n';
            return ;
        }
        cout << "Yes" << '\n';
    }
    else{
        if(a[1] == b[2] && a[2] == b[1] && (z[1] & z[2]) == 1){
            cout << "No" << '\n';
            return ;
        }
        if(a[1] == b[1] && z[1] == 1){
            cout << "No" << '\n';
            return ;
        }
        if(a[2] == b[2] && z[2] == 1){
            cout << "No" << '\n';
            return ;
        }
        if(a[1] == a[2] && b[1] == b[2] && (z[1] ^ z[2]) == 1){
            cout << "No" << '\n';
            return ;
        }
        cout << "Yes" << '\n';
    }
}
int main(){
    freopen("G.in", "r", stdin);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}