#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int T,N,ans;
int s_1[maxn],s_0[maxn];
bool check(int now){
    int R=0;
    for(int i=1;i<=N;i++){
        while(R+1<=N&&s_0[R+1]-s_0[i-1]<=now)
            R++;
        if(s_1[N]-(s_1[R]-s_1[i-1])<=now)
            return 1;
    }
    return 0;
}
void solve(){
    memset(s_1,0,sizeof s_1);
    memset(s_0,0,sizeof s_0);
    string s;
    cin>>s;
    N=s.size();
    int L=0,R=N;s=" "+s;
    for(int i=1;i<=N;i++) {
        s_0[i]=s_0[i-1]+(s[i]=='0');
        s_1[i]=s_1[i-1]+(s[i]=='1');
    }
    while(L<=R){
        int mid=(R-L>>1)+L;
        if(check(mid)){ans=mid;R=mid-1;}
        else L=mid+1;
    }
    printf("%d\n",ans);
    return ;
}
int main(){
    // freopen("CF1680C.in","r",stdin);
    cin>>T;
    while(T--) solve();
    return 0;
}