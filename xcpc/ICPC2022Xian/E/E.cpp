#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Three{
    int t[51];
    Three(){memset(t,0,sizeof t);}
    Three(LL x) {
        memset(t,0,sizeof t);
        int L=0;
        while(x){
            t[++L]=x%3;
            x/=3;
        }
    }
    LL get_int(){
        LL ret=0;
        for(int i=50;i;i--) ret=ret*3+t[i];
        return ret;
    }
    int get_len(){
        for(int i=50;i;i--) if(t[i]) return i;
        return 0;
    }
    LL get_ans(){
        LL ret=0,L=0;
        for(int i=50;i;i--)if(t[i]){L=i;break;}
        for(int i=L;i;i--) ret+=t[i];
        return ret+L;
    }
};
inline void solve(){
    LL l,r,ans;cin>>l>>r;
    Three L(l),R(r);
    ans=max(L.get_ans(),R.get_ans());
    int R_len=R.get_len();
    Three Z;
    for(int i=R_len;i;i--) Z.t[i]=2;
    for(int i=R_len;i;i--){
        
        if(R.t[i]!=0){
            Z.t[i]=R.t[i]-1;
            if(Z.get_int()>=l){
                LL now=Z.get_ans();
                ans=max(ans,now);
            }
        }
        
        Z.t[i]=R.t[i];
    }
    cout<< ans << endl;
    return ;
}
int main(){
    // freopen("E.in","r",stdin);
    int T;cin>>T;
    while(T--) solve();
}