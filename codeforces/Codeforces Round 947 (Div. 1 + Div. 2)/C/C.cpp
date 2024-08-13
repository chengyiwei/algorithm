#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
const ll INF = 1e9 + 7;
ll Tex, n, a[MAXN];
void AC(){
    cin >> n;
    ll mx = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(i >= 2){
            if(a[i] >= a[i - 1]){
                mx = max(mx, a[i - 1]);
            }
            else{
                mx = max(mx, a[i]);
            }
        }
    }
    if(n >= 3){
        vector<ll> b;
        b.push_back(a[1]);
        b.push_back(a[2]);
        b.push_back(a[3]);
        vector<ll> c = b;
        sort(c.begin(), c.end());
        mx = max(mx, c[1]);
        for(int i = 4; i <= n; i ++){
            b.erase(b.begin());
            b.push_back(a[i]);
            c = b;
            sort(c.begin(), c.end());
            mx = max(mx, c[1]);
        }
    }
    cout << mx << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}