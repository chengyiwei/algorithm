#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 5e4 + 5;
ll n, k;
ll dx[2] = {0, 1};
ll dy[2] = {1, 0};
int main(){
    ios::sync_with_stdio(false);
    map<pair<int, int>, int> mp;
    cin >> n >> k;
    ll x = 1, y = 1, cnt = 0;
    for(int i = 1; i <= 2 * n - 1; i ++){
        mp[{x, y}] = 1;
        cnt ++;
        cout << x << " " << y << '\n';
        x += dx[cnt & 1];
        y += dy[cnt & 1];
    }
    mp[{1, n}] = 1;
    cout << 1 << " " << n << "\n";
    cnt ++;
    if(cnt == k) return 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(!mp[{i, j}]) cout << i << " " << j << "\n", cnt ++;
            mp[{i, j}] = 1;
            if(cnt == k) return 0;
        }
    }
    return 0;
}