#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL TT=998244353;
const int maxn=105;
LL F[105][105];
LL pow(LL a,LL b){
    LL ans=1;
    while(b){
        if(b&1) ans=ans*a%TT;
        a=a*a%TT;b>>=1;
    }
    return ans;
}

int main(){
    freopen("G.in","r",stdin);
    int m,P;scanf("%d%d",&m,&P);
    F[0][0]=1;
    for(int i=0;i<=P;i++){
        for(int j=i;j<=P;j++){
            for(int k=1;k+j<=P;j++){
                F[i+1][j+k]=(F[i+1][j+k]+F[i][j])%TT;
            }
        }
    }
    LL ans=0;
    
}