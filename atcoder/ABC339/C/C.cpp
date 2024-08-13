#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5+5;
int main(){
    int N; scanf("%d",&N);
    LL now = 0, p = 0; 
    for(int i=1;i<=N;i++){
        LL x; scanf("%lld",&x);
        now += x;
        p = min(p,now);
    }
    printf("%lld\n",now + abs(p));
    return 0;
}