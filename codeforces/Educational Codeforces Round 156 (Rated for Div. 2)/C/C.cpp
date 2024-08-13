#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
int T,Num;
char s[maxn];
char st[maxn];
int top,id[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
signed main(){
    // freopen("C.in","r",stdin);
    // freopen("C.out","w",stdout);
    T=read();
    while(T--){
        scanf("%s",s+1);
        int pos=read(),len=strlen(s+1);
        int Long=0;
        for(int i=1;i<=len;i++){
            Long+=len-i+1;
            if(pos<=Long) {Num=i;break;}//需要删掉num-1个
        }
        int lst=pos;
        for(int i=1;i<Num;i++)lst-=len-i+1;
        Num--;
        top=0;
        for(int i=1;i<=len;i++){
            while(Num&&top&&s[i]<st[top]){Num--;top--;}
            st[++top]=s[i];
        }
        while(Num){top--;Num--;}
        printf("%c",st[lst]);
    }
    return 0;
}