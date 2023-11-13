#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5,INF=2e9+7;

int N,a[maxn],ans[maxn];

void solve(int l,int r,int ql,int qr){
    if(ql>qr) return ;
    if(l==r){ //如果值域为一个数 那么所对应的序列肯定就取这个值了
        for(int i=ql;i<=qr;i++) ans[i]=l;
        return ;
    }
    int cnt=0,mid=(l+r)>>1;
    int res=0,sum=0;
    for(int i=ql;i<=qr;i++) sum+=abs(a[i]-(mid+1));
    res=sum;
    // printf("%d %d %d %d\n",l,r,ql,qr);
    for(int i=ql;i<=qr;i++){
        sum-=abs(a[i]-(mid+1));sum+=abs(a[i]-mid);
        if(sum<res) cnt=i-ql+1,res=sum; //[1,i] 取mid更优 
    }
    solve(l,mid,ql,ql+cnt-1); //对子序列继续进行二分
    solve(mid+1,r,ql+cnt,qr); 
}

signed main(){
    freopen("P4597.in","r",stdin);
    freopen("P4597.out","w",stdout);
    cin>>N;
    for(int i=1;i<=N;i++) cin>>a[i];  
    solve(-INF,INF,1,N);
    for(int i=1;i<=N;i++) ans[0]+=abs(a[i]-ans[i]);
    cout<<ans[0]<<endl;
    return 0;
}