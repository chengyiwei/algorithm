#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL TT = 1e9+7;

LL read(){
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

LL ksm(LL a, LL b = TT-2){
    LL res = 1;
    while(b){
        if(b&1) res = res*a%TT;
        a = a*a%TT;
        b >>= 1;
    }
    return res%TT;
}

void print(LL x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

void solve(){
    LL n, m, k; n = read(), m = read(), k = read();
    LL x = (n-1)*n/2; x %= TT;
    vector<LL> a(m+1);
    for(int i=1;i<=m;i++){
        read(); read(); a[i] = read() % TT;
    }
    LL p1 = ksm(x) ,sum = 0, p2 = (1 - p1 + TT) % TT;
    LL now = 0 ;
    for(int i=1;i<=k;i++){
        sum += p1 * now % TT; sum %= TT;
        now = p1 * (now + 1) % TT + p2 * now % TT ; now %= TT;
    }
    LL ans = 0;
    for(int i=1;i<=m;i++){
        ans += sum + a[i] * p1 % TT * k % TT; ans %= TT;
    }
    print(ans);puts("");
}

int main(){
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    LL T = read(); 
    while(T--) solve();
}