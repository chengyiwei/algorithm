#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
void solve(){
    pii a; cin >> a.first >> a.second;
    if(a.first > a.second) swap(a.first, a.second);
    if(a.first % 2 == 0){
        pii p = {a.first / 2, a.second * 2};
        if (p != a){
            cout << "Yes" << '\n';
            return ;
        }
    }
    if(a.second % 2 == 0){
        pii p = {a.first * 2, a.second / 2};
        if (p.first > p.second) swap(p.first, p.second);
        if (p != a){
            cout << "Yes" << '\n';
            return ;
        }
    }
    cout << "No" << '\n';   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}