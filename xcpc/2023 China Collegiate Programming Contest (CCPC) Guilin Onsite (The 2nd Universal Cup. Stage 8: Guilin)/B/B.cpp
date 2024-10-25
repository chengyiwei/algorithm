#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 3e5 + 5;
ll Tex, n, m, a[MAXN], b[MAXN];
void AC(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for(int i = n - m + 1; i <= n; i ++){
        cin >> b[i];
    }
    sort(a + 1, a + n + 1); sort(b + (n - m) + 1, b + n + 1);
    ll sum = 0, mn = a[n - m + 1], bmn = b[n - m + 1];
    multiset<ll> st_mn;
    multiset<pair<ll, ll>> st_mx;
    for(int i = n - m + 1; i <= n; i ++){
        if(b[i] < a[i]){
            cout << -1 << "\n";
            return;
        }
        sum += b[i] - a[i];
        if(b[i] - a[i]) st_mx.insert({a[i], b[i]});
    }
    if(sum > n - m){
        cout << -1 << "\n";
        return;
    }
    for(int i = 1; i <= n - m; i ++){
        st_mn.insert(a[i]);
    }
    vector<ll> ans;
    while(st_mn.size()){
        if(sum == st_mn.size()){
            while(st_mx.size()){
                pair<ll, ll> it_mx = ((*st_mx.begin()));
                st_mx.erase((st_mx.begin()));
                ans.push_back(it_mx.first);
                it_mx.first ++;
                sum --;
                st_mn.erase((st_mn.begin()));
                if(it_mx.first != it_mx.second) st_mx.insert(it_mx);
            }
            st_mn.clear();
            break;
        }
        while(st_mn.size() && (*st_mn.begin()) >= mn){
            if(st_mx.size() == 0) break;
            pair<ll, ll> it_mx = ((*st_mx.begin()));
            st_mx.erase((st_mx.begin()));
            ans.push_back(it_mx.first);
            it_mx.first ++;
            sum --;
            st_mn.erase((st_mn.begin()));
            if(it_mx.first != it_mx.second) st_mx.insert(it_mx);
            if((*st_mx.begin()).first <= bmn) mn = (*st_mx.begin()).first;
        }
        ll it_mn = ((*st_mn.begin()));   
        st_mn.erase((st_mn.begin()));
        ans.push_back(it_mn);
        it_mn ++;
        st_mn.insert(it_mn);
        st_mn.erase((st_mn.begin()));
        // for(auto it : st_mn){
        //     cout << " " << it;
        // }
        // cout << "\n";
        // cout << "\n";
        
        if(st_mn.size() && (*st_mn.begin()) >= mn && st_mx.size() == 0){
            cout << -1 << "\n";
            return;
        }
    }
    cout << ans.size() << "\n";
    for(auto it : ans){
        cout << it << " ";
    }
    cout << "\n";
}
int main(){
    // freopen("in.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}