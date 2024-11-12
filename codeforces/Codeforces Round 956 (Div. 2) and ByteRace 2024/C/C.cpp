#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 505 + 5;
ll Tex, n, tot, pd;
vector<ll> a, b, c;
vector<pair<ll, ll>> ans;
bool f(vector<ll> & a, vector<ll> & b, vector<ll> & c){
    ans.clear();
    ll sum = 0, cnt = 0, last = 0;
    for(int i = 0; i < a.size(); i ++){
        sum += a[i];
        if(sum >= pd){
            ans.push_back({last + 1, i + 1ll});
            last = i + 1;
            cnt ++;
            break;
        }
    }
    sum = 0;
    for(int i = last; i < b.size(); i ++){
        sum += b[i];
        if(sum >= pd){
            ans.push_back({last + 1, i + 1ll});
            last = i + 1;
            cnt ++;
            break;
        }
    }
    sum = 0;
    for(int i = last; i < c.size(); i ++){
        sum += c[i];
        if(sum >= pd){
            ans.push_back({last + 1, i + 1ll});
            last = i + 1;
            cnt ++;
            break;
        }
    }
    return cnt == 3;
}
void AC(){
    cin >> n;
    a.clear(); b.clear(); c.clear();
    tot = 0;
    for(int i = 1; i <= n; i ++){
        ll x; cin >> x;
        tot += x;
        a.push_back(x);
    }
    for(int i = 1; i <= n; i ++){
        ll x; cin >> x;
        b.push_back(x);
    }
    for(int i = 1; i <= n; i ++){
        ll x; cin >> x;
        c.push_back(x);
    }
    pd = (tot + 2) / 3;
    if(f(a, b, c)){
        cout << ans[0].first << " " << ans[0].second << " ";
        cout << ans[1].first << " " << ans[1].second << " ";
        cout << ans[2].first << " " << ans[2].second << "\n";
        return;
    }
    if(f(a, c, b)){
        cout << ans[0].first << " " << ans[0].second << " ";
        cout << ans[2].first << " " << ans[2].second << " ";
        cout << ans[1].first << " " << ans[1].second << "\n";
        return;
    }
    if(f(b, a, c)){
        cout << ans[1].first << " " << ans[1].second << " ";
        cout << ans[0].first << " " << ans[0].second << " ";
        cout << ans[2].first << " " << ans[2].second << "\n";
        return;
    }
    if(f(b, c, a)){
        cout << ans[2].first << " " << ans[2].second << " ";
        cout << ans[0].first << " " << ans[0].second << " ";
        cout << ans[1].first << " " << ans[1].second << "\n";
        return;
    }
    if(f(c, a, b)){
        cout << ans[1].first << " " << ans[1].second << " ";
        cout << ans[2].first << " " << ans[2].second << " ";
        cout << ans[0].first << " " << ans[0].second << "\n";
        return;
    }
    if(f(c, b, a)){
        cout << ans[2].first << " " << ans[2].second << " ";
        cout << ans[1].first << " " << ans[1].second << " ";
        cout << ans[0].first << " " << ans[0].second << "\n";
        return;
    }
    cout << "-1" << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}