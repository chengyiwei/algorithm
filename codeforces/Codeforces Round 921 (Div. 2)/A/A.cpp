#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;cin>>T;
    while(T--){
        int n,k; cin>>n>>k;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++)
                putchar('a'+j-1);
        puts("");
    }
    return 0;
}