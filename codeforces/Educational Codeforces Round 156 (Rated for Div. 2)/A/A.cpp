#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int T;
int main(){
    // freopen("A.in","r",stdin);
    // freopen("A.out","w",stdout);
    T=read();
    while(T--){
        int n=read(),x,y,z;
        if(n%3==0){
            if(n<12){printf("NO\n");continue;}
            x=1,y=4,z=n-x-y;
        }
        if(n%3==1){
            if(n<7){printf("NO\n");continue;}
            x=1,y=2,z=n-x-y;
        }
        if(n%3==2){
            if(n<8){printf("NO\n");continue;}
            x=1,y=2,z=n-x-y;
        }
        printf("Yes\n%d %d %d\n",x,y,z);
    }
    return 0;
}