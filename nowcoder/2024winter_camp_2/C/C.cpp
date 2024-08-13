#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5 + 10;
const LL TT = 1e9 + 7;

LL qpow(LL a, LL b = TT - 2){
    LL res = 1;
    while(b){
        if(b & 1) res = res * a % TT;
        a = a * a % TT;
        b >>= 1;
    }
    return res;
}

struct Trie{
    int root, tot, nex[maxn * 30][2];
    LL val[maxn * 30];
    int newnode(){
        tot ++ ;
        memset(nex[tot], 0, sizeof(nex[tot]));
        val[tot] = 0;
        return tot;
    }
    void init(){
        memset(nex[0], 0, sizeof nex[0]);
        val[0] = 0;
        tot = 0;
        root = newnode();
    }
    void insert(LL x, LL v){
        int p = root;
        for(int i = 30; i>= 0; i--){
            int t = (x >> i) & 1;
            if(!nex[p][t]) nex[p][t] = newnode();
            p = nex[p][t];
            val[p] = (val[p] + v) % TT;
        }
    }
    LL query(LL x, LL k){
        int p = root;
        LL res = 0;
        for(int i = 30; i >= 0; i--){
            int t = (x >> i) & 1;
            if(((k >> i) & 1) == 1){ // k 的第 i 位为 1
                if(nex[p][t]) res = (res + val[nex[p][t]]) % TT;
                p = nex[p][t ^ 1];
            }
            else p = nex[p][t];
        }
        res = (res + val[p]) % TT;
        return res;
    }
}tr;

int a[maxn];

void solve(){
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    tr.init();
    LL ans = 1;
    for(int i = 2; i <= n; i++){
        tr.insert(a[i - 1], qpow(qpow(2, i - 1)));
        ans = (ans + 1 + tr.query(a[i], k) * qpow(2, i - 1)) % TT;
    }
    cout << ans << '\n';
}

int main(){
    freopen("C.in","r",stdin);
    
    int t; cin >> t;
    while(t--) solve();
    return 0;
}