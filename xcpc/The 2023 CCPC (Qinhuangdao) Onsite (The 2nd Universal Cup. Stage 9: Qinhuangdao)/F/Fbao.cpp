#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
bool zs(ll x){
    if(x <= 1) return 0;
    for(int i = 2; i <= sqrt(x); i ++){
        if(x % i == 0) return 0;
    }
    return 1;
}
int main(){
    set<ll> st;
    vector<ll> a;
    for(int i = 2; i <= (ll)2e5; i ++){
        if(zs(i)){
            if(a.size()) st.insert(i - a.back());
            a.push_back(i);
        }
    }
    ll cnt = 0;
    for(auto it : st){
        cout << it << " ";
        cnt ++;
        if(cnt == 5) cout << "\n", cnt = 0;
    }
    cout << "\n";
}