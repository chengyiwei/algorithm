
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

void print(LL x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

struct Node{
    LL tsum,sum;
    int to;
    Node(int tsum=0,int sum=0,int to=0):tsum(tsum),sum(sum),to(to){}
};

void solve(){
    int n=read(),Q=read();
    int Block=sqrt(n),t=n/Block+(n%Block!=0);
    vector<LL> a(n+1);
    vector<int> belong(n+1),st(t+1),ed(t+1);
    vector<vector<Node> > f(n+1,vector<Node>(Block+1));

    for(int i=1;i<=n;i++) a[i]=read(),belong[i]=(i-1)/Block+1;
    for(int i=1;i<=t;i++) st[i]=(i-1)*Block+1,ed[i]=i*Block;ed[t]=n;

    for(int i=1;i<=t;i++)
        for(int d=1;d<=min(Block,ed[i]-st[i]+1);d++){
            for(int j=st[i];j<st[i]+d;j++){
                Node now=Node();
                for(int k=j,cnt=1;k<=ed[i];k+=d,cnt++){
                    now.tsum += a[k]*cnt;
                    now.sum += a[k];
                    now.to = k+d;
                }
                f[j][d] = now;
            }
        }

    while(Q--){
        int s=read(),d=read(),k=read();
        if(d > Block){ // 步长很大
            LL ans=0;
            for(int i=s,cnt=1;cnt<=k;i+=d,cnt++)
                ans+=a[i]*cnt;
            print(ans);putchar(' ');
        }
        else{
            int S=s,D=s+d*(k-1);
            if(belong[S] == belong[D]){
                LL ans=0;
                for(int i=S,cnt=1;i<=D;i+=d,cnt++)
                    ans+=a[i]*cnt;
                print(ans);putchar(' ');
            }
            else{
                LL ans=0,cnt=1,i=S;
                for(;i<=ed[belong[S]];i+=d,cnt++)
                    ans += a[i]*cnt;
                for(;belong[i] < belong[D];i=f[i][d].to){
                    ans += f[i][d].tsum + f[i][d].sum*(cnt-1);
                    cnt += (f[i][d].to-i)/d;
                }
                for(;i<=D;i+=d,cnt++)
                    ans+=a[i]*cnt;
                print(ans);putchar(' ');
            }
        }
    }
    putchar('\n');
}

signed main(){
    freopen("F.in","r",stdin);
    freopen("F.out","w",stdout);
    int T=read();
    while(T--) solve();
}
