#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int N,a[105],ans;
int main(){
    freopen("D.in","r",stdin);
    freopen("D0.out","w",stdout);
    int T=read();
    while(T--){
        ans=0;
        int N=read();
        for(int i=1;i<=N;i++)a[i]=read();
        sort(a+1,a+1+N);
        for(int i=1;i<N;i++)
        for(int j=i+1;j<=N;j++){
            int flg=1;
            for(int k=1;k<=N;k++){
                if(a[i]%a[k]==0&&a[j]%a[k]==0){
                    flg=0;
                    break;
                } 
            }
            if(flg){
                // printf("%d %d\n",a[i],a[j]);
            }
            ans+=flg;
        }
        printf("%d\n",ans);
    }
    return 0;
}