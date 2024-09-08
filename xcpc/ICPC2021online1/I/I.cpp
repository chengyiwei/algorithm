#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll a[MAXN], cnt;
map<ll, ll> mp;
int main(){
    while(cin >> a[cnt]){
        mp[a[cnt]] ++;
        cnt ++;
    }
    mp[a[cnt - 2]] --;
    mp[a[cnt - 1]] --;
    vector<ll> ans;
    for(auto it : mp){
        if(it.second){
            if(a[cnt - 2] - a[cnt - 1] <= it.first && it.first <= a[cnt - 2] + a[cnt - 1]){
                ans.push_back(it.first);
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<ll>());
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}