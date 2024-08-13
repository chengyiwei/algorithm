#include<bits/stdc++.h>
using namespace std;
int N,X,W;
long long h[50],ans;
int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d%d",&W,&X);
        for(int j=9;j<18;j++){
            h[(X+j)%24]+=W;
        }
    }
    for(int i=0;i<24;i++)
        ans=max(ans,h[i]);
    printf("%lld\n",ans);
    return 0;
}