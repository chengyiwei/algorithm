#include<bits/stdc++.h>
using namespace std;
const int maxn=2e1+5;
int N,D,W,maxT;
int ans;
struct node{
    int T,X;
}a[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

bool cmp(node A,node B){
    return A.X<B.X||(A.X==B.X&&A.T>B.T);
}

int main(){
    freopen("F.in","r",stdin);
    freopen("F0.out","w",stdout);
    N=read();D=read();W=read();
    for(int i=1;i<=N;i++) a[i].T=read(),a[i].X=read(),maxT=max(maxT,a[i].T);
    sort(a+1,a+1+N,cmp);
    for(int x=1;x<=a[N].X;x++)
    for(int t=1;t<=maxT;t++){
        int now=0;
        for(int i=1;i<=N;i++)
            if(x<=a[i].X&&a[i].X<x+W&&t<=a[i].T&&a[i].T<t+D)
                now++;
        ans=max(ans,now);
    }
    cout<<ans<<endl;
    return 0;
}