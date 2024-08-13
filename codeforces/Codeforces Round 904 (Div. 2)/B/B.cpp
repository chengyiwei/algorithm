#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;

int N,num_0,ans,x;
char s[maxn];
int lst;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int get_0(int pos){
    while(pos>0&&s[pos]=='1')
        pos--;
    return pos;
}

signed main(){
    // freopen("B.in","r",stdin);
    int T=read();
    while(T--){
        N=read();
        scanf("%s",s+1);
        ans=0;x=N;
        for(int i=N;i;i--){
            if(ans==-1);
            else if(s[i]=='0');
            else {
                x=get_0(min(x,i)-1);
                if(x==0)ans=-1;
                else {
                    ans+=(i-x);
                    swap(s[i],s[x]);
                }
            }
            printf("%lld ",ans);
        }
        printf("\n");
    }
    return 0;
}