#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL TT=998244353;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int brand(){return (rand()<<15)|rand();}
LL bbrand(){
    return ((LL)brand()<<30)|brand();
}
void solve(){
    int n=read();LL ans1=0,ans2=1;
    vector<int> a(n*2,0);
    vector<LL> x(n,0);
    vector<LL> F(n*2+1,0);
    for(int i=0;i<n;i++)
        x[i]=bbrand()^2333;
    for(int i=0;i<2*n;i++){
        a[i]=read()-1;F[i+1]=F[i]^x[a[i]];  //F[i] 表示前 i-1 个数的异或和
    }
    map<LL,int> lst;
    for(int i=0;i<2*n;i++)
        lst[F[i]]=i;
    for(int i=0;i<2*n;i++){
        if(F[i]==0){
            LL cnt=1;ans1++;
            int j=i+1;
            while(F[j]!=0){
                cnt++;
                j=lst[F[j]];
                j++;
            }
            ans2=ans2*cnt%TT;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
}
int main(){
    freopen("G2.in","r",stdin);
    srand(time(0));
    int T=read();
    while(T--) solve();
}