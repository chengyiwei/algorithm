#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

int a[105];
void solve(){
    int N=read(),ans=0;
    for(int i=1;i<=N;i++){
        char ch=getchar();
        while(ch!='.'&&ch!='#') ch=getchar();
        a[i]=(ch=='#');
    }
    a[0]=1;a[N+1]=1;
    for(int i=0;i<=N+1;i++){
        if(a[i]) continue;
        int j=i;
        while(j<=N+1&&a[j]==0) j++;
        if(j-i==1) ans+=1;
        else if(j-i==2)ans+=2;
        else {
            printf("%d\n",2);
            return ;
        }
        i=j;
    }
    printf("%d\n",ans);
    return ;
}
int main(){
    // freopen("A.in","r",stdin);
    int T=read();
    while(T--) solve();
}