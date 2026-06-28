#include<bits/stdc++.h>
using namespace std;
int main(){
    long long ans=0;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        ans+=x;
    }
    ans-=m;
    if(ans<50)printf("QAQ\n");
    else printf("KFC\n");
}