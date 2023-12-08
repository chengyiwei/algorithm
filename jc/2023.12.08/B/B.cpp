#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int maxn=1e5+5;

struct AS{
    LL a,b;
    bool operator <(const AS B)const{return b<B.b;}
}E[maxn];
int main(){
    freopen("B.in","r",stdin);
    LL n,r,avg,ans=0;
    scanf("%lld%lld%lld",&n,&r,&avg); 
    LL sum=avg*n,now_sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d %d\n",&E[i].a,&E[i].b);
        now_sum+=E[i].a;
    }
    sort(E+1,E+1+n);
    for(int i=1;i<=n;i++){
        if(now_sum>=sum)break;
        if(r-E[i].a>=sum-now_sum){
            ans+=(sum-now_sum)*E[i].b;
            now_sum=sum;
        }
        else{
            ans+=(r-E[i].a)*E[i].b;
            now_sum+=(r-E[i].a);
        }
    }
    printf("%lld\n",ans);
    return 0;
}