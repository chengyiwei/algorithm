#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k,S_max;
    cin>>n>>k>>S_max;
    if(k>=n){
        for(int i=1;i<=n;i++){
            cout<<"? 1 "<<i<<endl;
            char get;
            cin>>get;
            if(get=='-'){
                cout<<"! "<<i;
                return ;
            }
        }
    }
}
int main(){
    int T;
    cin>>T;
    while(T--) solve();
}