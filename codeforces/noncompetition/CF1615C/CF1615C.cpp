#include<bits/stdc++.h>
using namespace std;
int T,N;
int check_ou(string X,string Y){
    int x_0=0,y_0=0;
    for(int i=0;i<N;i++)
        x_0+=X[i]=='0',y_0+=Y[i]=='0';
    if(x_0!=y_0) return -1;
    int now=0;
    for(int i=0;i<N;i++)
        now+=X[i]!=Y[i];
    if(now&1) return -1;
    return now;
}

int check_ji(string X,string Y){
    int x_0=0,y_1=0;
    for(int i=0;i<N;i++)
        x_0+=X[i]=='0',y_1+=Y[i]=='1';
    if(x_0!=y_1-1) return -1;
    for(int i=0;i<N;i++) if(X[i]=='1'&&Y[i]=='1'){
        for(int j=0;j<N;j++)if(j!=i)
            X[j]=X[j]=='1'?'0':'1';
        int ret=check_ou(X,Y);
        if(ret!=-1)return ret+1;
        break;
    }
    X[1]=X[1]=='1'?'0':'1';
    int ret=check_ou(X,Y);
    if(ret!=-1) return ret+1;
    return -1;
    
}
int main(){
    string A,B;
    // freopen("CF1615C.in","r",stdin);
    cin>>T;
    while(T--){
        cin>>N;
        cin>>A>>B;
        int ans1=check_ou(A,B);
        int ans2=check_ji(A,B);
        if(ans1==-1) printf("%d\n",ans2);
        else if(ans2==-1) printf("%d\n",ans1);
        else printf("%d\n",min(ans1,ans2));
    }
    return 0;
}