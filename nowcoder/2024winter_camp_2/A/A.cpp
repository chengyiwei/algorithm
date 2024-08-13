#include<bits/stdc++.h>
using namespace std;

set<int> S{34,36,38,40};

int n;

int main(){
    cin >> n;
    while(n--){
        int a,b,c, ans = 0;
        cin >> a >> b >> c;
        if(a == 150) ans += 1;
        if(a == 200) ans += 2;
        if(b == 45) ans += 2;
        else if(S.find(b) != S.end()) ans += 1;
        if(c == 45) ans += 2;
        else if(S.find(c) != S.end()) ans += 1;
        cout << ans << '\n';
    }
    return 0;
}