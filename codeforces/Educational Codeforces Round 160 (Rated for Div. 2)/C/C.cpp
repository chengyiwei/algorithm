#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}
int a[35];
int main(){
    freopen("C.in","r",stdin);
    int m=read();
    while(m--){
        int op=read(),v=read();
        if(op==1){a[v]++;}
        else{
            for(int i=30;i>=0;i--){
                int xu=v/(1<<i);
                xu=min(xu,a[i]);
                v-=xu*(1<<i);
            }
            if(v) printf("NO\n");
            else printf("YES\n");
        }
    }
    return 0;
}