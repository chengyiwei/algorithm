#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
const ll INF = 1e9 + 7;
ll Tex, n, a[MAXN];
void AC(){
    cin >> n;
    ll mn1 = INF, mn2 = INF;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        mn1 = min(mn1, a[i]);
    }
    for(int i = 1; i <= n; i ++){
        if(a[i] % mn1 == 0) continue;
        else mn2 = min(mn2, a[i]);
    }
    for(int i = 1; i <= n; i ++){
        if(a[i] % mn1 == 0 || a[i] % mn2 == 0) continue;
        else{
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}