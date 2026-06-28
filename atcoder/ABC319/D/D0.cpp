#include <bits/stdc++.h>
using namespace std;

int N,M;
int a[200001];
long long l,r=200000000400000,Ans;

int main() {
    freopen("D.in", "r", stdin);
    freopen("D0.out", "w", stdout);
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i) {
        scanf("%d",&a[i]);
        l=max(l,(long long)a[i]);
    }
    --l;
    while(l+1<r) {
        long long mid=(l+r)>>1;
        int cnt=1;
        long long tmp=-1;
        for(int i=1;i<=N;++i) {
            if(tmp+1+a[i]>mid) {
                ++cnt;
                tmp=a[i];
            }
            else
                tmp+=1+a[i];
        }
        if(cnt>M)
            l=mid;
        else {
            r=mid;
            Ans=mid;
        }
    }
    printf("%lld\n",Ans);
    return 0;
}