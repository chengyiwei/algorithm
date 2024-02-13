#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int len_s, len_t;
typedef long long LL;
string s, t;
const LL mod1 = 1e9 + 7, mod2 = 1e9 + 9,base1 = 37, base2 = 41;

struct Hash{
    LL Mod, Base;
    vector<LL> h;

    Hash(LL Mod, LL Base): Mod(Mod), Base(Base){}

    LL qpow(LL a, LL b){
        LL res = 1;
        while(b){
            if(b & 1) res = res * a % Mod;
            a = a * a % Mod;
            b >>= 1;
        }
        return res;
    }

    void init(string &s){
        int n = s.size();
        h.resize(n + 1); h[0] = s[0] - 'a' + 1;
        for (int i = 1; i < n; i++)
            h[i] = (h[i - 1] * Base + s[i] - 'a' + 1) % Mod;
    }

    LL get(int l, int r){
        if(l == 0) return h[r];
        else return (h[r] - h[l - 1] * qpow(Base, r - l + 1) % Mod + Mod) % Mod;
    }
};

int main(){
    freopen("C.in","r",stdin);
    cin >> len_s >> len_t >> s >> t;

    if(s.size() > t.size())
        swap(s, t), swap(len_s, len_t);

    vector<int> ok_s(s.size(), 0), ok_t(t.size(), 0);
    
    Hash hs_f(mod1, base1), hs_b(mod1, base1);
    string rs = s; reverse(rs.begin(), rs.end());
    hs_f.init(s); hs_b.init(rs);

    for (int i = 0; i < s.size(); i++){
        if(hs_f.get(0, i) == hs_b.get(s.size() - 1 - i, s.size() - 1))
            ok_s[i] = 1;
    }

    Hash ht_f(mod1, base1), ht_b(mod1, base1);
    string rt = t; reverse(rt.begin(), rt.end());
    ht_f.init(t); ht_b.init(rt);
    
    for (int i = 0; i < t.size(); i++){
        if(ht_f.get(0, i) == ht_b.get(t.size() - 1 - i, t.size() - 1))
            ok_t[i] = 1;
    }

    // for (int i = 0; i < s.size(); i++)
    //     cout << ok_s[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < t.size(); i++)
    //     cout << ok_t[i] << ' ';
    // cout << '\n';

    int ans = -1;
    vector<int> pre(t.size(), -1);
    for (int i = 0; i < s.size(); i++){ 
        if(i > 0)
            pre[i] = pre[i - 1];
        if(ok_s[i]){
            if(hs_f.get(0, i) == ht_b.get(0, i))
                pre[i] = i;
        }
    }

    // for (int i = 0; i < s.size(); i++)
    //     cout << pre[i] << ' ';
    // cout << '\n';

    for (int i = 0; i < s.size() - 1; i++){
        if(ok_t[i]){
            if(ht_f.get(0, i) == hs_b.get(0, i) && pre[s.size() - 1 - i - 1] != -1){
                ans = max(ans, i + 1 + pre[s.size() - 1 - i - 1] + 1);
            }
        }
    }
    if(ans != -1) ans *= 2;
    cout << ans << '\n';
    return 0;
}