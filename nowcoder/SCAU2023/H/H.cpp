#include<bits/stdc++.h>
using namespace std;
int main(){
    int k,t;
    double p,ans=0;
    cin>>k>>t>>p;
    for(int i=1;i<=k;i++){
        double now=1;
        for(int j=1;j<=t;j++){
            ans+=now*p;
            now*=(1-p);
        }
    }
    printf("%.4lf\n",ans);
    return 0;
}