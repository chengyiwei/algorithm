#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
int s[maxn],N,tmp[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int c[maxn];
void add_x(int x,int val){
    for(int i=x;i<maxn;i+=i&-i)
        c[i]+=val; 
}
vector<int> p;
int get(int x){
    int ret=0;
    if(x==0) return 0; 
    for(int i=x;i;i-=i&-i) 
        ret+=c[i];
    return ret;
}
signed main(){
    freopen("E.in","r",stdin);
    scanf("%d",&N);
    LL ans=0;
    for(int i=1;i<=N;i++) {
    	int now;
    	scanf("%d",&now); 
        s[i]=s[i-1]+now;
        if(s[i]>0) ans++;
    }
    for(int i=1;i<=N;i++)tmp[i]=s[i];
    sort(tmp+1,tmp+1+N);
    int len=unique(tmp+1,tmp+N+1)-(tmp+1);
    for(int i=1;i<=N;i++)
        s[i]=lower_bound(tmp+1,tmp+len+1,s[i])-tmp+1;
    for(int i=1;i<=N;i++){
        ans+=get(s[i]-1);
        add_x(s[i],1);
    }
    printf("%lld\n",ans);
    return 0;
}
