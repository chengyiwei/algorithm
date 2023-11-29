#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
typedef long long LL;
LL brand(){
    return (rand()<<16)+(rand()<<1)+(rand()<<1);
}
LL bbrand(){
    return (brand()<<31)+(rand());
}
LL a[(int)1e6+5];
bool solve(LL D){
    int tot=0;
    for(LL i=0;i*i<=D;i++)
        a[++tot]=i*i;
    LL pos=tot,ans=1e9;
    for(int i=1;i<=tot;i++){ //D-(x2+y2)
        while(pos>0&&a[pos]+a[i]>D) pos--;
        if(pos<tot) ans=min(ans,a[pos+1]+a[i]-D);
        if(pos>0) ans=min(ans,D-(a[pos]+a[i]));
    }
    // printf("%lld\n",ans);
    return ans<=15;
}
int main(){
    freopen("a.in","w",stdout);
    srand(GetTickCount());
    LL x=bbrand()%1000000000000;
    while(solve(x)) 
        x=bbrand()%1000000000000;
    cout<<x<<endl;
}