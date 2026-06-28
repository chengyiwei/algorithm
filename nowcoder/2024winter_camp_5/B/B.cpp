#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL TT = 1e9 + 7;
int main() {
    string s; cin >> s; 
    int n = s.size(); s = " " + s;
    LL ans = 0;
    vector<int> f(n + 1, 1);
    f[1] = 2;
    for(int i = 2; i <= n; i++){
        f[i] = (f[i - 1] + f[i - 2]) % TT;
    }

    vector<string> t = {"mygo", "m ygo", "my go", "myg o", "m y go", "m yg o", "my g o", "m y g o"};
    for(int i = 1; i <= n; i++){
        for(auto &j : t){
            auto x = s.substr(i, j.size());
            auto check = [&](auto s, auto t){
                for(int i = 0; i < s.size(); i++){
                    if(t[i] == ' ') continue;
                    if(s[i] != t[i]) return 0;
                }
                return 1;
            };
            if(check(x, j)) 
                ans = (ans + 1ll * f[i - 1] * f[n - (i + j.size() - 1)] % TT) % TT;  
        }
    }
    cout << ans << endl;
}