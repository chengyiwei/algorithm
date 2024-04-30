#include<bits/stdc++.h>
using namespace std;
int F[]={1,0,0,0,1,0,1,0,2,1};
int G(int x,int k){
    if(k==0) return x;
    if(x==0||x==1) return ((k&1)^x);
    int cnt=0;
    do{
        cnt+=F[x%10];
        x/=10;
    }while(x);
    return G(cnt,k-1);
}
void solve(){
    int x,k;scanf("%d%d",&x,&k);
    printf("%d\n",G(x,k));
    return ;
}
int main(){
    freopen("B.in","r",stdin);
    int T;scanf("%d",&T);
    while(T--) solve();
    return 0;
}