#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=5e5+7;
int N,C;
struct AS{
    int val,id;
    bool operator <(const AS B) const {return val-id*C>B.val-B.id*C;}
}a[maxn];
void solve(){
    cin>>N>>C;
    for(int i=1;i<=N;i++) cin>>a[i].val,a[i].id=i;
    sort(a+2,a+1+N);
    int now=a[1].val;
    for(int i=2;i<=N;i++){
        if(1ll * a[i].id * C > now + a[i].val)
            {printf("No\n");return ;}
        now+=a[i].val;
    }
    printf("Yes\n");
    return ;
}
signed main(){
    // freopen("D.in","r",stdin);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}