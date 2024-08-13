#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int g(int x){
    int ret=0;
    do{
        ret=ret+x%10;
        x/=10;
    }while(x);
    return ret;
}
int main(){
    // freopen("A.in","r",stdin);
    int T=read();
    while(T--){
        int x=read(),k=read();
        while(1){
            if(g(x)%k==0) {printf("%d\n",x);break;}
            x++;
        }
    }
}