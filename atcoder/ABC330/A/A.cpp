#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    int N=read(),L=read();
    int ans=0;
    for(int i=1;i<=N;i++){
        int x=read();
        ans+=(x>=L);
    }
    printf("%d\n",ans);
}