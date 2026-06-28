#include<bits/stdc++.h>
#define maxn 255
#define LL long long
using namespace std;
int n,m,t[maxn],w[maxn];
LL F[1005];
inline int read(){
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
bool check(int mid){
    memset(F,192,sizeof F);
    LL INF=F[0];F[0]=0;
    for (int i=1;i<=n;i++){
        LL p=(LL)t[i]-(LL)w[i]*mid;
        for (int j=m;j>=0;j--)
           if (F[j]!=INF) F[min(m,j+w[i])]=max(F[min(m,j+w[i])],F[j]+p);
    }
	return F[m]>=0;
}
int main(){
    freopen("talent.in","r",stdin);
    freopen("talent.out","w",stdout);
    n=read();m=read();
    for (int i=1;i<=n;i++) w[i]=read(),t[i]=read()*1000;
    int L=0,R=1000000;
    while(L<=R){
        int mid=(R-L>>1)+L;
        if (check(mid)) L=mid+1;else R=mid-1;
    }
	printf("%d\n",R);
    return 0;
}
