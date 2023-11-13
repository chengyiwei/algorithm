#include<bits/stdc++.h>
using namespace std;

const int maxn=1000005,maxb=1005;

int a[maxn],cnt[maxn],belong[maxn];
int N,sqN,num_b,M,ans[maxn];

struct query{
    int l,r,id;
} q[maxn];

int cmp(query a, query b) {
	return (belong[a.l] ^ belong[b.l]) ? belong[a.l] < belong[b.l] : ((belong[a.l] & 1) ? a.r < b.r : a.r > b.r);
}
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}

void printi(int x) {
	if(x / 10) printi(x / 10);
	putchar(x % 10 + '0');
}

int main(){
    freopen("SP3267.in","r",stdin);
    freopen("SP3267.out","w",stdout);
    N=read();
    sqN=sqrt(N);
    num_b=ceil((double)N/sqN);
    for(int i=1;i<=num_b;i++)
        for(int j=(i-1)*sqN+1;j<=i*sqN;++j)
            belong[j]=i;
    for(int i=1;i<=N;i++) a[i]=read();
    M=read();
    for(int i=1;i<=M;i++)
        q[i].l=read(),q[i].r=read(),q[i].id=i;
    sort(q+1,q+1+M,cmp);
    int l=1,r=0,now=0;
    for(int i=1;i<=M;i++){
        int ql=q[i].l,qr=q[i].r;
        while(l<ql) now -= !--cnt[a[l++]];
        while(l>ql) now += !cnt[a[--l]]++;
        while(r<qr) now += !cnt[a[++r]]++;
        while(r>qr) now -= !--cnt[a[r--]];
        ans[q[i].id]=now;
    }
    for(int i=1;i<=M;i++) printi(ans[i]),putchar('\n');
    return 0;
}