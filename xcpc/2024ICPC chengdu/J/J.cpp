#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex, n, m, q;
struct node{
    ll id, val;
};
bool operator < (node xx, node yy){
    if(xx.val == yy.val) return xx.id < yy.id;
    return xx.val > yy.val;
}
void AC(){
    cin >> n >> m >> q;
    vector<node> vec(m + 1);
    vector<ll> a(n + 1, m);
    for(int i = 1; i <= m; i ++){
        vec[i].id = i;
    }
    ll last = 0;
    map<ll, ll> mp1;
    map<pair<ll, ll>, ll> mp2;
    while(q --){
        ll opt, id, x;
        cin >> opt;
        if(opt == 1){
            cin >> x;
            mp1[last] = 0;
            mp1[x] = 1;
            last = x;
        }
        else if(opt == 2){
            cin >> id >> x;
            if(mp1[x] && !mp2[{id, x}]) vec[id].val += a[x], a[x] --, mp2[{id, x}] = 1;
        }
        else{
            cin >> id >> x;
            if(mp1[x]) mp2[{id, x}] = 1;
        }
    }
    sort(vec.begin() + 1, vec.end());
    for(int i = 1; i <= m; i ++){
        cout << vec[i].id << " " << vec[i].val << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}