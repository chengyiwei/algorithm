#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Tex, n, k;
string s;
void AC(){
    cin >> n >> k >> s;
    s = " " + s;
    for(int i = n + 1; i <= n + min(k, n); i ++){
        s.push_back(s[i - n]);
    }
    ll l = 1, r = n, cnt = 0, ans = 0;
    for(int i = 1; i <= r; i ++){
        if(i + 6 > r) break;
        if(s.substr(i, 7) == "nanjing") cnt ++;
    }
    ans = cnt;
    while(r < s.size()){
        r ++;
        if(r - 6 > 0 && s.substr(r - 6, 7) == "nanjing") cnt ++;
        if(l + 6 < s.size() && s.substr(l, 7) == "nanjing") cnt --;
        l ++;
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}