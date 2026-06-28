#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull mask=std::chrono::steady_clock::now().time_since_epoch().count();

ull shift(ull x){
    x^=mask;
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    x^=mask;
    return x;
}

const int maxn=1e6+5;
int n;
ull hsh[maxn];
vector<int> E[maxn];
set<ull> trees;

void get_hash(int u,int fa){
    hsh[u]=1;
    for(int& v:E[u]){
        if(v==fa) continue;
        get_hash(v,u);
        hsh[u]+=shift(hsh[v]);
    }
    trees.insert(hsh[u]);
}

int main(){
    freopen ("763.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(v);
        E[v].push_back(u);
    }
    get_hash(1,0);
    printf("%lu",trees.size());
    return 0;
}