#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL p1=31,p2=37;
const LL TT1=1e9+7,TT2=998244353;

LL pow(LL a,LL b,LL Mod){
    LL ans=1;
    while(b){
        if(b&1) ans=ans*a%Mod;
        a=a*a%Mod;
        b>>=1;
    }
    return ans%Mod;
}



void solve(){
    string s;cin>>s;
    int n=s.size();s=" "+s;
    vector<LL> hsh1(n+1,0),hsh2(n+1,0);
    for(int i=1;i<=n;i++){
        hsh1[i]=(hsh1[i-1]*p1+s[i]-'a'+1)%TT1;
        hsh2[i]=(hsh2[i-1]*p2+s[i]-'a'+1)%TT2;
    }
    int ans=0;
    for(int i=1;i<n;i++){
        int l1,r1,l2,r2;
        for(l1=r1=i,l2=r2=i+1;l1>=1&&r1<=n;){
            if(               (((hsh1[r1]-hsh1[l1-1]*pow(p1,r1-l1+1,TT1)%TT1)+TT1)%TT1==((hsh1[r2]-hsh1[l2-1]*pow(p1,r2-l2+1,TT1))%TT1+TT1)%TT1)              )
            if(               (((hsh2[r1]-hsh2[l1-1]*pow(p2,r1-l1+1,TT2)%TT2)+TT2)%TT2==((hsh2[r2]-hsh2[l2-1]*pow(p2,r2-l2+1,TT2))%TT2+TT2)%TT2)              ){
                ans++;r1=l1-1;l2=r2+1;
            }
            l1--,r2++;
        }
    }
    printf("%d\n",ans);
}
int main(){
    freopen("L.in","r",stdin);
    int T;scanf("%d",&T);
    while(T--) solve();
}