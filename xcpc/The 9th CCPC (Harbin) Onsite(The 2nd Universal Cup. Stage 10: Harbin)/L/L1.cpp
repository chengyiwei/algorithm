#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll Tex, n, x;
vector<ll> a, b;
void f(vector<ll> & qwq, vector<ll> & p){
    for(auto &it : p){
        qwq.push_back(it);
    }
    p.clear();
}
void AC(){
    cin >> n;
    a.clear(); b.clear();
    a.push_back(0);
    b.push_back(0);
    for(int i = 1; i <= n; i ++){
        cin >> x;
        a.push_back(x);
    }
    for(int i = 1; i <= n; i ++){
        cin >> x;
        b.push_back(x);
    }
    vector<ll> q1, q2, q3, q4;
    for(int i = n; i >= 1; i --){
        if(b[i] == a[i]) continue;
        ll idx;
        for(int j = 1; j < i; j ++){
            if(a[j] == b[i]) idx = j;
        }
        // cout << " " << i << "\n";
        q1.clear(); q2.clear(); q3.clear(); q4.clear();
        q4.push_back(b[i]);
        if(idx - 1 > 0){
            for(int k = 1; k < idx; k ++){
                q1.push_back(a[k]);
            }
        }
        if(i - idx > 0){
            for(int k = idx + 1; k <= i; k ++){
                q2.push_back(a[k]);
            }
        }
        if(n - i > 0){
            for(int k = i + 1; k <= n; k ++){
                q3.push_back(a[k]);
            }
        }
        if(i == n){
            if(idx > 0) cout << string(idx, '1');
            a.clear(); a.push_back(0);
            if(q2.size()) f(a, q2);
            if(q1.size()) f(a, q1);
            if(q4.size()) f(a, q4);
        }
        else{
            if(idx - 1 > 0) cout << string(idx - 1, '1');
            if(i - idx > 0) cout << string(i - idx, '2');
            if(n - i + 1 > 0) cout << string(n - i + 1, '1');
            a.clear(); a.push_back(0);
            if(q1.size()) f(a, q1);
            if(q2.size()) f(a, q2);
            if(q4.size()) f(a, q4);
            if(q3.size()) f(a, q3);
        }
    }
    cout << endl;
}
int main(){
    freopen ("L.in", "r", stdin);
    freopen ("L.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0);cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}