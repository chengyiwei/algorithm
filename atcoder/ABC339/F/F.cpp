#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
const int maxn = 1005;
const LL TT1 = 1e9 + 7, TT2 = 1e9 + 23;

map<pii,LL> mp;

pii read_pii(){
    pii x = make_pair(0,0); char ch = getchar();
    while(ch<'0' || ch>'9') ch = getchar();
    while(ch>='0' && ch<='9') { x.first = (x.first*10+ch-'0')%TT1; x.second = (x.second*10+ch-'0')%TT2; ch = getchar(); }
    return x;
}

int main(){
    freopen("F.in","r",stdin);
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++){
        pii p = read_pii();
        if(mp.find(p) == mp.end()) mp[p] = 1;
        else mp[p]++;
    }
    LL ans = 0;
    for(auto it1:mp){
        for(auto it2:mp){
            LL x1 = it1.first.first * it2.first.first, x2 = it1.first.second * it2.first.second;
            pii p = make_pair(x1%TT1,x2%TT2);
            auto it = mp.find(p);
            if(it != mp.end()) ans += it1.second * it2.second * it->second;
        }
    }
    printf("%lld\n",ans);
    return 0;
}