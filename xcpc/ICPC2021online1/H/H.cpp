#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll n, m, cnt;
map<ll, ll> mp;
set<ll> st1[MAXN];
vector<ll> st2[MAXN];
int main(){
    freopen("in.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        ll id;
        string x, y, z;
        cin >> id >> x >> y >> z;
        mp[id] = ++ cnt;
    }
    for(int i = 1; i <= m; i ++){
        ll id, a, b, c;
        string name;
        cin >> id >> name;
        if(name == "203"){
            cin >> a >> b >> c;
            st1[mp[a]].insert(b);
            st1[mp[b]].insert(a);
            st1[mp[a]].insert(c);
            st1[mp[c]].insert(a);
            st1[mp[b]].insert(c);
            st1[mp[c]].insert(b);

            st2[mp[a]].push_back(id);
            st2[mp[b]].push_back(id);
            st2[mp[c]].push_back(id);
        }
        else{
            cin >> a >> b;
            st1[mp[a]].insert(b);
            st1[mp[b]].insert(a);

            st2[mp[a]].push_back(id);
            st2[mp[b]].push_back(id);
        }
    }
    ll q; cin >> q;
    while(q --){
        ll fd;
        cin >> fd;
        cout << fd << "\n";
        cout << "[";
        ll pwp = 0;
        for(auto it : st1[mp[fd]]){
            cout << it;
            pwp ++;
            if(pwp != st1[mp[fd]].size()) cout << ",";
        }
        cout << "]\n";
        cout << "[";
        for(auto it : st2[mp[fd]]){
            cout << it;
            if(it != st2[mp[fd]].back()) cout << ',';
        }
        cout << "]\n";
    }
    return 0;
}