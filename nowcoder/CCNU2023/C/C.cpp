#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve(){
    int x,y;
    cin>>x>>y;
    if(x==(y-1)*9){
        putchar('1');
        for(int i=1;i<=y-1;i++) putchar('0');
        putchar('\n');
    }
    else{
        vector<int> a(y+1,0);
        a[y]=1;x--;
        int pos=0;
        while(x){
            a[++pos]+=min(9,x);
            x-=min(9,x);
        }
        LL now=0;
        for(int i=y;i;i--){
            now=now*10+a[i];
        }
        printf("%lld\n",now+1);
    }
}

int main(){
    freopen("C.in","r",stdin);
    int T;
    cin>>T;
    while(T--) solve();
}