#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 15;
LL ten[maxn],dp[maxn];
LL cnta[maxn],cntb[maxn];
int num[maxn];

void init(){
    ten[0]=1;
    for(int i=1;i<maxn;i++){
        dp[i] = i*ten[i-1];
        ten[i] = ten[i-1]*10;;
    }
}

void solve(LL x,LL *cnt){
    int len = 0;
    while(x){
        num[++len] = x%10;
        x/=10;
    }
    for(int i=len;i;i--){
        for(int j=0;j<=9;j++)
            cnt[j] += dp[i-1]*num[i];
        for(int j=0;j<num[i];j++)
            cnt[j] += ten[i-1];
        LL num2 = 0;
        for(int j=i-1;j;j--)
            num2 = num2*10+num[j];
        cnt[num[i]] += num2 + 1;
        cnt[0] -= ten[i-1];
    }
}

int main(){
    init();
    LL a,b; cin>>a>>b;
    solve(a-1,cnta),solve(b,cntb);
    for(int i=0;i<=9;i++)
        cout<<cntb[i]-cnta[i]<<" ";
    return 0;
}