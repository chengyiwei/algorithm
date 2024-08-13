#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 15;
const LL TT = 1e9 + 7;
int n,y;
string s;
int p[10] = {0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};


void solve(){
    set<int> S;
    cin >> n >> s >> y; LL ans = 0;
    for(int _ = 0; _ <= 9; _++)
    for(int a = 0; a <= 9; a++)
    for(int b = 0; b <= 9; b++) if (a != b)
    for(int c = 0; c <= 9; c++) if (a != c && b != c)
    for(int d = 0; d <= 9; d++) if (a != d && b != d && c != d){
        LL x = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '_') x = x * 10 + _;
            if(s[i] == 'a') x = x * 10 + a;
            if(s[i] == 'b') x = x * 10 + b;
            if(s[i] == 'c') x = x * 10 + c;
            if(s[i] == 'd') x = x * 10 + d;
            if(s[i] >= '0' && s[i] <= '9') x = x * 10 + s[i] - '0';
        }
        if(x % 8 != 0) continue;
        if(x > y) continue;
        if(x < p[n-1]) continue;
        S.insert(x);
    }
    ans = S.size();
    cout << ans << endl;
}

int main(){
    freopen("K.in","r",stdin);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}