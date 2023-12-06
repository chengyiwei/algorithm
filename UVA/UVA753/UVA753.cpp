#include<bits/stdc++.h>
using namespace std;
int N,M,K;
const int maxn=405;
bool E[maxn][maxn];
int cnt;
void solve(){
    N=read();
    map<string,int> mp;
    vector<int> A(N+1);
    vector<int> B(N+1);
    for(int i=1;i<=N;i++){
        string now;cin>>now;
        if(mp.find(now))
    }
}
int main(){
    freopen("UVA753.in","r",stdin);
    int T=read();
    while(T--){
        solve();
        if(T) printf("\n\n");
    }
    return 0;
}