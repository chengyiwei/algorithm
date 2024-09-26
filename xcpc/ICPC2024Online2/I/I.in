#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll n, ans;
struct node{
    ll w, v, c, t;
}a[MAXN];
bool operator < (node xx, node yy){
    return xx.w * yy.c < yy.w * xx.c;
    // if(xx.t == yy.t) return xx.w < yy.w;
    // return xx.t > yy.t;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    ll sum = 0;
    vector<node> b;
    for(int i = 1; i <= n; i ++){
        cin >> a[i].w >> a[i].v >> a[i].c;
        ans += a[i].v;
        sum += a[i].w;
    }
    for(int i = 1; i <= n; i ++){
        a[i].t = (sum - a[i].w) * a[i].c;
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    sum = 0;
    for(int i = b.size() - 1; i >= 0; i --){
        cout << b[i].w << " ";
        ans -= b[i].c * sum;
        sum += b[i].w;
    }
    cout << ans << '\n';
    return 0;
}