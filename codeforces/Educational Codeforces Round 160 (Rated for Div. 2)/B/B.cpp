#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
void solve(){
    string s;cin>>s;
    int n=s.size();s=" "+s;
    vector<int> pre_0(n+1,0),pre_1(n+1,0);
    int num_0=0,num_1=0;
    for(int i=1;i<=n;i++)
        if(s[i]=='0') num_0++;
        else num_1++;
    if(num_0>num_1) {
        for(int i=1;i<=n;i++) 
        if(s[i]=='0') s[i]='1';
        else s[i]='0';
        swap(num_0,num_1);
    }

    for(int i=1;i<=n;i++){
        pre_0[i]=pre_0[i-1];pre_1[i]=pre_1[i-1];
        if(s[i]=='0') pre_0[i]++;
        else pre_1[i]++;
    }
    for(int d=0;d<=n;d++){
        if(pre_1[n-d]<=pre_0[n]){
            printf("%d\n",d);
            return ;
        }
    }
    return ;
}
int main(){
    // freopen("B.in","r",stdin);
    int T=read();
    while(T--) solve();
    return 0;
}