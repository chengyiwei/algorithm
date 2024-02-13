#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x, n; scanf("%d%d", &x, &n);
    vector<int> p;
    int sq = sqrt(x);
    for(int i=1;i<=sq;i++){
        if(x%i == 0){
            p.push_back(i);
            if(i*i != x) 
                p.push_back(x/i);
        }
    }
    sort(p.begin(), p.end(), greater<int>());
    for(int i=0;i<p.size();i++){
        if(x / p[i] >= n){
            printf("%d\n", p[i]);
            return;
        }
    }
}

int main(){
    int T; scanf("%d", &T);
    while(T--) solve();
    return 0;
}