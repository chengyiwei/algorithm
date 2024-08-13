#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    // freopen("A.in","r",stdin);
    int T=read();
    while(T--){
        int x=read();
        if((x-1)%3==0||(x+1)%3==0) printf("First\n");
        else printf("Second\n");
    }
    return 0;
}