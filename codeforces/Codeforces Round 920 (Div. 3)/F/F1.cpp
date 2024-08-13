#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

void print(LL x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

LL sum[100005][305],tsum[100005][305];

void solve(){
    int n=read(),Q=read();
    int tot=0;
    vector<LL> a(n+1); 
    int block = min((int)sqrt(n),300);
    for(int i=1;i<=n;i++) a[i]=read();

    for(int d=1;d<=block;d++){
        for(int i=1;i<=d;i++){
            for(int j=i,cnt=1;j<=n;j+=d,cnt++){
                tot++;
                if(j-d > 0) tsum[j][d] = tsum[j-d][d] + a[j]*cnt, sum[j][d] = sum[j-d][d] + a[j];
                else tsum[j][d] = a[j]*cnt, sum[j][d] = a[j];
            }
        }
    }
    
    while(Q--){
        int s=read(),d=read(),k=read(); LL ans=0;
        if(d > block){
            for(int i=s,cnt=1;cnt<=k;i+=d,cnt++)
                ans += a[i]*cnt;
        }
        else{
            int st = s, ed = s+d*(k-1);
            int num = (st- 1) / d;
            ans = (tsum[ed][d] - tsum[max(st-d,0)][d]) - (sum[ed][d] - sum[max(st-d,0)][d]) * num;
        }
        print(ans);putchar(' ');
    }
    putchar('\n');
}

int main(){
    freopen("F.in","r",stdin);
    freopen("F1.out","w",stdout);
    int T=read();
    while(T--) solve();
    return 0;
}